#include"NextionLCD.h"
#include"Nextion.h"
int NextionLCD::CurrentPage = 0;
static SoftwareSerial* NextionLCD::p_SoftwareSerialFromNodeMcu=new SoftwareSerial(11,10);

NextionLCD::NextionLCD()
{
   p_SoftwareSerialFromNodeMcu->begin(4800);     
   OpenWater.attachPush(OpenWaterPushCallback);  // Button press
   CloseWater.attachPush(CloseWaterPushCallback);  // Button press   
   MoreWater.attachPush(MoreWaterPushCallback);  // Button press  
   LessWater.attachPush(LessWaterPushCallback);  // Button press
   Warmer.attachPush(WarmerPushCallback);  // Button press
   Colder.attachPush(ColderPushCallback);  // Button press
   page0.attachPush(page0PushCallback);  // Page press event
   page1.attachPush(page1PushCallback);  // Page press event
}
NextionLCD::~NextionLCD()
{
  if(p_SoftwareSerialFromNodeMcu!=NULL)
  delete p_SoftwareSerialFromNodeMcu;
}
static void NextionLCD::OpenWaterPushCallback(void *ptr)  // Press event for button b1
{
  p_SoftwareSerialFromNodeMcu->print("1000");    
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);  
  delay(2300);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW); 
  Serial.println("Open water From Nextion");                  
} 
static void NextionLCD::CloseWaterPushCallback(void *ptr)  // Press event for button b1
{  
   p_SoftwareSerialFromNodeMcu->print("1100");
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,HIGH);                                        
   Serial.println("Close Water From Nextion");                
} 
static void NextionLCD::MoreWaterPushCallback(void *ptr)  // Press event for button b1
{
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);  
  delay(250);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW); 
  
  Serial.println("More Water From Nextion");         
} 
static void NextionLCD::LessWaterPushCallback(void *ptr)  // Press event for button b1
{ 
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);  
  delay(250);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);                      
} 
///////////
static void NextionLCD::WarmerPushCallback(void *ptr)  // Press event for button b1
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
                                                                                                                                                                                                               
   Serial.println("warmer From Nextion");
  
} 
///////////
static void NextionLCD::ColderPushCallback(void *ptr)  // Press event for button b1
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
                                                                                                       
  Serial.println("colder From Nextion");
} 
///////////////////////////////
// Page change event Nextion
static void NextionLCD::page0PushCallback(void *ptr)  // If page 0 is loaded on the display, the following is going to execute:
{
  CurrentPage = 0;  // Set variable as 0 so from now on arduino knows page 0 is loaded on the display
}  // End of press event


// Page change event:
static void NextionLCD::page1PushCallback(void *ptr)  // If page 1 is loaded on the display, the following is going to execute:
{
  CurrentPage = 1;  // Set variable as 1 so from now on arduino knows page 1 is loaded on the display
}  // End of press event
void NextionLCD::NexLoop(void)
{
  nexLoop(nex_listen_list);
}
void NextionLCD::DisconnectedToWifiSign()
{
     Serial.print("WifiStatusPic.pic=19");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.          
     Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
     Serial.write(0xff);
     Serial.write(0xff);        
     /////////////////////////  
     Serial.print("WifiStatus.pco=63488");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.          
     Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
     Serial.write(0xff);
     Serial.write(0xff);        
     /////////////////////////
     Serial.print("WifiStatus.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
     Serial.print("\"");
     Serial.print("Disconnected");
     Serial.print("\"");
     Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
     Serial.write(0xff);
     Serial.write(0xff);          
}
void  NextionLCD::ConnectedToWifiSign()
{
     Serial.print("WifiStatusPic.pic=18");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.          
     Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
     Serial.write(0xff);
     Serial.write(0xff);        
     /////////////////////////
     Serial.print("WifiStatus.pco=11749");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.          
     Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
     Serial.write(0xff);
     Serial.write(0xff);        
     /////////////////////////
     Serial.print("WifiStatus.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
     Serial.print("\"");
     Serial.print("Connected");
     Serial.print("\"");
     Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
     Serial.write(0xff);
     Serial.write(0xff);                 
}
void  NextionLCD::TemperatureSign()
{
  
}