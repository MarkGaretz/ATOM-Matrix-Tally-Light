void showNetworkScreen() {
  Serial.println("Showing Network screen");
  resetScreen();
  screen = 1;
  if(screenRotation == 0 || screenRotation == 2){
    screenRotation = 3;
    M5.Lcd.setRotation(3); 
  }  
  M5.Lcd.println("SSID:");
  M5.Lcd.println(WIFI_SSID);
  M5.Lcd.println();
  M5.Lcd.println("IP Address:");
  M5.Lcd.println(WiFi.localIP());

  matrix.begin();
    matrix.fillScreen(0);
    matrix.setCursor(0,0);
    matrix.setTextColor(matrix.Color(0,255,0));
    matrix.setTextWrap(false);
    matrix.print("W");
    matrix.show();
    matrix.show();
   
}
