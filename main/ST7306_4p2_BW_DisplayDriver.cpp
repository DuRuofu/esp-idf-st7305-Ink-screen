#include <ST73XX_UI.h>
#include <ST7306_4p2_BW_DisplayDriver.h>
#include <stdlib.h>

#define ABS_DIFF(x, y) (((x) > (y))? ((x) - (y)) : ((y) - (x)))

ST7306_4p2_BW_DisplayDriver::ST7306_4p2_BW_DisplayDriver(int dcPin, int resPin, int csPin, int sclkPin, int sdinPin, SPIClass& spi) : 
    DC_PIN(dcPin), RES_PIN(resPin), CS_PIN(csPin), SCLK_PIN(sclkPin), SDIN_PIN(sdinPin),
    LCD_WIDTH(300), LCD_HIGH(400),
    ST73XX_UI(300, 400),
    // 2个像素组成1个像素，所以一行为600像素，600/4=150 一行共150个byte的数据，上下两行共用一行的数据，所以总行数需要除2
    // 400/2=200 所以共200行，一行150个byte数据，共200*150=30000byte
    LCD_DATA_WIDTH(150), LCD_DATA_HIGH(200), DISPLAY_BUFFER_LENGTH(30000),
    spiRef(spi)
{
    display_buffer = new uint8_t[DISPLAY_BUFFER_LENGTH];
    // delete[] display_buffer;

    // 像素数据结构为：
    // P0P2 P4P6
    // P1P3 P5P7

    // 对应一个byte数据的：
    // BIT7 BIT5 BIT3 BIT1
    // BIT6 BIT4 BIT2 BIT0
}

ST7306_4p2_BW_DisplayDriver::~ST7306_4p2_BW_DisplayDriver() {
    delete[] display_buffer;
}

void ST7306_4p2_BW_DisplayDriver::initialize() {
    pinMode(DC_PIN, OUTPUT);
    pinMode(RES_PIN, OUTPUT);
    pinMode(CS_PIN, OUTPUT);

    digitalWrite(RES_PIN, HIGH);

    spiRef.setFrequency(40000000);
    spiRef.begin(SCLK_PIN, -1, SDIN_PIN, -1);

    Initial_ST7305();
    fill(0x00);
}

void ST7306_4p2_BW_DisplayDriver::fill(uint8_t data) {
    memset(display_buffer, data, DISPLAY_BUFFER_LENGTH);
    Serial.printf("fill data = 0x%x\n", data);
}

void ST7306_4p2_BW_DisplayDriver::clearDisplay() {
    memset(display_buffer, 0x00, DISPLAY_BUFFER_LENGTH);
}

void ST7306_4p2_BW_DisplayDriver::writePoint(uint x, uint y, uint16_t data) {
    if(x>=LCD_WIDTH || y>=LCD_HIGH){
        return;
    }
    else{
        // 找到是哪一行的数据
        uint real_x = x/2; // 0->0, 3->0, 4->1, 7->1
        uint real_y = y/2; // 0->0, 1->0, 2->1, 3->1
        uint write_byte_index = real_y*LCD_DATA_WIDTH+real_x;
        uint one_two = (y % 2 == 0)?0:1; // 0 1
        uint line_bit_1 = (x % 2)*4; // 0 4
        uint line_bit_0 = (x % 2)*4 + 2; // 2 6
        uint8_t write_bit_1 = 7-(line_bit_1+one_two);
        uint8_t write_bit_0 = 7-(line_bit_0+one_two);

        bool data_bit0 = (data & 0x0001) > 0? true : false;
        bool data_bit1 = (data & 0x0002) > 0? true : false;

        // Serial.printf("Input x: %u\n", x);
        // Serial.printf("Input y: %u\n", y);
        // Serial.printf("Input data: %u\n", data);
        // Serial.printf("real_x: %u\n", real_x);
        // Serial.printf("real_y: %u\n", real_y);
        // Serial.printf("write_byte_index: %u\n", write_byte_index);
        // Serial.printf("one_two: %u\n", one_two);
        // Serial.printf("line_bit_0: %u\n", line_bit_0);
        // Serial.printf("line_bit_1: %u\n", line_bit_1);
        // Serial.printf("write_bit_0: %u\n", write_bit_0);
        // Serial.printf("write_bit_1: %u\n", write_bit_1);
        // Serial.printf("data & 0x0001: 0x%x\n", data & 0x0001);
        // Serial.printf("data & 0x0002: 0x%x\n", data & 0x0002);
        // Serial.printf("Bit 0 of data is %s\n", data_bit0? "1" : "0");
        // Serial.printf("Bit 1 of data is %s\n", data_bit1? "1" : "0");

        if (data_bit1) {
            // 将指定位置的 bit 置为 1
            display_buffer[write_byte_index] |= (1 << write_bit_1);
        } else {
            // 将指定位置的 bit 置为 0
            display_buffer[write_byte_index] &= ~(1 << write_bit_1);
        }

        if (data_bit0) {
            // 将指定位置的 bit 置为 1
            display_buffer[write_byte_index] |= (1 << write_bit_0);
        } else {
            // 将指定位置的 bit 置为 0
            display_buffer[write_byte_index] &= ~(1 << write_bit_0);
        }
    }
}

