#include <Arduino.h>
#include <SPI.h>
#include <ST73XX_UI.h>
#include <ST7306_4p2_BW_DisplayDriver.h>
#include <U8g2_for_ST73XX.h>

#include <lvgl.h>
#include <demos/lv_demos.h>

#include "ui/ui.h"
#include "ui/screens.h"

#define DC_PIN   7
#define RES_PIN  6
#define CS_PIN   10
#define SCLK_PIN 2
#define SDIN_PIN 3

ST7306_4p2_BW_DisplayDriver display(DC_PIN, RES_PIN, CS_PIN, SCLK_PIN, SDIN_PIN, SPI);
U8G2_FOR_ST73XX u8g2_for_st73xx;


TaskHandle_t Task_lvgl_Handle;   // lvgl 任务
TaskHandle_t Task_blink_Handle;   // lvgl 任务

#define LVGL_RUNNING_CORE 0
#define BLINK_RUNNING_CORE 0

hw_timer_t *tim1 = NULL;

/*Change to your screen resolution*/
static const uint32_t screenWidth = 300;
static const uint32_t screenHeight = 400;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight/2];

static lv_disp_drv_t disp_drv;

static void disp_init(void);
static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area,
                       lv_color_t *color_p);

// // 设置像素的回调函数
// void set_px_cb(lv_disp_drv_t * disp_drv, uint8_t * buf, lv_coord_t buf_w,
//                lv_coord_t x, lv_coord_t y, lv_color_t color, lv_opa_t opa)
// {
//     if (color.full== 0) {
//         // 如果颜色为非黑色，调用画点函数画一个白色点
//         display.writePoint(x, y, ST7306_COLOR_00);
//     } else {
//         // 如果颜色为黑色，不做任何操作，因为屏幕默认为黑色背景
//         display.writePoint(x, y, ST7306_COLOR_11);
//     }
//     // display.display();
//     // Serial.printf("1.x = %d, y = %d, full = 0x%x\n", x, y, color.full);
// }

/* Display flushing */ /*显示驱动*/
void disp_flush(lv_disp_drv_t *disp, const lv_area_t *area,
                lv_color_t *color_p){
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    // 遍历要刷新的区域
    for (lv_coord_t y = area->y1; y <= area->y2; y++) {
        for (lv_coord_t x = area->x1; x <= area->x2; x++) {
            lv_color_t pixelColor = color_p[(y - area->y1) * (area->x2 - area->x1 + 1) + (x - area->x1)];
            if (pixelColor.full== 0) {
                // 如果颜色为非黑色，调用画点函数画一个白色点
                display.drawPixel(x, y, (uint16_t)ST7306_COLOR_11);
            }else{
                display.drawPixel(x, y, (uint16_t)ST7306_COLOR_00);
            }
            // Serial.printf("2.x = %d, y = %d, full = 0x%x\n", x, y, pixelColor.full);
        }
    }

    display.display();

    // 标记刷新完成
    lv_disp_flush_ready(disp);
}

void lv_port_disp_init(void)
{
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 2);

    /*-----------------------------------
    * Register the display in LVGL
    *----------------------------------*/

    lv_disp_drv_init(&disp_drv);   /*Basic initialization*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = disp_flush;
    disp_drv.draw_buf = &draw_buf;
    // 设置像素设置回调函数
    // disp_drv.set_px_cb = set_px_cb;
    lv_disp_drv_register(&disp_drv);
}

// 定义任务函数 1
void lvgl_handler(void *pvParameters) {
    while (1) {
        lv_timer_handler(); /* let the GUI do its work */
        lv_tick_inc(5);
        // delay(5);
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

lv_obj_t *label;

void setup() {
    Serial.begin(115200);
    Serial.println("Hello Arduino! (V8.0.X)");

    display.initialize();
    // display.Low_Power_Mode();
    display.High_Power_Mode();
    display.display_on(true);
    display.display_Inversion(false);
    display.setRotation(0);

    u8g2_for_st73xx.begin(display);                 // connect u8g2 procedures to Adafruit GFX

    display.clearDisplay();
    display.display();

    lv_init();

    lv_port_disp_init();

#if 1
    Serial.println("ui_init start");
    ui_init();
    // lv_disp_t *dispp = lv_disp_get_default();
    // lv_theme_t *theme = lv_theme_mono_init(dispp, false, LV_FONT_DEFAULT);
    Serial.println("ui_init done");
#else
    /* Create simple label */
    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Initial Text");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    // uncomment one of these demos
    // lv_demo_widgets(); // OK
    // lv_demo_benchmark();          // OK
    // lv_demo_keypad_encoder();     // works, but I haven't an encoder
    // lv_demo_music();              // NOK 
    // lv_demo_printer();
    // lv_demo_stress();             // seems to be OK
#endif
    Serial.println("Setup done");

    // xTaskCreatePinnedToCore(lvgl_handler, "lvgl_handler", 4096, NULL, 1, &Task_lvgl_Handle, LVGL_RUNNING_CORE);
    xTaskCreate(lvgl_handler, "lvgl_handler", 4096, NULL, 1, NULL);
}

void loop() {
    delay(100);
    static int counter = 0;
    char buffer[200];
    sprintf(buffer, "Counter: %d", counter++);
    lv_label_set_text(objects.label_counter, buffer);

    uint32_t totalHeapSize = ESP.getHeapSize();
    uint32_t usedHeapSize = totalHeapSize - ESP.getFreeHeap();
    uint32_t freeHeapSize = ESP.getFreeHeap();
    sprintf(buffer, "Total RAM size:%.1fKB, Used RAM size:%.1fKB, Free RAM size:%.1fKB.", ((double)totalHeapSize)/1024, ((double)usedHeapSize)/1024, ((double)freeHeapSize)/1024);
    lv_label_set_text(objects.label_scroll, buffer);
}
