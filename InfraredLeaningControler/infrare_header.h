#ifndef INCLUDE_INFRARE
#define INCLUDE_INFRARE

extern uint16_t IR_send_pin = 17;
extern decode_type_t maker_code = "MITSUBISHI112";
extern uint16_t IR_bits = 112;
extern uint16_t command_header = 0x23CB2601002;


void InfrareSendInit();
void InfrareSend();
unsigned char MakeCommand(char *power, char *mode, char *temp, char *fan, char *swing);

#endif