void ST7306_4p2_BW_DisplayDriver::display() {
    address();
    digitalWrite(DC_PIN, HIGH);
    digitalWrite(CS_PIN, LOW);
    spiRef.writeBytes(display_buffer, DISPLAY_BUFFER_LENGTH);
    digitalWrite(CS_PIN, HIGH);
}

void ST7306_4p2_BW_DisplayDriver::Initial_ST7305() {
    digitalWrite(RES_PIN, HIGH);	
    delay(10);
    digitalWrite(RES_PIN, LOW);
    delay(10);	
    digitalWrite(RES_PIN, HIGH);	
    delay(10);

    // 7306
    Write_Register(0xD6); //NVM Load Control 
    Write_Parameter(0X17); 
    Write_Parameter(0X02);

    Write_Register(0xD1); //Booster Enable 
    Write_Parameter(0X01); 



    // Write_Register(0xC0); //Gate Voltage Setting 
    // Write_Parameter(0X12); //VGH 00:8V  04:10V  08:12V   0E:15V   12:17V
    // Write_Parameter(0X0A); //VGL 00:-5V   04:-7V   0A:-10V

    // Write_Register(0XC1);   //VSHP Setting
    // Write_Parameter(0X37);  //VSHP1=4.8V
    // Write_Parameter(0X37);  //VSHP2=4.8V
    // Write_Parameter(0X37);  //VSHP3=4.8V
    // Write_Parameter(0X37);  //VSHP4=4.8V

    // Write_Register(0XC2);   //VSLP Setting
    // Write_Parameter(0X19);  //VSLP1=0.5V
    // Write_Parameter(0X19);  //VSLP2=0.5V
    // Write_Parameter(0X19);  //VSLP3=0.5V
    // Write_Parameter(0X19);  //VSLP4=0.5V

    // Write_Register(0XC4);   //VSHN Setting
    // Write_Parameter(0X41);  //VSHN1=-3.8V
    // Write_Parameter(0X41);  //VSHN2=-3.8V
    // Write_Parameter(0X41);  //VSHN3=-3.8V
    // Write_Parameter(0X41);  //VSHN4=-3.8V

    // Write_Register(0XC5);   //VSLN Setting
    // Write_Parameter(0X19);  //VSLN1=0.5V
    // Write_Parameter(0X19);  //VSLN2=0.5V
    // Write_Parameter(0X19);  //VSLN3=0.5V
    // Write_Parameter(0X19);  //VSLN4=0.5V


    // Write_Register(0XD8);   //OSC Setting
    // Write_Parameter(0XA6);  
    // Write_Parameter(0XE9);
    // /*-- HPM=32hz ; LPM=> 0x15=8Hz 0x14=4Hz 0x13=2Hz 0x12=1Hz 0x11=0.5Hz 0x10=0.25Hz---*/
    // Write_Register(0xB2); //Frame Rate Control 
    // Write_Parameter(0X12); //HPM=32hz ; LPM=1hz 


    // Write_Register(0XD8);   //OSC Setting
    // Write_Parameter(0XA6);  
    // Write_Parameter(0XE9);
    // /*-- HPM=32hz ; LPM=> 0x15=8Hz 0x14=4Hz 0x13=2Hz 0x12=1Hz 0x11=0.5Hz 0x10=0.25Hz---*/
    // Write_Register(0xB2); //Frame Rate Control 
    // Write_Parameter(0X02); //HPM=16hz ; LPM=1hz 


    Write_Register(0xC0); //Gate Voltage Setting 
    Write_Parameter(0X12); //VGH 00:8V  04:10V  08:12V   0E:15V   12:17V
    Write_Parameter(0X0a); //VGL 00:-5V   04:-7V   0A:-10V

    // VLC=3.6V (12/-5)(delta Vp=0.6V)		
    Write_Register(0xC1); //VSHP Setting (4.8V)	
    Write_Parameter(115); //VSHP1 	
    Write_Parameter(0X3E); //VSHP2 	
    Write_Parameter(0X3C); //VSHP3 	
    Write_Parameter(0X3C); //VSHP4	

    Write_Register(0xC2); //VSLP Setting (0.98V)	
    Write_Parameter(0); //VSLP1 	
    Write_Parameter(0X21); //VSLP2 	
    Write_Parameter(0X23); //VSLP3 	
    Write_Parameter(0X23); //VSLP4 	

    Write_Register(0xC4); //VSHN Setting (-3.6V)	
    Write_Parameter(50); //VSHN1	
    Write_Parameter(0X5C); //VSHN2 	
    Write_Parameter(0X5A); //VSHN3 	
    Write_Parameter(0X5A); //VSHN4 	

    Write_Register(0xC5); //VSLN Setting (0.22V)	
    Write_Parameter(50); //VSLN1 	
    Write_Parameter(0X35); //VSLN2 	
    Write_Parameter(0X37); //VSLN3 	
    Write_Parameter(0X37); //VSLN4
    

    // Write_Register(0xD8); //OSC Setting                                                                                                                                                                              
    // Write_Parameter(0X80); //Enable OSC, HPM Frame Rate Max = 51hZ
    // Write_Parameter(0XE9); 
    // /*-- HPM=51hz ; LPM=> 0x15=8Hz 0x14=4Hz 0x13=2Hz 0x12=1Hz 0x11=0.5Hz 0x10=0.25Hz---*/
    // Write_Register(0xB2); //Frame Rate Control 
    // Write_Parameter(0X12); //HPM=51hz ; LPM=1hz 


    Write_Register(0XD8);   //OSC Setting
    Write_Parameter(0XA6);  
    Write_Parameter(0XE9);
    /*-- HPM=32hz ; LPM=> 0x15=8Hz 0x14=4Hz 0x13=2Hz 0x12=1Hz 0x11=0.5Hz 0x10=0.25Hz---*/
    Write_Register(0xB2); //Frame Rate Control 
    Write_Parameter(0X12); //HPM=32hz ; LPM=1hz 



    // Write_Register(0XD8);   //OSC Setting
    // Write_Parameter(0XA6);  
    // Write_Parameter(0XE9);
    // /*-- HPM=32hz ; LPM=> 0x15=8Hz 0x14=4Hz 0x13=2Hz 0x12=1Hz 0x11=0.5Hz 0x10=0.25Hz---*/
    // Write_Register(0xB2); //Frame Rate Control 
    // Write_Parameter(0X02); //HPM=16hz ; LPM=1hz 




    Write_Register(0xB3); //Update Period Gate EQ Control in HPM 
    Write_Parameter(0XE5); 
    Write_Parameter(0XF6); 
    Write_Parameter(0X17);
    Write_Parameter(0X77); 
    Write_Parameter(0X77); 
    Write_Parameter(0X77); 
    Write_Parameter(0X77); 
    Write_Parameter(0X77); 
    Write_Parameter(0X77); 
    Write_Parameter(0X71); 

    Write_Register(0xB4); //Update Period Gate EQ Control in LPM 
    Write_Parameter(0X05); //LPM EQ Control 
    Write_Parameter(0X46); 
    Write_Parameter(0X77); 
    Write_Parameter(0X77); 
    Write_Parameter(0X77); 
    Write_Parameter(0X77); 
    Write_Parameter(0X76); 
    Write_Parameter(0X45); 

    Write_Register(0x62); //Gate Timing Control
    Write_Parameter(0X32);
    Write_Parameter(0X03);
    Write_Parameter(0X1F);

    // Write_Register(0XC7);   //Ultra Low Power Mode  
    // Write_Parameter(0XC1);  
    // Write_Parameter(0X41);
    // Write_Parameter(0X26);

    Write_Register(0xB7); //Source EQ Enable 
    Write_Parameter(0X13); 

    Write_Register(0XB0);   //Gate Line Setting
    Write_Parameter(0X64);  //400 line = 100*4

    Write_Register(0x11); //Sleep out 
    delay(120); 

    Write_Register(0xC9); //Source Voltage Select  
    Write_Parameter(0X00); //VSHP1; VSLP1 ; VSHN1 ; VSLN1

    Write_Register(0x36); //Memory Data Access Control
    // Write_Parameter(0X00); //Memory Data Access Control: MX=0 ; DO=0 
    Write_Parameter(0X48); //MX=1 ; DO=1 
    // Write_Parameter(0X4c); //MX=1 ; DO=1 GS=1

    Write_Register(0x3A); //Data Format Select 
    Write_Parameter(0X11); //10:4write for 24bit ; 11: 3write for 24bit

    Write_Register(0xB9); //Gamma Mode Setting 
    Write_Parameter(0X20); //20: Mono 00:4GS  

    Write_Register(0xB8); //Panel Setting 
    Write_Parameter(0x29); // Panel Setting: 0x29: 1-Dot inversion, Frame inversion, One Line Interlace

    //WRITE RAM 300X400
    Write_Register(0X2A);   //Column Address Setting
    Write_Parameter(0X05);
    Write_Parameter(0X36);
    Write_Register(0X2B);   //Row Address Setting
    Write_Parameter(0X00);
    Write_Parameter(0XC7);

    Write_Register(0x35); //TE
    Write_Parameter(0X00); 

    Write_Register(0xD0); //Auto power dowb OFF
    // Write_Parameter(0X7F); //Auto power dowb OFF
    Write_Parameter(0XFF); //Auto power dowb ON


    // Write_Register(0x39); //LPM:Low Power Mode ON
    Write_Register(0x38); //HPM:high Power Mode ON

    HPM_MODE = true;
    LPM_MODE = false;

    Write_Register(0x29); //DISPLAY ON  
    // Write_Register(0x28); //DISPLAY OFF  

    // Write_Register(0x21); //Display Inversion On 
    Write_Register(0x20); //Display Inversion Off 

    Write_Register(0xBB); // Enable Clear RAM
    Write_Parameter(0x4F); // CLR=0 ; Enable Clear RAM,clear RAM to 0
}

