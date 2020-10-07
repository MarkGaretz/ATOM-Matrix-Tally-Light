/*
Tests string alignment

Normally strings are printed relative to the top left corner but this can be
changed with the setTextDatum() function. The library has #defines for:

TL_DATUM = Top left
TC_DATUM = Top centre
TR_DATUM = Top right
ML_DATUM = Middle left
MC_DATUM = Middle centre
MR_DATUM = Middle right
BL_DATUM = Bottom left
BC_DATUM = Bottom centre
BR_DATUM = Bottom right

 
 Needs fonts 2, 4, 6, 7 and 8

 Make sure all the display driver and pin comnenctions are correct by
 editting the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */
#include <M5StickC.h>

unsigned long drawTime = 0;

void setup(void) {
  M5.begin();
}

void loop() {

  M5.Lcd.fillScreen(TFT_BLACK);
  
  for(byte datum = 0; datum < 9; datum++) {
    M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
    
    M5.Lcd.setTextDatum(datum);
    
    M5.Lcd.drawNumber(8,40,80,7);
    M5.Lcd.fillCircle(40,80,5,TFT_RED);
    
    M5.Lcd.setTextDatum(MC_DATUM);
    
    M5.Lcd.setTextColor(TFT_BLACK);
    M5.Lcd.drawString("X",40,80,2);
    delay(1000);
    M5.Lcd.fillScreen(TFT_BLACK);
  }

  M5.Lcd.setTextColor(TFT_BLUE, TFT_BLACK);
  M5.Lcd.drawCentreString("6",40,80,7);
  M5.Lcd.fillCircle(40,80,5,TFT_YELLOW);
  
  M5.Lcd.setTextDatum(MC_DATUM);
  
  M5.Lcd.setTextColor(TFT_BLACK);
  M5.Lcd.drawString("X",40,80,2);
  delay(1000);
  M5.Lcd.fillScreen(TFT_BLACK);
  
  M5.Lcd.setTextColor(TFT_RED, TFT_BLACK);
  M5.Lcd.drawRightString("9",40,80,7);
  M5.Lcd.fillCircle(40,80,5,TFT_YELLOW);
  
  M5.Lcd.setTextDatum(MC_DATUM);
  
  M5.Lcd.setTextColor(TFT_BLACK);
  M5.Lcd.drawString("X",40,80,2);
  delay(1000);
  M5.Lcd.fillScreen(TFT_BLACK);

  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLUE);

  M5.Lcd.setTextDatum(MC_DATUM);

  //Test floating point drawing function
  float test = 67.12;
  M5.Lcd.drawFloat(test, 2, 40, 80, 4);
  delay(1000);
  M5.Lcd.fillScreen(TFT_BLACK);
  test = -0.555555;
  M5.Lcd.drawFloat(test, 3, 40, 80, 4);
  delay(1000);
  M5.Lcd.fillScreen(TFT_BLACK);
  test = 0.1;
  M5.Lcd.drawFloat(test, 4, 40, 80, 4);
  delay(1000);
  M5.Lcd.fillScreen(TFT_BLACK);
  
  M5.Lcd.fillCircle(40,120,5,TFT_YELLOW);
  
  M5.Lcd.setTextDatum(MC_DATUM);
  
  M5.Lcd.setTextColor(TFT_BLACK);
  M5.Lcd.drawString("X",40,120,2);
 
  delay(4000);
}
