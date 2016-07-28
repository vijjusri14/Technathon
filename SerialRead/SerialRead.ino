/*///////////////////////////////////////*/ 
/*/  Title:NodeMCU SerialRead Test Code /*/
/*/  Author:Vijay Bhaskar               /*/
/*/  Date:07/27/2016                    /*/
/*///////////////////////////////////////*/

#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress server_addr(10,0,1,35);  // IP of the MySQL *server* here
char user[] = "root";              // MySQL user login username
char password[] = "secret";        // MySQL user login password

SoftwareSerial mySerial(13,15);

// WiFi card example
char ssid[] = "WiFi";    // your SSID
char pass[] = "password";       // your SSID Password

// Sample query
char INSERT_SQL[] = "INSERT INTO test_arduino.hello_arduino (message) VALUES ('Hello, Arduino!')";

WiFiClient client;            // Use this for WiFi instead of EthernetClient
MySQL_Connection conn((Client *)&client);

String incoming;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  // Begin WiFi section
  int status = WiFi.begin(ssid, pass);
  if ( status != WL_CONNECTED) {
    Serial.println("Couldn't get a wifi connection");
    while(true);
  }
  // print out info about the connection:
  else {
    Serial.println("Connected to network");
    IPAddress ip = WiFi.localIP();
    Serial.print("My IP address is: ");
    Serial.println(ip);
  }
  // End WiFi section

  Serial.println("Connecting...");
  if (conn.connect(server_addr, 3306, user, password)) {
    delay(1000);
  }
  else
    Serial.println("Connection failed.");
  conn.close();
}

void loop() {
  if(Serial.available()>0 || mySerial.available()>0){
    incoming = mySerial.readString();

    Serial.print("I got: ");
    Serial.println(incoming);

    delay(2000);

  Serial.println("Recording data.");

  // Initiate the query class instance
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  // Execute the query
  cur_mem->execute(INSERT_SQL);
  // Note: since there are no results, we do not need to read any data
  // Deleting the cursor also frees up memory used
  delete cur_mem;
  }
}
