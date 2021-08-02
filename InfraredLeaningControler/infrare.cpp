#include "infrare_header.h"
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRac.h>
#include <IRtext.h>
#include <IRutils.h>
#include <IRsend.h>

void InfrareSendInit(){
    IRsend irsend(IR_Send_pin);
    irsend.begin();
}

void InfrareSend(){
    unsigned char command[28];
    command = MakeCommand();
    irsend.send(maker_code, command, IR_bits);
}

unsigned char *MakeCommand(char *power, char *mode, int temp, char *fan, char *swing) {
    unsigned char command[28];
    command = COMMNAD_HEADER;
    if (power = "ON"){
        command[11] = POWER_ON;

    }else if(power = "OFF"){
        command[11] = POWER_OFF;
    }else {
        return "failed";
    }
    command[12] = 0x0
    if (mode = "COOL"){
        command[13] = MODE_COOL;
    }else if (mode = "DRY") {
        command[13] = MODE_DRY;
    }else if (mode = "HEAT") {
        command[13] = MODE_HEAT;
    }else {
        return "failed";
    }
    if (temp > 31 || temp < 18) {
        return "failed";
    }
    command[14] = 0x0;
    command[15] = (unsigned char)(31 - temp);
    if (swing == "UNKNOWN") {
        command[16] = SWING_UNKNOWN;
    }else if (swing == "HIGHEST") {
        command[16] =SWING_HIGHEST;
    }else if (swing == "HIGH") {
        command[16] =SWING_HIGH;
    }else if (swing == "MIDDLE") {
        command[16] =SWING_MIDDLE;
    }else if (swing == "LOW") {
        command[16] =SWING_LOW;
    }else if (swing == "LOWEST") {
        command[16] =SWING_LOWEST;
    }else if (swing == "AUTO") {
        command[16] =SWING_AUTO;
    }else {
        return "failed";
    }
    if (fan == "HIGH" && swing == "UNKNOWN" || swing == "HIGH" || swing == "LOW" || swing == "LOWEST") {
        command[17] = FAN_HIGH << 8;
    }else if (fan == "HIGH" && swing == "HIGHEST" || swing == "MIDDLE" || swing == "AUTO") {
        command[17] = FAN_HIGH;
    }else if (fan == "MIDIUM" && swing == "UNKNOWN" || swing == "HIGH" || swing == "LOW" || swing == "LOWEST") {
        command[17] = FAN_MIDIUM << 8;
    }else if (fan == "MIDIUM" && swing == "HIGHEST" || swing == "MIDDLE" || swing == "AUTO") {
        command[17] = FAN_MIDIUM;
    }else if (fan == "LOW" && swing == "UNKNOWN" || swing == "HIGH" || swing == "LOW" || swing == "LOWEST") {
        command[17] == FAN_LOW << 8;
    }else if (fan == "LOW" && swing == "HIGHEST" || swing == "MIDDLE" || swing == "AUTO") {
        command[17] == FAN_LOW;
    }else if (fan == "QUIET" && swing == "UNKNOWN" || swing == "HIGH" || swing == "LOW" || swing == "LOWEST") {
        command[17] == FAN_QUIET << 8;
    }else if (fan == "QUIET" && swing == "HIGHEST" || swing == "MIDDLE" || swing == "AUTO") {
        command[17] == FAN_QUIET;
    }else {
        return "failed";
    }
    command[18] = 0x00000000
    command[26] = PARITY + command[13] + command[15] + (command[16] << 1) + command[17];

    return commnad;
}
