#ifndef VALVES_H
#include<Arduino.h>
class Valves
{
  public:
  Valves();
  ~Valves();
   void Initial();
   void OpenWater();
   void CloseWater();
   void Morewater();
   void LessWater();
   void Colder();
   void Warmer();
   
  private:
  #define IN3 2
  #define IN4 3
  #define IN33 4
  #define IN44 5
  #define IN1 6
  #define IN2 7
};
#define VALVES_H
#endif