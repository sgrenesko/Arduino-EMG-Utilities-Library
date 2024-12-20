#ifndef MYO_UTILITIES_H
#define MYO_UTILITIES_H

#include <Arduino.h>
class MyoUtil{
  public:

  //Prints the data recieved from the MyoWare from the declared analog pin 
  //into the SerialMonitor with some lines for context, returns current value
  //for use in calculations
  //Variable to pass: analog pin number (i.e. A0)
  int data(int analog);

  //Uses the data from the MyoWare to control an LED, 
  //current control flow is that the LED is toggled to the 
  //desired state when the sensor is activated
  //Variables: LED pin num, MyoWare reading from data, and String ("OFF", "ON", or "BLINK")
  void led(int led, int val, String state);

  

};
#endif