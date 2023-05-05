#ifndef COMMANDSFROMALEXA_H
#define COMMANDSFROMALEXA_H
#include<SoftwareSerial.h>
class CommandsFromAlexa
{
  public:
  CommandsFromAlexa();
  ~CommandsFromAlexa();
  int CheckingForCommandsFromAlexa();
  private:
  SoftwareSerial* p_SoftwareSerialFromNodeMcu;
  
};
#endif