#include"valves.h"

Valves::Valves()
{
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN33,OUTPUT);
    pinMode(IN44,OUTPUT);     
}
Valves::~Valves()
{
    
}
void Valves::Initial()
{
  
}
void Valves::OpenWater()
{
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);  
  delay(2300);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW); 
  Serial.println("Open water");
}
void Valves::CloseWater()
{
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);                                        
  Serial.println("Close Water");
}
void Valves::Morewater()
{
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);  
  delay(250);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);                                                                  
  Serial.println("More water");
}
void Valves::LessWater()
{
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,HIGH);
   delay(250);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,LOW);                                                                                              
   Serial.println("Less Water"); 
}
void  Valves::Colder()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN33,HIGH);
  digitalWrite(IN44,LOW);
  delay(250);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN33,LOW);
  digitalWrite(IN44,LOW);
  Serial.println("Colder");
}
void Valves::Warmer()
{
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,HIGH);
   digitalWrite(IN33,LOW);
   digitalWrite(IN44,HIGH);
   delay(250);
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,LOW);
   digitalWrite(IN33,LOW);
   digitalWrite(IN44,LOW);                                                                                                                                                                                                          
   Serial.println("warmer");
}