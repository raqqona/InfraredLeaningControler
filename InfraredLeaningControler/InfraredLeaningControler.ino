#include "bme280_header.h"
#include "infrare_header.h" 
#include "wifi_header.h"

COMMAND_OPTION cmd_option;
INDOOR_ENV indoorEnv;

void setup() {
  Serial.begin(9600);
  Wire.begin(21,22);
  WifiConnect();
  Bme280Init();
}

void loop() {
  ReadBmeData();
  indoorEnv.temp = GetTemp();
  indoorEnv.hum = GetHum();
  indoorEnv.press = GetPress();
  
  cmd_option = SendRequest("GET", indoorEnv);
  InfrareSend(cmd_option);
}
