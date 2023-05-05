#include"Adafruit.h"

//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
AdaFruit::AdaFruit()
 {
   mqtt=new Adafruit_MQTT_Client(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
   photocell = new Adafruit_MQTT_Publish(this->mqtt, AIO_USERNAME "/feeds/photocell");
   ActionType =new  Adafruit_MQTT_Subscribe(this->mqtt, AIO_USERNAME "/feeds/action_type");
   p_ESPSerial=new SoftwareSerial(D2,D3);
   p_ESPSerial->begin(4800);


 }
 //////////////////////////////////////
 //////////////////////////////////////
 //////////////////////////////////////
AdaFruit::~AdaFruit()
{
  
}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
void AdaFruit::Initial()
{
  
}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
void AdaFruit::MQTT_connect()
{
  int8_t ret;

  // Stop if already connected.
  if (mqtt->connected()) {
      MQttOneTimeDisConnected=1;
      if(MQttOneTimeConnected)
      p_ESPSerial->print(Connected);
      MQttOneTimeConnected=0;
    return;
  }
  MQttOneTimeConnected=1;
  if(MQttOneTimeDisConnected)
      p_ESPSerial->print(Disconnected);
      MQttOneTimeDisConnected=0;
  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt->connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt->connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt->disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
//////////////////////////////////////
 //////////////////////////////////////
 //////////////////////////////////////
void AdaFruit::SubscribeActionType()
 {
   mqtt->subscribe(this->ActionType);
 }
 //////////////////////////////////////
 //////////////////////////////////////
 //////////////////////////////////////

void AdaFruit::PublishPhotocell(char* PublishedText)
 {
    photocell->publish(PublishedText);
 }
 //////////////////////////////////////
 //////////////////////////////////////
 //////////////////////////////////////

void  AdaFruit::ReadSubscription()
{
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt->readSubscription(5000))) 
  {
    if (subscription == this->ActionType) 
    {
      uint8_t* action_type=ActionType->lastread;
      int myint=atoi((const char *)action_type);
      Serial.print(F("Got: "));
      Serial.println(myint);
      
      switch(myint)
      {
        case OpenWaterCommand:
        p_ESPSerial->print(OpenWaterExecute);                
        break;
        case CloseWaterCommand:
        p_ESPSerial->print(CloseWaterExecute);
        break;
        case MoreWaterCommand:
        p_ESPSerial->print(MoreWaterExecute);
        break;
        case LessWaterCommand:
        p_ESPSerial->print(LessWaterExecute);
        break;
        case ColderCommand:
        p_ESPSerial->print(ColderExecute);
        break;
        case WarmerCommand:
        p_ESPSerial->print(WarmerExecute);
        default:
        ;
      }
    }
  }
}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////