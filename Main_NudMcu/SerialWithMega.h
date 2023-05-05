#ifndef SERIALWITHMEGA_H
#define SERIALWITHMEGA_H
#include"Adafruit.h"
class SerialWithMega:public AdaFruit
{
  public:
  SerialWithMega();
  ~SerialWithMega();
  void CheckingSerialFromMega();
  private:
  SoftwareSerial* p_ESPSerial;

  
};
#endif