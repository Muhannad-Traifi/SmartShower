#include"ConnectToWifi.h"

ConnectToWifi::ConnectToWifi()
{
   WiFiMulti=new ESP8266WiFiMulti;
   p_ESPSerial=new SoftwareSerial(D2,D3);
   p_ESPSerial->begin(4800);
}
ConnectToWifi::~ConnectToWifi()
{
  
}
void ConnectToWifi::Initial()
{
  
}
void ConnectToWifi::ConnectingToWifi()
{
  
  for(uint8_t t = 4; t > 0; t--) {
          delay(1000);
      }
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    
    //Serial.println(ssid);
    WiFiMulti->addAP(this->UserName,this->Password);

    //WiFi.disconnect();
    while(WiFiMulti->run() != WL_CONNECTED) 
    {
      Serial.print(".");
      delay(100);
      ///////
      ///////
      p_ESPSerial->print("99");
    }
    Serial.println("Connected to wi-fi");
    
}