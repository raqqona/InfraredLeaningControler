#include "wifi_header.h"
#include <Arduino.h>
#include <Wifi.h>
#include <WifiClientSecure.h>
#include <ArduinoJson.h>
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

void MakeRequestrequest->bodyBody(HTTP_REQUEST *request, INDOOR_ENV idoorEnv) {
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

void ParseResponseBody(char *response_body, COMMAND_OPTION *option) {
    StaticJsonDocument<128> res_json; 
    DeserializationError error = deserializaJson(res_json, response_body, sizeof(response_json));
    if (error) {
        return "failed";
    }

    option->power = res_json['power'];
    option->mode = res_json['mode'];
    option->temp = res_json['temp'];
    option->fan = res_json['fan'];
    option->swing = res_json['swing'];
    option->command = res_json['command']
}

void ParseResponse(COMMAND_OPTION *cmd_option) {
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

    ParseResponseBody(body, cmd_option);
    if (cmd_option.command == false){
        return;
    }
}


COMMAND_OPTION *SendRequest(char *method, INDOOR_ENV idoorEnv) {
  if (!client.connect(server, 443)) {
    Serial.println("Connection Failed!");
  }else{
    Serial.println("Connected to sucsess!");

    HTTP_REQUEST reqeuest;

    MakeRequestHeader(request, method);
    MakeRequestHeader(request, indoorEnv);

    client.print(request->head);
    client.print(request->body);

    COMMAND_OPTION cmd_option;
    ParseResponse(cmd_option);

    delay(2);
    client.stop();
    delay(2);

    return cmd_option;
  }
}
