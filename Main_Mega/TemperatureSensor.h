#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureSensor
{
  public:
  TemperatureSensor();
  ~TemperatureSensor();
  DallasTemperature* p_DallasTemperature;
  OneWire*           p_OneWire;
  void initial();  
  int GetTemperature();
  void UpdatingTemperature();
  private:
  #define ONE_WIRE_BUS 9
  int TemperatureOldValue=0;
  
};
#endif