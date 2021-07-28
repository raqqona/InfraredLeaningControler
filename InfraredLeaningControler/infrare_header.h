#ifndef INCLUDE_INFRARE
#define INCLUDE_INFRARE

extern uint16_t IR_send_pin = 16;
extern decode_type_t maker_code = "MITSUBISHI112";
extern uint16_t IR_bits = 112;


void InfrareSendInit();
void InfrareSend();
unsigned char MakeCommand();

#endif