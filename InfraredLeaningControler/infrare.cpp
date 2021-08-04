#include "infrare_header.h"
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRac.h>
#include <IRtext.h>
#include <IRutils.h>
#include <IRsend.h>

void InfrareSendInit(){
    IRsend irsend(IR_PIN);
    irsend.begin();
}

void InfrareSend(char *response_body){
    unsigned char *command;
    command = (unsigned char *)malloc(28);
    if (command == NULL) {
        break;
    }

    COMMAND_OPTION *option;
    option = (COMMAND_OPTION *)malloc(sizeof(COMMAND_OPTION));
    if (option == NULL) {
        break;
    }

    ParseResponseBody(response_body, option);
    MakeCommand(command, option);
    irsend.send(MAKER_CODE, command, IR_BITS);
    
    free(commnad);
    free(option);
}

void ParseResponseBody(char *response_body, COMMAND_OPTION *option) {
    //APIの仕様決めてから
    option->power = response_body;
    option->mode = response_body;
    option->temp = response_body;
    option->fan = response_body;
    option->swing = response_body;
}

void MakeCommand(char *command, COMMAND_OPTION *option) {
    command[0] = COMMNAD_HEADER;
    if (option->power = "ON"){
        command[11] = POWER_ON;

    }else if(option->power = "OFF"){
        command[11] = POWER_OFF;
    }else {
        return "failed";
    }
    command[12] = 0x0
    if (option->mode = "COOL"){
        command[13] = MODE_COOL;
    }else if (option->mode = "DRY") {
        command[13] = MODE_DRY;
    }else if (option->mode = "HEAT") {
        command[13] = MODE_HEAT;
    }else {
        return "failed";
    }
    if (temp > 31 || temp < 18) {
        return "failed";
    }
    command[14] = 0x0;
    command[15] = (unsigned char)(31 - temp);
    if (option->swing == "UNKNOWN") {
        command[16] = SWING_UNKNOWN;
    }else if (option->swing == "HIGHEST") {
        command[16] =SWING_HIGHEST;
    }else if (option->swing == "HIGH") {
        command[16] =SWING_HIGH;
    }else if (option->swing == "MIDDLE") {
        command[16] =SWING_MIDDLE;
    }else if (option->swing == "LOW") {
        command[16] =SWING_LOW;
    }else if (option->swing == "LOWEST") {
        command[16] =SWING_LOWEST;
    }else if (option->swing == "AUTO") {
        command[16] =SWING_AUTO;
    }else {
        return "failed";
    }
    if (option->fan == "HIGH" && option->swing == "UNKNOWN" || option->swing == "HIGH" || option->swing == "LOW" || option->wing == "LOWEST") {
        command[17] = FAN_HIGH << 8;
    }else if (option->fan == "HIGH" && option->swing == "HIGHEST" || option->swing == "MIDDLE" || option->swing == "AUTO") {
        command[17] = FAN_HIGH;
    }else if (option->fan == "MIDIUM" && option->swing == "UNKNOWN" || option->swing == "HIGH" || option->swing == "LOW" || option->swing == "LOWEST") {
        command[17] = FAN_MIDIUM << 8;
    }else if (option->fan == "MIDIUM" && option->swing == "HIGHEST" || option->swing == "MIDDLE" || option->swing == "AUTO") {
        command[17] = FAN_MIDIUM;
    }else if (option->fan == "LOW" && option->swing == "UNKNOWN" || option->swing == "HIGH" || option->wing == "LOW" || option->swing == "LOWEST") {
        command[17] == FAN_LOW << 8;
    }else if (option->fan == "LOW" && option->swing == "HIGHEST" || option->swing == "MIDDLE" || option->swing == "AUTO") {
        command[17] == FAN_LOW;
    }else if (option->fan == "QUIET" && option->swing == "UNKNOWN" || option->swing == "HIGH" || option->swing == "LOW" || option->swing == "LOWEST") {
        command[17] == FAN_QUIET << 8;
    }else if (option->fan == "QUIET" && option->swing == "HIGHEST" || option->swing == "MIDDLE" || option->swing == "AUTO") {
        command[17] == FAN_QUIET;
    }else {
        return "failed";
    }
    command[18] = 0x00000000
    command[26] = PARITY + command[13] + command[15] + (command[16] << 1) + command[17];

    return commnad;
}
