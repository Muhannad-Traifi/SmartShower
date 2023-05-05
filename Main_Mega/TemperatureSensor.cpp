#include"TemperatureSensor.h"

TemperatureSensor::TemperatureSensor()
{
  p_DallasTemperature=NULL;
  p_OneWire=          NULL;
  
}
TemperatureSensor::~TemperatureSensor()
{
  if(p_DallasTemperature!=NULL)
  delete p_DallasTemperature;
  if(p_OneWire!=NULL)
  delete p_OneWire;
}
void TemperatureSensor::initial()
{
  p_OneWire=new OneWire(ONE_WIRE_BUS);
  p_DallasTemperature=new DallasTemperature(p_OneWire);
  p_DallasTemperature->begin();

}

int TemperatureSensor::GetTemperature()
{
    return (int)p_DallasTemperature->getTempCByIndex(0);
}
void  TemperatureSensor::UpdatingTemperature()
{
  p_DallasTemperature->requestTemperatures();
       
  if(TemperatureOldValue!=(int)p_DallasTemperature->getTempCByIndex(0))
  { 
  TemperatureOldValue=(int)p_DallasTemperature->getTempCByIndex(0);  
  Serial.print("Temperature.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(TemperatureOldValue);  // This is the text you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  }
 
}