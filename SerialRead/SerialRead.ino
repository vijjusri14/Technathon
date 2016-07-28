/*///////////////////////////////////////*/ 
/*/  Title:NodeMCU SerialRead Test Code /*/
/*/  Author:Vijay Bhaskar               /*/
/*/  Date:07/27/2016                    /*/
/*///////////////////////////////////////*/

#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(13,15);
const char* ssid = "WiFi";
const char* password = "password";
String incoming;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if(Serial.available()>0 || mySerial.available()>0){
    incoming = mySerial.readString();

    Serial.print("I got: ");
    Serial.println(incoming);    
  }
}
