#ifndef INCLUDE_INFRARE
#define INCLUDE_INFRARE

extern char url[] = "********";
extern char server[] = "********";

typedef struct http_request {
    char header[256];
    char body[64];
}HTTP_REQUEST;


void WifiConnect();
void MakeRequestHeader(char *header, char *method);
void MakeRequestBody(char *body, INDOOR_ENV indoorEnv);
void ParseResponseBody(char *response_body, COMMAND_OPTION *option);
void ParseResponse(COMMAD_OPTION *cmd_option);
COMMAND_OPTION *SendRequest(char *method, INDDOR_ENV indoorEnv);

#endif
