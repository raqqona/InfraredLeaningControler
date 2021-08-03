#ifndef INCLUDE_INFRARE
#define INCLUDE_INFRARE

extern char url[] = "********";
extern char server[] = "********";

void WifiConnect();
void MakeRequestHeader(char *header, char *method);
void MakeRequestBody(char *body, double temp, double hum, double press);
char *ParseResponse();
char *SendRequest(char *method, char *body);

#endif