#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "gfx.h"
#include "SPI.h"
#include "sense_air.hpp"

const char* ssid     = "Jlucu4ka";
const char* password = "Kisylia22";
SoftwareSerial swSers8(13, 15, false, 256); // RX, TX

void setup() {
  Serial.begin (115200);
  Serial.setDebugOutput(true);
  delay(10);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  s8_setup(swSers8);
}

int value = 0;

void loop() {
  uint16_t co2;

  //MQTT_connect();
  co2 = readco2(swSers8);
  //senseair.publish(co2);
  
  delay(10 * 1000L);
}