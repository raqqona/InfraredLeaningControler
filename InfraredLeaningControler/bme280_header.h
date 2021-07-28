#ifndef INCLUDE_BME280
#define INCLUDE_BME280
/*
****************************************************
* Copyright (c) 2018 Switch Science                *
* This software is released under the MIT License. *
* http://opensource.org/licenses/mit-license.php   *
****************************************************
*/
extern BME280_ADDRESS 0x76

extern unsigned long int hum_raw,temp_raw,pres_raw;
extern signed long int t_fine;

//気温補正データ
extern uint16_t dig_T1;
extern int16_t dig_T2;
extern int16_t dig_T3;

//気圧補正データ
extern uint16_t dig_P1;
extern int16_t dig_P2;
extern int16_t dig_P3;
extern int16_t dig_P4;
extern int16_t dig_P5;
extern int16_t dig_P6;
extern int16_t dig_P7;
extern int16_t dig_P8;
extern int16_t dig_P9;

//湿度補正データ
extern uint8_t dig_H1;
extern int16_t dig_H2;
extern uint8_t dig_H3;
extern int16_t dig_H4;
extern int16_t dig_H5;
extern int8_t  dig_H6;


void Bme280Init();
void GetTemp(double* temp);
void GetHum(double* hum);
void GetPress(double* press);
void ReadTrim();
void WriteReg(uint8_t reg_address, uint8_t data);
void ReadBmeData();
signed long int Calibration_T(signed long int adc_T);
unsigned long int Calibration_P(signed long int adc_P);
unsigned long int Calibration_H(signed long int adc_H);

#endif