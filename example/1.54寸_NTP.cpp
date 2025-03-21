#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <ST73XX_UI.h>
#include <ST7305_1p54_BW_DisplayDriver.h>
#include <U8g2_for_ST73XX.h>

#include <NTPClient.h>
#include <WiFi.h> // for WiFi shield
#include <WiFiUdp.h>

#define DC_PIN   7
#define RES_PIN  6
#define CS_PIN   10
#define SCLK_PIN 2
#define SDIN_PIN 3

ST7305_1p54_BW_DisplayDriver display(DC_PIN, RES_PIN, CS_PIN, SCLK_PIN, SDIN_PIN, SPI);
U8G2_FOR_ST73XX u8g2_for_st73xx;

const char *ssid     = "liuzewen";
const char *password = "liuzewen";

WiFiUDP ntpUDP;

// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionally you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600*8, 60000);

void setup() {
    Serial.begin(115200);
    Serial.println("Hello Arduino! (V8.0.X)");

    display.initialize();
    display.High_Power_Mode();
    // display.Low_Power_Mode();
    display.display_on(true);
    display.display_Inversion(false);  

    display.clearDisplay();
    display.display();

    u8g2_for_st73xx.begin(display);                 // connect u8g2 procedures to Adafruit GFX

    display.setRotation(3);


    display.clearDisplay();
    u8g2_for_st73xx.setFontDirection(0);            // left to right (this is default)
    u8g2_for_st73xx.setForegroundColor(ST7305_COLOR_BLACK);      // apply Adafruit GFX color
    u8g2_for_st73xx.setBackgroundColor(ST7305_COLOR_WHITE);
    u8g2_for_st73xx.setFont(u8g2_font_wqy16_t_gb2312b);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(0,20);                // start writing at this position
    u8g2_for_st73xx.printf("SSID: %s\n", ssid);
    u8g2_for_st73xx.print(F("Connecting to WiFi "));
    display.display();

    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    int retryCount = 0;
    while (WiFi.status()!= WL_CONNECTED) {
        delay (500);
        Serial.print (".");
        u8g2_for_st73xx.print(F("."));
        display.display();
        retryCount++;
        if (retryCount > 20) { // If it still can't connect after 20 retries, reset the ESP32
            Serial.println("Failed to connect to WiFi, resetting...");
            u8g2_for_st73xx.print("\nConnect fail, resetting...\n");
            display.display();
            delay(1000);
            ESP.restart();
        }
    }
    u8g2_for_st73xx.print("\n");
    u8g2_for_st73xx.print("Sucess!\n");
    u8g2_for_st73xx.printf("IP:%s", WiFi.localIP().toString().c_str());
    display.display();
    Serial.println ( "Sucess!" );
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());

    timeClient.begin();
    delay(1000);
}

void loop() {
    long time = millis();

    timeClient.update();

    char str[100];
    static int fps = 0;

    sprintf(str, "millis=%.3fs", ((float)time)/1000.00);

    display.clearDisplay();

    u8g2_for_st73xx.setFontDirection(0);            // left to right (this is default)
    u8g2_for_st73xx.setForegroundColor(ST7305_COLOR_BLACK);      // apply Adafruit GFX color
    u8g2_for_st73xx.setBackgroundColor(ST7305_COLOR_WHITE);
    u8g2_for_st73xx.setFont(u8g2_font_helvR14_tf);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(10,20);                // start writing at this position
    u8g2_for_st73xx.print(str);
    
    u8g2_for_st73xx.setFont(u8g2_font_wqy16_t_gb2312b);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(10,40);                // start writing at this position
    u8g2_for_st73xx.print(F("鱼鹰光电"));

    u8g2_for_st73xx.setFont(u8g2_font_fub30_tn);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    // u8g2_for_st73xx.setFont(u8g2_font_7Segments_26x42_mn);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(10,100);                // start writing at this position
    u8g2_for_st73xx.printf("%s", timeClient.getFormattedTime().c_str());

    u8g2_for_st73xx.setFontDirection(0);            // left to right (this is default)
    u8g2_for_st73xx.setFont(u8g2_font_wqy16_t_gb2312b);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2_for_st73xx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
    u8g2_for_st73xx.setCursor(10,130);                // start writing at this position
    u8g2_for_st73xx.print(F("1.54' Mono LCD"));
    u8g2_for_st73xx.setCursor(10,150);                // start writing at this position
    u8g2_for_st73xx.printf("FPS=%dHz(spi write)", fps);
    u8g2_for_st73xx.setCursor(10,170);                // start writing at this position
    u8g2_for_st73xx.printf("FPS=51Hz(real)");

    display.display();

    fps = 1000.0/(millis() - time);
    // Serial.printf("display time = %dms\n", millis() - time);
    // Serial.printf("This time : %s\n", timeClient.getFormattedTime().c_str());

    delay(50);
}
