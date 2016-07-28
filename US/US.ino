/* 
 *  Title:Park My Car
 *  Author:Vijay Bhaskar
 *  Date:07/27/2016
*/
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,2);
int trig1=11;
int trig2=10;
int trig3=9;
int trig4=8; 
int echo1=7;
int echo2=6;
int echo3=5;
int echo4=4;
int pir=12;
int detect;
int duration1;
int duration2;
int duration3;
int duration4;        
float distance1;  
float distance2;
float distance3;  
float distance4;        
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(trig3, OUTPUT);
  pinMode(trig4, OUTPUT);
  digitalWrite(trig1, LOW);
  digitalWrite(trig2, LOW);
  digitalWrite(trig3, LOW);
  digitalWrite(trig4, LOW);
  delayMicroseconds(2); 
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  pinMode(echo4, INPUT);
  pinMode(pir, INPUT);
  delay(6000);
  Serial.println("Distance:");
} 
void loop()
{  
  detect = digitalRead(pir);
  

  if(detect == 1)
  {
    check();
  }
  else 
  {
    delay(1000);
    check();
  }   
}

void check()
{
 
  digitalWrite(trig1, HIGH);   
  delayMicroseconds(1000);              
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH);
  delayMicroseconds(1000);
    
  digitalWrite(trig2, HIGH);   
  delayMicroseconds(1000);               
  digitalWrite(trig2, LOW);  
  duration2 = pulseIn(echo2, HIGH);
  delayMicroseconds(1000);
  
  digitalWrite(trig3, HIGH);   
  delayMicroseconds(1000);               
  digitalWrite(trig3, LOW);  
  duration3 = pulseIn(echo3, HIGH);
  delayMicroseconds(1000);
  
  digitalWrite(trig4, HIGH);   
  delayMicroseconds(1000);               
  digitalWrite(trig4, LOW);   
  duration4 = pulseIn(echo4, HIGH);
  delayMicroseconds(1000);
  
  if(duration1>=38000 || duration2>=38000 || duration3>=38000 || duration4>=38000){
    Serial.print("Out range");  
    } 
 
  else
  {
    Serial.println(  "A: "+ String(duration1/58.31) + "cm\tB: " + String(duration2/58.31) + "cm\tC: " + String(duration3/58.31) + "cm\tD: " + String(duration1/58.31) + "cm");
    mySerial.println("A: "+ String(duration1/58.31) + "cm\tB: " + String(duration2/58.31) + "cm\tC: " + String(duration3/58.31) + "cm\tD: " + String(duration1/58.31) + "cm");
     
    if (duration1<(58.31*8) || duration1<(58.31*8) || duration1<(58.31*8) || duration1<(58.31*8)){
      digitalWrite(13,HIGH);
      }
    else{
      digitalWrite(13,LOW);      
    }     
   } 
}

