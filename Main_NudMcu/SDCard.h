#ifndef SDCard_H
#define SDCard_H
#include <SD.h>
#include <SPI.h>
#include"Arduino.h"


class SDCard
{
  public:
  SDCard();
  ~SDCard();
  void SDCardReadFromFile();
  void KeepTryingToConnectToSDCard();
  int IndexofUsername=0;
  int IndexofPassword=0;
  protected:
  char UserName[50];
  char Password[50];
  private:
  File PasswordFile;
  int CS_PIN = D8;//Chip Selected Pin اختياري  elective pin so you can Chose any Digital pin you like
  //////////
  char FileData[100];
  //////////

  int indexOfData=0;
  int LineNumber=1;
  /*///////////////////////////////////////
CS   -> D8
SCK  -> D5
MOSI -> D7
MISO -> D6
VCC  -> VIN ( Be aware it does not work with 3.3V it needs 5V )
GND  -> GND
//////////////////////////////////////*/
  
};
#endif