#include <Arduino.h>
#include <SPI.h>
#include <ST73XX_UI.h>
#include <ST7306_4p2_RBW_DisplayDriver.h>
#include <U8g2_for_ST73XX.h>

#define DC_PIN   7
#define RES_PIN  6
#define CS_PIN   10
#define SCLK_PIN 2
#define SDIN_PIN 3

ST7306_4p2_RBW_DisplayDriver display(DC_PIN, RES_PIN, CS_PIN, SCLK_PIN, SDIN_PIN, SPI);
U8G2_FOR_ST73XX u8g2_for_st73xx;

void setup() {
    Serial.begin(115200);
    Serial.println("Hello Arduino! (V8.0.X)");

    display.initialize();
    // display.Low_Power_Mode();
    display.High_Power_Mode();
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
    display.drawLine(10, 20, 40, 70, 0x01);
    display.drawLine(20, 20, 50, 70, 0x02);
    display.drawLine(30, 20, 60, 70, ST7306_COLOR_RED_BLACK);

    // 画一个实心三角形
    display.drawFilledTriangle(30, 5, 50, 35, 70, 5, ST7306_COLOR_RED);

    // 画一个实心三角形
    display.drawFilledTriangle(70, 5, 90, 35, 110, 5, ST7306_COLOR_BLACK);

    // 画一个实心三角形
    display.drawFilledTriangle(110, 5, 130, 35, 150, 5, ST7306_COLOR_RED_BLACK);

    // 画一个三角形
    display.drawTriangle(150, 5, 170, 35, 190, 5, ST7306_COLOR_RED_BLACK);

    // 画一个矩形
    display.drawRectangle(80, 40, 140, 70, ST7306_COLOR_RED_BLACK);

    // 画一个实心矩形
    display.drawFilledRectangle(80, 40, 130, 60, ST7306_COLOR_BLACK);

    // 画一个圆形
    display.drawCircle(125, 120, 30, ST7306_COLOR_RED_BLACK);

    // 画一个实心圆形
    display.drawFilledCircle(125, 120, 20, ST7306_COLOR_RED_BLACK);

    // 画一个多边形
    uint polygonPoints1[] = {10, 50, 70, 40, 70, 90, 30, 110, 10, 90};
    display.drawPolygon(polygonPoints1, 5, ST7306_COLOR_RED_BLACK);

    // 画一个实心多边形
    uint polygonPoints2[] = {10, 120, 70, 110, 70, 160, 30, 180, 10, 160};
    display.drawFilledPolygon(polygonPoints2, 5, ST7306_COLOR_RED_BLACK);

    u8g2_for_st73xx.setFontDirection(0);            // left to right (this is default)
    u8g2_for_st73xx.setForegroundColor(ST7306_COLOR_RED_BLACK);      // apply Adafruit GFX color
    u8g2_for_st73xx.setBackgroundColor(0);
    u8g2_for_st73xx.setFont(u8g2_font_helvR14_tf);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(0,210);                // start writing at this position
    u8g2_for_st73xx.print(str);

    u8g2_for_st73xx.setForegroundColor(ST7306_COLOR_BLACK);      // apply Adafruit GFX color
    u8g2_for_st73xx.setFont(u8g2_font_wqy16_t_gb2312b);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(0,230);                // start writing at this position
    u8g2_for_st73xx.print(F("慕容流年"));

    u8g2_for_st73xx.setForegroundColor(ST7306_COLOR_RED);      // apply Adafruit GFX color
    u8g2_for_st73xx.setFont(u8g2_font_fub42_tn);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(0,310);                // start writing at this position
    static uint8_t min = 0;
    u8g2_for_st73xx.printf("20:%02d", min>59 ? min=0: min++);

    u8g2_for_st73xx.setFontDirection(1);            // left to right (this is default)
    u8g2_for_st73xx.setForegroundColor(0x03);      // apply Adafruit GFX color
    u8g2_for_st73xx.setBackgroundColor(0);
    u8g2_for_st73xx.setFont(u8g2_font_wqy16_t_gb2312b);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(150,190);                // start writing at this position
    u8g2_for_st73xx.print(F("刘泽文liuzewen"));

    display.display();

    Serial.printf("display time = %dms\n", millis() - time);

    delay(45);
}
