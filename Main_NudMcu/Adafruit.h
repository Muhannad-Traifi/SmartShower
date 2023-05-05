#ifndef ADAFRUIT_H
#define ADAFRUIT_H

#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include"Arduino.h"

class AdaFruit
{
  public:
  AdaFruit();
  ~AdaFruit();
  void Initial();
  void SubscribeActionType();
  void PublishPhotocell(char*);
  void ReadSubscription();
  void MQTT_connect();
  
   enum Commands: int 
  {
   OpenWaterCommand=0,CloseWaterCommand=1,MoreWaterCommand=2,LessWaterCommand=3,ColderCommand=4,WarmerCommand=5
  };
  enum CommandsExcute: int 
  {
   OpenWaterExecute=1000,CloseWaterExecute=1100,MoreWaterExecute=1200,LessWaterExecute=1300,ColderExecute=1400,WarmerExecute=1500,Disconnected=99,Connected=100
  };
 
  private:
  SoftwareSerial* p_ESPSerial;

  private:
  bool MQttOneTimeConnected=0;
  bool MQttOneTimeDisConnected=0;
/************************* Adafruit.io Setup *********************************/
  #define AIO_SERVER      "io.adafruit.com"
  #define AIO_SERVERPORT  1883                   // use 8883 for SSL
  #define AIO_USERNAME    "Hero1980"
  #define AIO_KEY         "a10ccd9585ea41208b7a2cd346e8d139"
  WiFiClient client;
  Adafruit_MQTT_Client* mqtt;
  Adafruit_MQTT_Publish* photocell;
  Adafruit_MQTT_Subscribe* ActionType;

 
  
};
#endif