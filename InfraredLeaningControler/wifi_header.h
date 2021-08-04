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
void MakeRequestBody(char *body, double temp, double hum, double press);
char *ParseResponse();
char *SendRequest(char *method, char *body);

#endif