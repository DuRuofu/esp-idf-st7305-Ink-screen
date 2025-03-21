#include <Arduino.h>
#include <SPI.h>
#include <ST73XX_UI.h>
#include <ST7305_2p13_BW_DisplayDriver.h>
#include <U8g2_for_ST73XX.h>

#define DC_PIN   7
#define RES_PIN  6
#define CS_PIN   10
#define SCLK_PIN 2
#define SDIN_PIN 3

ST7305_2p13_BW_DisplayDriver display(DC_PIN, RES_PIN, CS_PIN, SCLK_PIN, SDIN_PIN, SPI);
U8G2_FOR_ST73XX u8g2_for_st73xx;

void setup() {
    Serial.begin(115200);
    Serial.println("Hello Arduino! (V8.0.X)");

    display.initialize();
    display.Low_Power_Mode();
    // display.High_Power_Mode();
    display.display_on(true);
    display.display_Inversion(false);

    u8g2_for_st73xx.begin(display);                 // connect u8g2 procedures to Adafruit GFX

    display.clearDisplay();
    display.display();
}

void loop() {
    long time = millis();

    char str[100];

    sprintf(str, "millis=%.3fs", ((float)time)/1000.00);

    display.clearDisplay();

    // 画一条的直线
    display.drawLine(0, 20, 30, 70, ST7305_COLOR_BLACK);

    // 画一个三角形
    display.drawTriangle(40, 5, 60, 35, 80, 5, ST7305_COLOR_BLACK);

    // 画一个实心三角形
    display.drawFilledTriangle(0, 5, 20, 35, 40, 5, ST7305_COLOR_BLACK);

    // 画一个矩形
    display.drawRectangle(70, 40, 120, 70, ST7305_COLOR_BLACK);

    // 画一个实心矩形
    display.drawFilledRectangle(70, 40, 100, 60, ST7305_COLOR_BLACK);

    // 画一个圆形
    display.drawCircle(90, 120, 25, ST7305_COLOR_BLACK);

    // 画一个实心圆形
    display.drawFilledCircle(90, 120, 15, ST7305_COLOR_BLACK);

    // 画一个多边形
    uint polygonPoints1[] = {0, 50, 60, 40, 60, 90, 20, 110, 0, 90};
    display.drawPolygon(polygonPoints1, 5, ST7305_COLOR_BLACK);

    // 画一个实心多边形
    uint polygonPoints2[] = {0, 120, 60, 110, 60, 160, 20, 180, 0, 160};
    display.drawFilledPolygon(polygonPoints2, 5, ST7305_COLOR_BLACK);

    u8g2_for_st73xx.setFontDirection(0);            // left to right (this is default)
    u8g2_for_st73xx.setForegroundColor(ST7305_COLOR_BLACK);      // apply Adafruit GFX color
    u8g2_for_st73xx.setBackgroundColor(ST7305_COLOR_WHITE);
    u8g2_for_st73xx.setFont(u8g2_font_helvR14_tf);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(0,210);                // start writing at this position
    u8g2_for_st73xx.print(str);
    
    u8g2_for_st73xx.setFont(u8g2_font_wqy16_t_gb2312b);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(0,230);                // start writing at this position
    u8g2_for_st73xx.print(F("慕容流年"));

    u8g2_for_st73xx.setFont(u8g2_font_fub42_tn);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(0,310);                // start writing at this position
    static uint8_t min = 0;
    u8g2_for_st73xx.printf("20:%02d", min>59 ? min=0: min++);

    u8g2_for_st73xx.setFontDirection(1);            // left to right (this is default)
    u8g2_for_st73xx.setForegroundColor(ST7305_COLOR_BLACK);      // apply Adafruit GFX color
    u8g2_for_st73xx.setBackgroundColor(ST7305_COLOR_WHITE);
    u8g2_for_st73xx.setFont(u8g2_font_wqy16_t_gb2312b);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(150,190);                // start writing at this position
    u8g2_for_st73xx.print(F("刘泽文liuzewen"));

    display.display();

    Serial.printf("display time = %dms\n", millis() - time);

    delay(120);
}
