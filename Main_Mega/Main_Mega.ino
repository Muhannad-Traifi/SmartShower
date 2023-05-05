///Calling Temperature Class Object////////////////////////
#include"TemperatureSensor.h"
#include"valves.h"
TemperatureSensor Obj_TemperatureSensor;
////Calling Nextion LCD Object/////////////////////////////
#include"NextionLCD.h"
NextionLCD Obj_NextionLCD;
//////////////////////////////
Valves Obj_Valves;
//////////////////////////////
#include"CommandsFromAlexa.h"
CommandsFromAlexa Obj_CommandsFromAlexa;


enum Commands: int 
{
   OpenWater=1000,CloseWater=1100,MoreWater=1200,LessWater=1300,Colder=1400,Warmer=1500,Disconnected=99,Connected=100
};

void setup() {
    
    Serial.begin(9600);
    Obj_TemperatureSensor.initial();
}

void loop() 
{  
  Obj_NextionLCD.NexLoop(); 

  int CommandsFromAlexa;
  if((CommandsFromAlexa=Obj_CommandsFromAlexa.CheckingForCommandsFromAlexa())!=-1)
  {   
    ExecuteOrder(CommandsFromAlexa);   
  }
  
  Obj_TemperatureSensor.UpdatingTemperature();
}
void ExecuteOrder(int OrderID)
{
    
      switch(OrderID)
       {
         case OpenWater:                             
         Obj_Valves.OpenWater();               
         break;
         case CloseWater:                      
         Obj_Valves.CloseWater();
         break;
         case MoreWater:          
         Obj_Valves.Morewater();
         break;
         case LessWater:          
         Obj_Valves.LessWater();
         break;
         case Colder:          
         Obj_Valves.Colder();
         break;
         case Warmer:          
         Obj_Valves.Warmer();                                                                                                                                                                                                                       
         break;
         case Disconnected:
         Obj_NextionLCD.DisconnectedToWifiSign();
         break;
         case Connected:
         Obj_NextionLCD.ConnectedToWifiSign();                       
         default :
        ;
       }                         
}