#define BLYNK_TEMPLATE_ID "TMPL31peu_B2J"
#define BLYNK_TEMPLATE_NAME "Project"
#define BLYNK_AUTH_TOKEN "ATZbI4g2K4_FzNRfvnhCG-8QV7OH0tmr"

#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#define DHTPIN D6
#define DHTTYPE DHT11
#define LED D3
DHT dht(DHTPIN, DHTTYPE);
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Avijit";
char pass[] = "12345678";
float h, t, smoke;

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 0)
  {
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }
}


void setup() {
  pinMode(A0,INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Temperature, Humidity");
  Blynk.begin(auth, ssid, pass);
  dht.begin();
}

void loop() {
  smoke=analogRead(A0);
  Blynk.virtualWrite(V3,smoke);
  Serial.println(smoke);
  h = dht.readHumidity();
  t = dht.readTemperature();
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
  Serial.print("humidity: ");
  Serial.println(h);
  Serial.print("temperature: ");
  Serial.println(t);
  Blynk.run();
  delay(1000);
}
