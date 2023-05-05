#ifndef CONNECTTOWIFI_H
#define CONNECTTOWIFI_H
#include <ESP8266WiFiMulti.h>
#include<SoftwareSerial.h>

#include"SDCard.h"

class ConnectToWifi:public SDCard
{
  public:
  ConnectToWifi();
  ~ConnectToWifi();
  void Initial();
  void ConnectingToWifi();
  private:
  SoftwareSerial* p_ESPSerial;
  ESP8266WiFiMulti* WiFiMulti;   
};
#endif