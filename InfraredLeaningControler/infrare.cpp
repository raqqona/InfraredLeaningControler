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
    command = MakeCommand();
    irsend.send(maker_code, command, IR_bits);
}

unsigned char MakeCommand() {
    unsigned char command[500];
    //next task
}
