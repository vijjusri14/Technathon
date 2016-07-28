/*///////////////////////////////////////*/ 
/*/  Title:Ultrasonic Sensor Test Code  /*/
/*/  Author:Vijay Bhaskar               /*/
/*/  Date:07/27/2016                    /*/
/*///////////////////////////////////////*/
int trig=12; 
int echo=9;
int duration;        
float distance;     

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2); 
  pinMode(echo, INPUT);
  delay(6000);
  Serial.println("Distance:");
} 

void loop()
{  
  digitalWrite(trig, HIGH);   
  delayMicroseconds(10);               
  digitalWrite(trig, LOW); 
  duration = pulseIn(echo, HIGH);
  if(duration >= 38000)
    Serial.print("Out range");   
  else
  {
    distance = duration/58.31;   
    Serial.println(String(distance) + "cm");
    if (distance < 4)
      digitalWrite(13,HIGH);
    else
      digitalWrite(13,LOW);
  } 
  delay(1000);
}

