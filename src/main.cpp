#include <Arduino.h>
#include <WiFi.h>

#define WIFI_SSID "Internet_Services_1418"
#define WIFI_PASSWORD "Meia242113"

#define LED 2

void setup() {  
    Serial.begin(115200);
    pinMode(LED, OUTPUT);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.println("Starting");
}
bool isConnected = false;
void loop() {
  if(WiFi.status() == WL_CONNECTED && !isConnected)
  {
    Serial.println("Connected");
    digitalWrite(LED, HIGH);
    isConnected= true;
  }
  
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    digitalWrite(LED, !digitalRead(LED));
    delay(100);
    isConnected = false;
  }
}
