#include "InfraredLeaningControler_header.h"

void setup() {
  Bme280Init()
}

void loop() {
  double temp, hum, press = 0.0;

  ReadBmeData();
  temp = GetTemp();
  hum = GetHum();
  press = GetPress();
}
