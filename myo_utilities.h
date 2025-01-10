/*
Myoelectric Utilities Library by Stephen Grenesko

This library contains a variety of pre made functions in order to 
streamline the software used by microcontrollers in conjunction
with myoelectric sensors. 
This library will allow for cleaner code practices,
 as well as creating a layer of abstraction to remove
the need of tedious serial porting and pin setup. 
Supports more simplistic interaction between the sensor and standard controlled hardware.

*/

#ifndef myo_utilities_h
#define myo_utilities_h

#include "Arduino.h"

class MyoUtil{
  public:
  //Object creation for myoware sensor data pin, based on MyoWare 2.0 hardware I/O
    MyoUtil(int pin);
  //Serial plotting for the sensor data
    void serialPlot();

  private:
    int _pin; //Analog data pin
};
#endif