void ST7306_4p2_BW_DisplayDriver::Low_Power_Mode(){
    if(LPM_MODE){
        HPM_MODE = false;
        LPM_MODE = true;
    }
    else{
        HPM_MODE = false;
        LPM_MODE = true;

        // VLC=3.6V (12/-5)(delta Vp=0.6V)		
        Write_Register(0xC1); //VSHP Setting (4.8V)	
        Write_Parameter(115); //VSHP1 	
        Write_Parameter(0X3E); //VSHP2 	
        Write_Parameter(0X3C); //VSHP3 	
        Write_Parameter(0X3C); //VSHP4	

        Write_Register(0xC2); //VSLP Setting (0.98V)	
        Write_Parameter(0); //VSLP1 	
        Write_Parameter(0X21); //VSLP2 	
        Write_Parameter(0X23); //VSLP3 	
        Write_Parameter(0X23); //VSLP4 	

        Write_Register(0xC4); //VSHN Setting (-3.6V)	
        Write_Parameter(50); //VSHN1	
        Write_Parameter(0X5C); //VSHN2 	
        Write_Parameter(0X5A); //VSHN3 	
        Write_Parameter(0X5A); //VSHN4 	

        Write_Register(0xC5); //VSLN Setting (0.22V)	
        Write_Parameter(50); //VSLN1 	
        Write_Parameter(0X35); //VSLN2 	
        Write_Parameter(0X37); //VSLN3 	
        Write_Parameter(0X37); //VSLN4

        Write_Register(0xC9); //Source Voltage Select  
        Write_Parameter(0X00); //VSHP1; VSLP1 ; VSHN1 ; VSLN1

        delay(20);

        Write_Register(0x39); //LPM:Low Power Mode ON
        delay(100);
    }
}

