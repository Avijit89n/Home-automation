#include <WiFiManager.h>
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <WiFi.h>

const char DEVICE_LOGIN_NAME[] = "device login name"; //enter your device login name
const char DEVICE_KEY[] = "device key"; // enter your device key

WiFiManager wm;

char SSID[32];
char PASS[32];

int s1 = 16, s2 = 17, s3 = 18, s4 = 19, s5 = 34, s6 = 35, s7 = 36, s8 = 39;
int r1 = 21, r2 = 22, r3 = 23, r4 = 25, r5 = 26, r6 = 27, r7 = 32, r8 = 33;
int ledPin = 2;
int configBtn = 4;

unsigned long pressStartTime = 0;
const unsigned long holdTime = 5000;

void onSwitch1Change();
void onSwitch2Change();
void onSwitch3Change();
void onSwitch4Change();

CloudSwitch switch1;
CloudSwitch switch2;
CloudSwitch switch3;
CloudSwitch switch4;
CloudSwitch switch5;
CloudSwitch switch6;
CloudSwitch switch7;
CloudSwitch switch8;

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

void setup() {
  Serial.begin(9600);
  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);
  pinMode(s4, INPUT_PULLUP);
  pinMode(s5, INPUT_PULLUP);
  pinMode(s6, INPUT_PULLUP);
  pinMode(s7, INPUT_PULLUP);
  pinMode(s8, INPUT_PULLUP);

  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(r6, OUTPUT);
  pinMode(r7, OUTPUT);
  pinMode(r8, OUTPUT);

  pinMode(ledPin, OUTPUT);

  pinMode(configBtn, INPUT_PULLUP);
  wm.setConfigPortalBlocking(false);

  WiFi.begin();

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);

  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(switch1, READWRITE, ON_CHANGE, onSwitch1Change);
  ArduinoCloud.addProperty(switch2, READWRITE, ON_CHANGE, onSwitch2Change);
  ArduinoCloud.addProperty(switch3, READWRITE, ON_CHANGE, onSwitch3Change);
  ArduinoCloud.addProperty(switch4, READWRITE, ON_CHANGE, onSwitch4Change);
  ArduinoCloud.addProperty(switch5, READWRITE, ON_CHANGE, onSwitch5Change);
  ArduinoCloud.addProperty(switch6, READWRITE, ON_CHANGE, onSwitch6Change);
  ArduinoCloud.addProperty(switch7, READWRITE, ON_CHANGE, onSwitch7Change);
  ArduinoCloud.addProperty(switch8, READWRITE, ON_CHANGE, onSwitch8Change);
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  ArduinoCloud.printDebugInfo();
}

int prevStage1 = 0;
int prevStage2 = 0;
int prevStage3 = 0;
int prevStage4 = 0;
int prevStage5 = 0;
int prevStage6 = 0;
int prevStage7 = 0;
int prevStage8 = 0;

bool checkOffline = false;

void loop() {

  if (digitalRead(configBtn) == LOW && WiFi.status() != WL_CONNECTED) {
    if (pressStartTime = 0) {
      pressStartTime = millis();
    }
    if (millis() - pressStartTime >= holdTime) {
      Serial.println("Button pressed! Entering WiFi config mode...");
      wm.setConfigPortalTimeout(120);
      wm.startConfigPortal("Project_lab", "12345678");
      Serial.println("WiFi config mode active...");

      strcpy(SSID, WiFi.SSID().c_str());
      strcpy(PASS, WiFi.psk().c_str());
    }
  } else {
    pressStartTime = 0;
  }



  wm.process();

  int btn1 = !digitalRead(s1);
  int btn2 = !digitalRead(s2);
  int btn3 = !digitalRead(s3);
  int btn4 = !digitalRead(s4);
  int btn5 = !digitalRead(s5);
  int btn6 = !digitalRead(s6);
  int btn7 = !digitalRead(s7);
  int btn8 = !digitalRead(s8);


  if (prevStage1 != btn1) {
    switch1 = !switch1;
    digitalWrite(r1, switch1);
  }
  if (prevStage2 != btn2) {
    switch2 = !switch2;
    digitalWrite(r2, switch2);
  }
  if (prevStage3 != btn3) {
    switch3 = !switch3;
    digitalWrite(r3, switch3);
  }
  if (prevStage4 != btn4) {
    switch4 = !switch4;
    digitalWrite(r4, switch4);
  }
  if (prevStage5 != btn5) {
    switch5 = !switch5;
    digitalWrite(r5, switch5);
  }
  if (prevStage6 != btn6) {
    switch6 = !switch6;
    digitalWrite(r6, switch6);
  }
  if (prevStage7 != btn7) {
    switch7 = !switch7;
    digitalWrite(r7, switch7);
  }
  if (prevStage8 != btn8) {
    switch8 = !switch8;
    digitalWrite(r8, switch8);
  }

  prevStage1 = btn1;
  prevStage2 = btn2;
  prevStage3 = btn3;
  prevStage4 = btn4;
  prevStage5 = btn5;
  prevStage6 = btn6;
  prevStage7 = btn7;
  prevStage8 = btn8;

  if (WiFi.status() == WL_CONNECTED) {
    if (checkOffline == true) {
      switch1 = btn1;
      switch2 = btn2;
      switch3 = btn3;
      switch4 = btn4;
      switch5 = btn5;
      switch6 = btn6;
      switch7 = btn7;
      switch8 = btn8;
    }
    ArduinoCloud.update();
    digitalWrite(ledPin, HIGH);
    checkOffline = false;
  }
  if (WiFi.status() != WL_CONNECTED) {
    checkOffline = true;
    wm.process();
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}


void onSwitch1Change() {
  digitalWrite(r1, switch1);
}
void onSwitch2Change() {
  digitalWrite(r2, switch2);
}
void onSwitch3Change() {
  digitalWrite(r3, switch3);
}
void onSwitch4Change() {
  digitalWrite(r4, switch4);
}
void onSwitch5Change() {
  digitalWrite(r5, switch5);
}
void onSwitch6Change() {
  digitalWrite(r6, switch6);
}
void onSwitch7Change() {
  digitalWrite(r7, switch7);
}
void onSwitch8Change() {
  digitalWrite(r8, switch8);
}
