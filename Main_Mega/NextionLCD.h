#ifndef NEXTIONLCD.h
#define NEXTIONLCD.h
#include <Nextion.h>  // Include the nextion library (the official one) https://github.com/itead/ITEADLIB_Arduino_Nextion
                      // Make sure you edit the NexConfig.h file on the library folder to set the correct serial port for the display.
                      // By default it's set to Serial1, which most arduino boards don't have.
                      // Change "#define nexSerial Serial1" to "#define nexSerial Serial" if you are using arduino uno, nano, etc.
#include<SoftwareSerial.h>
class NextionLCD
{
  public:
  NextionLCD();
  ~NextionLCD();
   void NexLoop(void);
   static void OpenWaterPushCallback(void *ptr);
   static void CloseWaterPushCallback(void *ptr);
   static void MoreWaterPushCallback(void *ptr);
   static void LessWaterPushCallback(void *ptr);
   static void WarmerPushCallback(void *ptr);
   static void ColderPushCallback(void *ptr); 
   static void page0PushCallback(void *ptr);
   static void page1PushCallback(void *ptr);
   static SoftwareSerial* p_SoftwareSerialFromNodeMcu;
   void ConnectedToWifiSign();
   void DisconnectedToWifiSign();
   void TemperatureSign();
   
  private:
 

  #define IN3  2
  #define IN4  3
  #define IN33 4
  #define IN44 5
  #define IN1  6
  #define IN2  7
  //////////////Nextion Buttons////////////
NexButton OpenWater = NexButton(0, 1, "OpenWater");  // Button added
NexButton CloseWater = NexButton(0, 2, "CloseWater");  // Button added
NexButton MoreWater = NexButton(0, 4, "MoreWater");  // Button added
NexButton LessWater = NexButton(0, 3, "LessWater");  // Button added
NexButton Warmer = NexButton(0, 6, "Warmer");  // Button added
NexButton Colder = NexButton(0, 5, "Colder");  // Button added
////////////////Nextion Pages /////////////////////////
NexPage page0 = NexPage(0, 0, "page0");  // Page added as a touch event
NexPage page1 = NexPage(1, 0, "page0");  // Page added as a touch event
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
static int CurrentPage;  // Create a variable to store which page is currently loaded ( Nextion )

/////////////////Nextion  event objects ///////////////////////////////////////
NexTouch* nex_listen_list[9] = 
{
  &OpenWater,  // Button added
  &CloseWater, // Button added
  &MoreWater,  // Button added
  &LessWater,  // Button added
  &Warmer,     // Button added
  &Colder,     // Button added

  &page0,  // Page added as a touch event
  &page1,  // Page added as a touch event
  NULL  // String terminated
};  // End of touch event list
};
#endif