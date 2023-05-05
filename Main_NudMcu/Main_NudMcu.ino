
#include"ConnectToWifi.h"
ConnectToWifi Obj_ConnectToWifi;
/////////////////////////
#include"SDCard.h"
SDCard Obj_SDCard;
/////////////////////////
#include"Adafruit.h"
AdaFruit Obj_AdaFruit;
/////////////////////////
#include"SerialWithMega.h"
SerialWithMega Obj_SerialWithMega; 
/////////////////////////

void setup() {
    Serial.begin(9600);
    Serial.setDebugOutput(true);
    ///////////////////////////
    Obj_SDCard.KeepTryingToConnectToSDCard();
    //////////////////////////
    Obj_ConnectToWifi.ConnectingToWifi();
    //////////////////////////    
    Obj_AdaFruit.SubscribeActionType();
}

void loop() {
 
  Obj_AdaFruit.MQTT_connect();
  //////////////////////////    
  Obj_AdaFruit.ReadSubscription();
  //////////////////////////    
  Obj_SerialWithMega.CheckingSerialFromMega();
   
}