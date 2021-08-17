#ifndef INCLUDE_INFRARE
#define INCLUDE_INFRARE

extern uint16_t IR_PIN = 17;
extern char MAKER_CODE[13] = "MITSUBISHI112";
extern uint16_t IR_BITS = 112;
extern uint16_t COMMAND_HEADER = 0x23CB2601002;

extern uint8_t POWER_ON = 0x4
extern uint8_t POWER_OFF = 0x0
extern uint8_t MODE_HEAT = 0x1
extern uint8_t MODE_DRY = 0x4
extern uint8_t MODE_COOL = 0x3
extern uint8_t FAN_HIGH = 0x0
extern uint8_t FAN_MEDIUM = 0x5
extern uint8_t FAN_LOW = 0x3
extern uint8_t FAN_QUIET = 0x2
extern uint8_t SWING_UNKNOWN = 0x0
extern uint8_t SWING_HIGHEST = 0x1
extern uint8_t SWING_HIGH = 0x1
extern uint8_t SWING_MIDDLE = 0x2
extern uint8_t SWING_LOW = 0x2
extern uint8_t SWING_LOWEST = 0x3
extern uint8_t SWING_AUTO = 0x0
extern uint8_t PARITY = 0x30

typedef struct command_option {
    char power[3];
    char mode[4];
    int temp;
    char fan[6];
    char swing[7];
    bool command;
}COMMAND_OPTION;



void InfrareSendInit();
void InfrareSend(char *received_body);
void ParseResponseBody(char *response_body, COMMAND_OPTION *option);
unsigned char *MakeCommand(char *command, COMMAND_OPTION *option);

#endif
