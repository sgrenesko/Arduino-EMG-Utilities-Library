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
#include "Servo.h"

class MyoUtil
{
public:
  MyoUtil(int pin);               //Constructor for EMG pin
  void serialPlot();              //Stream EMG to Serial Plotter
  int readRaw();                  //Return raw EMG reading
  void ledToggle(bool ledState, int ledPin, int threshold);    //Control an LED based on muscle activity
  void servoInit(int servoPin, int maxAngle);   //Servo init
  void servoUpdate();                           //Update servo position based on muscle activity
  void buzzControl(int buzzPin, int maxFrequency); //Control a buzzer based on muscle activity
private:
  int _pin;
  int _ledPin;
  bool _ledState;
  int _servoPin;
  int _maxAngle;
  Servo servo;
};

#endif