void ST7306_4p2_BW_DisplayDriver::High_Power_Mode(){
    if(HPM_MODE){
        HPM_MODE = true;
        LPM_MODE = false;
    }
    else{
        HPM_MODE = true;
        LPM_MODE = false;

        Write_Register(0x38); //HPM:high Power Mode ON
        delay(300);

        // VLC=3.6V (12/-5)(delta Vp=0.6V)		
        Write_Register(0xC1); //VSHP Setting (4.8V)	
        Write_Parameter(115); //VSHP1 	
        Write_Parameter(0X3E); //VSHP2 	
        Write_Parameter(0X3C); //VSHP3 	
        Write_Parameter(0X3C); //VSHP4	

        Write_Register(0xC2); //VSLP Setting (0.98V)	
        Write_Parameter(0); //VSLP1 	
        Write_Parameter(0X21); //VSLP2 	
        Write_Parameter(0X23); //VSLP3 	
        Write_Parameter(0X23); //VSLP4 	

        Write_Register(0xC4); //VSHN Setting (-3.6V)	
        Write_Parameter(50); //VSHN1	
        Write_Parameter(0X5C); //VSHN2 	
        Write_Parameter(0X5A); //VSHN3 	
        Write_Parameter(0X5A); //VSHN4 	

        Write_Register(0xC5); //VSLN Setting (0.22V)	
        Write_Parameter(50); //VSLN1 	
        Write_Parameter(0X35); //VSLN2 	
        Write_Parameter(0X37); //VSLN3 	
        Write_Parameter(0X37); //VSLN4

        Write_Register(0xC9); //Source Voltage Select  
        Write_Parameter(0X00); //VSHP1; VSLP1 ; VSHN1 ; VSLN1

        delay(20);
    }
}

