#include "bme280_header.h"

void setup() {
  Serial.begin(9600);
  Wire.begin(21,22);
  Bme280Init()
}

void loop() {
  double temp, hum, press = 0.0;

  ReadBmeData();
  temp = GetTemp();
  hum = GetHum();
  press = GetPress();
}
