#ifndef INCLUDE_INFRARE
#define INCLUDE_INFRARE

extern char url[] = "********";
extern char server[] = "********";

void WifiConnect();
void MakeRequestHeader(char *header, char *method);
char *ParseResponse();
char *SendRequest(char *method, char *body);

#endif