void ST7306_4p2_BW_DisplayDriver::display_on(bool enabled){
    if(enabled){
        Write_Register(0x29); //DISPLAY ON  
    }else{
        Write_Register(0x28); //DISPLAY OFF  
    }
}

void ST7306_4p2_BW_DisplayDriver::display_sleep(bool enabled){
    if(enabled){
        if(LPM_MODE){
            Write_Register(0x38); //HPM:high Power Mode ON
            delay(300);
        }
        Write_Register(0x10); //sleep ON  
        delay(100);
    }else{
        Write_Register(0x11); //sleep OFF  
        delay(100);
    }
}

void ST7306_4p2_BW_DisplayDriver::display_Inversion(bool enabled){
    if(enabled){
        Write_Register(0x21); //Display Inversion On 
    }else{
        Write_Register(0x20); //Display Inversion Off 
    }
}

void ST7306_4p2_BW_DisplayDriver::address() {
    Write_Register(0x2A);//Column Address Setting S61~S182
    Write_Parameter(0X05);
    Write_Parameter(0X36); // 0X24-0X17=14 // 14*4*3=168

    Write_Register(0x2B);//Row Address Setting G1~G250
    Write_Parameter(0X00);
    Write_Parameter(0XC7); // 192*2=384

    Write_Register(0x2C);   //write image data
}

void ST7306_4p2_BW_DisplayDriver::Write_Register(uint8_t idat) {
    digitalWrite(DC_PIN, LOW);
    digitalWrite(CS_PIN, LOW);
    spiRef.write(idat);
    digitalWrite(CS_PIN, HIGH);
}

void ST7306_4p2_BW_DisplayDriver::Write_Parameter(uint8_t ddat) {
    digitalWrite(DC_PIN, HIGH);
    digitalWrite(CS_PIN, LOW);
    spiRef.write(ddat);
    digitalWrite(CS_PIN, HIGH);
}
