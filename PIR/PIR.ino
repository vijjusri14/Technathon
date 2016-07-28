/*///////////////////////////////////////*/ 
/*/  Title:PIR Sensor Test Code         /*/
/*/  Author:Vijay Bhaskar               /*/
/*/  Date:07/27/2016                    /*/
/*///////////////////////////////////////*/
int sensor=2;
int led=13; 
int pir;
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);//led off
}
void loop()
{
  pir= digitalRead(sensor);//Reads the Sensor
  if (pir==1){
     digitalWrite(led,HIGH);//led on
     Serial.println("Humans");
     delay(3000);
     digitalWrite(led,LOW);//led off
    }
    delay(100);
}
