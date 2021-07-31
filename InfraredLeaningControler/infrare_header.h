#ifndef INCLUDE_INFRARE
#define INCLUDE_INFRARE

extern uint16_t IR_send_pin = 17;
extern decode_type_t maker_code = "MITSUBISHI112";
extern uint16_t IR_bits = 112;
extern uint16_t command_header = 0x23CB2601002;

extern uint8_t POWER_ON = 4
extern uint8_t POWER_OFF = 0
extern uint8_t MODE_HEAT = 1
extern uint8_t MODE_DRY = 4
extern uint8_t MODE_COOL = 3
extern uint8_t FAN_HIGH = 0
extern uint8_t FAN_MEDIUM = 5
extern uint8_t FAN_LOW = 3
extern uint8_t FAN_QUIET = 2
extern uint8_t SWING_UNKNOWN = 0
extern uint8_t SWING_HIGHEST = 1
extern uint8_t SWING_HIGH = 2
extern uint8_t SWING_MIDDLE = 3
extern uint8_t SWING_LOW = 4
extern uint8_t SWING_LOWEST = 5
extern uint8_t SWING_AUTO = 7



void InfrareSendInit();
void InfrareSend();
unsigned char MakeCommand(char *power, char *mode, char *temp, char *fan, char *swing);

#endif