#include"CommandsFromAlexa.h"
#include"Arduino.h"


CommandsFromAlexa::CommandsFromAlexa()
{
  p_SoftwareSerialFromNodeMcu= new SoftwareSerial(11,10);
  p_SoftwareSerialFromNodeMcu->begin(4800);
}
CommandsFromAlexa::~CommandsFromAlexa()
{
  if(p_SoftwareSerialFromNodeMcu!=NULL)
  delete p_SoftwareSerialFromNodeMcu;
}
int  CommandsFromAlexa::CheckingForCommandsFromAlexa()
{
  if(p_SoftwareSerialFromNodeMcu->available()>0)
  {
      int OrderID=p_SoftwareSerialFromNodeMcu->parseInt();
      Serial.print("From Alexa : ");
      Serial.println(OrderID);
     return OrderID;
  }else
  return -1;
}