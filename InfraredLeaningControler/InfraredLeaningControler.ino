#include "bme280_header.h"
#include "infrare_header.h" 
#include "wifi_header.h"

void setup() {
  Serial.begin(9600);
  Wire.begin(21,22);
  WifiConnect();
  Bme280Init();
}

void loop() {
  double temp, hum, press = 0.0;

  ReadBmeData();
  temp = GetTemp();
  hum = GetHum();
  press = GetPress();
  
  char received_command[128];
  received_command = SendRequest("GEt", temp, hum, press);
}
