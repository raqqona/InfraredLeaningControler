#include "wifi_header.h"
#include <Arduino.h>
#include <Wifi.h>
#include <WifiClientSecure.h>
WifiClientSecure client;

void WifiConnect() {   
    Wifi.begin(ssid, passwd);
    while (Wifi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(1000);
    }
    Serial.println("WiFi connected");
    Serial.print("IP address:");
    Serial.println(WiFi.localIP());
}

void MakeRequestHeader(HTTP_REQUEST *request, char *method) {
    char buf[8];

    strcat(requst->header, method);
    strcat(requst->header, " ");
    strcat(requst->header, url);
    strcat(requst->header, " HTTP/1.1\r\n");
    strcat(requst->header, "Host: ");
    strcat(requst->header, server);
    strcat(requst->header, "\r\n");
    strcat(requst->header, "Connection: keep-alive\r\n");
    strcat(requst->header, "Content-Length: ");
    snprintf(buf, 8, "%d", sizeof(request.body));
    strcat(requst->header, buf);
    strcat(requst->header, "\r\n");
    strcat(requst->header, "\r\n");
}

void MakeRequestrequest->bodyBody(HTTP_REQUEST *request, double temp, double hum, double press) {
    char buf[8];

    strcat(request->body, "{'temp':");
    snprintf(buf, 8, "%f", temp);
    strcat(request->body, buf);
    strcat(request->body, ",'hum':");
    snprintf(buf, 8, "%f", hum);
    strcat(request->body, buf);
    strcat(request->body, ",'press':");
    snprintf(buf, 8, "%f", press);
    strcat(request->body, buf);
    strcat(request->body, "}");
}

char *ParseResponse() {
    while(client.connected()) {
        while (client.available()) {
            if(client.read() == "\r"){
                break;
            }
        }
    }

    char body[client.available()];
    while(client.available()){
        strcat(body, client.read());
    }

    return body;
}


char *SendRequest(char *method, double temp, double hum, double press) {
  if (!client.connect(server, 443)) {
    Serial.println("Connection Failed!");
  }else{
    Serial.println("Connected to sucsess!");

    HTTP_REQUEST reqeuest;

    MakeRequestHeader(request, method);
    MakeRequestHeader(request, temp, hum, press);

    client.print(request->head);
    client.print(request->body);


    char response_body[128];
    response_body = ParseResponse();

    delay(2);
    client.stop();
    delay(2);

    return response_request->body;
  }
}
