#include "bme280_header.h"
#include "infrare_header.h" 
#include "wifi_header.h"

char received_body[128];
double temp, hum, press = 0.0;

void setup() {
  Serial.begin(9600);
  Wire.begin(21,22);
  WifiConnect();
  Bme280Init();
}

void loop() {
  ReadBmeData();
  temp = GetTemp();
  hum = GetHum();
  press = GetPress();
  
  response_body = SendRequest("GET", temp, hum, press);
  InfrareSend(response_body);
}
