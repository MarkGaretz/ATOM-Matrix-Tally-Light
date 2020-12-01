WiFiClient client;
WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

PinButton btnM5(37);
PinButton btnAction(39);

char currentState = -1;
char screen = 0;
bool connectedTovMix = false;

char deviceName[32];
int status = WL_IDLE_STATUS;
bool apEnabled = false;
boolean started = false;

// Time measure
int interval = 5000;
unsigned long lastCheck = 0;
unsigned long lastBattCheck = 0;
unsigned long lastAccCheck = 0;
unsigned long lastConnCheck = 0;
int screenRotation = 3;

float accX = 0;
float accY = 0;
float accZ = 0;

void setup()
{
  uint8_t c;
  Serial.begin(115200);
  M5.begin();
  matrix.begin();
  M5.IMU.Init();
  delay(10);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  loadSettings();
  
  Serial.print("SSID: ");
  Serial.println(&(WIFI_SSID[0]));
  Serial.print("PASS: ");
  Serial.println(&(WIFI_PASS[0]));
}

void loop()
{
  server.handleClient();
  btnM5.update();
  if (btnM5.isClick()) {
    if (screen == 0) {
      showNetworkScreen();
    } else if (screen == 1) {
      showTallyNum();
    } else if (screen == 2) {
      showBrightnessScreen();
    } else if (screen == 3) {
      showTallyScreen();
    }
  }

  M5.IMU.getAccelData(&accX, &accY, &accZ);

  if(millis() > lastAccCheck + 1000){
    lastAccCheck = millis();
    if(accX > 0.70){
      if(screenRotation != 1){
        screenRotation = 1;
        M5.Lcd.setRotation(1);
        renderCurrentScreen();
      }
    } else if(accX < -0.70){
      if(screenRotation != 3){
        screenRotation = 3;
        M5.Lcd.setRotation(3);
        renderCurrentScreen();
      }
    }
    if(screen != 1){
      if(accY > 0.70){
        if(screenRotation != 0){
          screenRotation = 0;
          M5.Lcd.setRotation(0);
          renderCurrentScreen();
        }
      } else if (accY < -0.70){
        if(screenRotation != 2){
          screenRotation = 2;
          M5.Lcd.setRotation(2);
          renderCurrentScreen();
        }
      }
    }
  }

  if(!started){
    started = true;
    start();
  }
  
  btnAction.update();
  if (btnAction.isClick() && screen == 0) {
    connectTovMix(false);

matrix.setTextColor(matrix.Color(0,0,255));
matrix.setTextWrap(false);
matrix.setCursor(0,0);
matrix.fillScreen(0);


String LocalIP = String() + WiFi.localIP()[0] + "-" + WiFi.localIP()[1] + "-" + WiFi.localIP()[2] + "-" + WiFi.localIP()[3];

int iplen = 0;
for (iplen=0; iplen<=LocalIP.length(); iplen++) {
  matrix.fillScreen(0);
  matrix.setCursor(0,0);
  matrix.print(LocalIP.charAt(iplen));
  matrix.show();
  matrix.show();
  delay(1200);
  matrix.fillScreen(0);
  matrix.setCursor(0,0);
  matrix.show();
  matrix.show();
  delay(100);
  
}
matrix.fillScreen(0);
matrix.show();
matrix.show();
showTallyScreen();

}

if (btnAction.isClick() && screen == 4) {
    
  matrix.setTextColor(matrix.Color(255,0,255));
  matrix.setTextWrap(false);
  matrix.setCursor(0,0);
  matrix.fillScreen(0);


String LocalIP = String() + WiFi.localIP()[0] + "-" + WiFi.localIP()[1] + "-" + WiFi.localIP()[2] + "-" + WiFi.localIP()[3];

int iplen = 0;
for (iplen=0; iplen<=LocalIP.length(); iplen++) {
  matrix.fillScreen(0);
  matrix.setCursor(0,0);
  matrix.print(LocalIP.charAt(iplen));
  matrix.show();
  matrix.show();
  delay(1200);
  matrix.fillScreen(0);
  matrix.setCursor(0,0);
  matrix.show();
  matrix.show();
  delay(100);
}
matrix.fillScreen(0);
matrix.show();
matrix.show();

    connectTovMix(false);



}
  
  if(btnAction.isLongClick() && screen == 0){
    if(!client.connected()){
       resetSettings();
    } else {
      resetScreen();
      M5.Lcd.println("No need to reset");
      M5.Lcd.println("You're connected");
      delay(3000);
      showTallyScreen();
    }
  }

  if(btnAction.isClick() && screen == 3){
     updateBrightnessVar();
  }

  if(btnAction.isDoubleClick() && screen == 2){
    increaseTally();
    showTallyNum();
  }
  if(btnAction.isLongClick() && screen == 2){
    resetTally();
    showTallyNum();
  }
  
  while (client.available())
  {
    server.handleClient();
    String data = client.readStringUntil('\r\n');
    handleData(data);
  }

  if(millis() > lastBattCheck + 1000){
    if(screen == 0 && client.available()){
      lastBattCheck = millis();
      renderBatteryLevel(); 
    }
  }
  
    if (CONN_INT != 0 && !client.connected() && !apEnabled && millis() > lastConnCheck + (CONN_INT * 1000))  
  { 
    client.stop();  
    Serial.println("Reconnecting, based on given interval");  
    singleReconnect();  
  }
  
  if (!client.connected() && !apEnabled && millis() > lastCheck + interval)
  {
    client.stop();
    lastCheck = millis();
    noConnectionTovMix();
  }
}

void cls()
{
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setCursor(0, 0);
}

void start()
{
  cls();
  loadSettings();
  screenRotation = screenRotation == 1 || screenRotation == 3 ? screenRotation : 3;
  M5.Lcd.setRotation(screenRotation);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.setCursor(20, 20);
  M5.Lcd.println("vMix M5Stick-C Tally");
  M5.Lcd.setCursor(35, 40);
  M5.Lcd.println("by Guido Visser");
    //matrix.setRotation(1); // Uncomment this to rotate the Matrix Display
    matrix.setTextColor(matrix.Color(0,255,0));
    matrix.setTextWrap(false);
    matrix.print("P");
    matrix.show();
    matrix.show();
  
  delay(2000);

  startWiFi();
}

void resetScreen(){
  cls();
  digitalWrite(LED_BUILTIN, HIGH);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(WHITE, BLACK);
}

void renderBatteryLevel() {
  int battLvl = getBatteryLevel();
  if(battLvl > 100){
    battLvl = 100; 
  }
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(0,0);
  M5.Lcd.print("Batt: ");
  M5.Lcd.print(battLvl);
  M5.Lcd.println("%");
}

int getBatteryLevel(void)
{
  uint16_t vbatData = M5.Axp.GetVbatData();
  double vbat = vbatData * 1.1 / 1000;
  return floor(100.0 * ((vbat - 3.0) / (4.07 - 3.0)));
}

void renderCurrentScreen(){
  if(screen == 0){
    showTallyScreen();
  } else if (screen == 1) {
    showNetworkScreen();
  } else if (screen == 2) {
    showTallyNum();
  }
}
