#include <M5StickC.h>

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setCursor(25, 2);
  M5.Lcd.printf("UNIT_EARTH EXAMPLE\n");
  pinMode(32, INPUT);
  M5.Lcd.setCursor(10, 30);
  M5.Lcd.print("GPIO33:");
  M5.Lcd.setCursor(10, 50);
  M5.Lcd.print("GPIO32:");
}

uint16_t analogRead_value = 0;
uint16_t digitalRead_value = 0;
void loop() {
  // put your main code here, to run repeatedly:
  M5.Lcd.setCursor(80, 30);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.printf("%d\n", analogRead_value);
  M5.Lcd.setCursor(80, 50);
  M5.Lcd.printf("%d\n", digitalRead_value);
  analogRead_value = analogRead(33);
  digitalRead_value = digitalRead(32);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setCursor(80, 30);
  M5.Lcd.printf("%d\n", analogRead_value);
  M5.Lcd.setCursor(80, 50);
  M5.Lcd.printf("%d\n", digitalRead_value);
  delay(10);
}
