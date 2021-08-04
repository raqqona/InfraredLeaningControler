## InfraredLeaningControler

温湿気圧を読める赤外線学習リモコンです．

###　環境
* esp32 DevKit-C
* bme280
* 5mm赤外線LED 940nm OSI5LA5113A
* OSRB38C9AA

### bme280 setup(i2c)
下の表の通りにピンを接続。
| VID | GND | CSB | SDI | SDO | SCK |
| --- | --- | --- | --- | --- | --- |
| 3V3 | GND | 3V3 | 21  | GND | 22  |

### 5mm赤外線LED 940nm OSI5LA5113A
| + | - |
| - | - |
| X | Y |

### OSRB38C9AA
| OUT | GND | VCC |
| --- | --- | --- |
| 17  | GND | 5V  |

### リモコンの送信データ
0xmaker code/P/M/T/S/F000000XX
