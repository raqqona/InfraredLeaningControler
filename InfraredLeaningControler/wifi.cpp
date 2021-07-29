#include "wifi_header.h"
#include <Arduino.h>
#include <Wifi.h>
#include <WifiClientSecure.h>
WifiClientSecure client;

void WifiConnect(){   
    Wifi.begin(ssid, passwd);
    while (Wifi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(1000);
    }
    Serial.println("WiFi connected");
    Serial.print("IP address:");
    Serial.println(WiFi.localIP());
}

void MakeRequestHeader(char *header, char *method){
    strcat(header, method);
    strcat(header, " ");
    strcat(header, url);
    strcat(header, " HTTP/1.1\r\n");
    strcat(header, "Host: ");
    strcat(header, server);
    strcat(header, "\r\n");
    strcat(header, "Connection: keep-alive\r\n");
    strcat(header, "Content-Length: ");
    strcat(header, length);
    strcat(header, "\r\n");
    strcat(header, "\r\n");
}

char *ParseResponse(){
    while(client.connected()){
        while (client.available()) {
            if(client.read() == "\r"){
                break;
            }
        }
    }

    char response[client.available()];
    while(client.available()){
        strcat(response, client.read());
    }

    return response;
}


char *SendRequest(char *method, char *body){
  if (!client.connect(server, 443)){
    Serial.println("Connection Failed!");
  }else{
    Serial.println("Connected to sucsess!");
    char *header;
    MakeRequestHeader(header, method);

    client.print(head);
    client.print(body);

    char* response_body = ParseResponse();

    delay(2);
    client.stop();
    delay(2);

    return response_body;
  }
}