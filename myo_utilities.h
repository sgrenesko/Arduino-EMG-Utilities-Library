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
#ifndef MYO_UTILITIES_H
#define MYO_UTILITIES_H

#include "Arduino.h"

class MyoUtil {
  public:
    MyoUtil(int pin);       //Constructor for EMG pin
    void begin(long baud=115200); //Serial init
    void serialPlot();      //Stream EMG to Serial Plotter
    int readRaw();          //Return raw EMG reading
    void ledAction(bool ledState, int ledPin);

  private:
    int _pin;
    int _ledPin;
    bool _ledState;
};

#endif
