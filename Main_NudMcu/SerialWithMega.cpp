#include"SerialWithMega.h"
#include<SoftwareSerial.h>

SerialWithMega::SerialWithMega()
{
   p_ESPSerial=new SoftwareSerial(D2,D3);
   p_ESPSerial->begin(4800);
}
SerialWithMega::~SerialWithMega()
{
  
}
void SerialWithMega::CheckingSerialFromMega()
{
   if(p_ESPSerial->available()>0)
    {
      int Order= p_ESPSerial->parseInt();
      if(Order==OpenWaterExecute)
      {
        Serial.println("From Mega To Cloud Closing Water : ");       
        this->PublishPhotocell("Open water");
      }
      if(Order==CloseWaterExecute)
      {
        Serial.println("From Mega To Cloud Closing Water : ");
        this->PublishPhotocell("Close Water");
      }     
         
    }
}