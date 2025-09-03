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
#include "LiquidCrystal.h"
#include "Stepper.h"

class MyoUtil
{
public:
  MyoUtil(int pin);                                 // Constructor for EMG pin
  void serialPlot();                                // Stream EMG to Serial Plotter
  int readRaw();                                    // Return raw EMG reading
  void ledInit(int ledPin);                         // LED init
  void ledUpdate(bool ledState, int threshold);     // Control an LED based on muscle activity
  void servoInit(int servoPin, int maxAngle);       // Servo init
  void servoUpdate();                               // Update servo position based on muscle activity
  void buzzControl(int buzzPin, long maxFrequency); // Control a buzzer based on muscle activity
  void lcdInit();                                   // Initialize the LCD
  void lcdPrint();                                  // Print EMG value to LCD
  void stepperInit(int steps, int speed);           // Stepper motor init
  void stepperUpdate();                             // Update stepper motor based on muscle activity
  void genericInit(int pin);                        // Generic device pin init
  void genericUpdate();                             // Generic device update based on muscle activity

private:
  int _pin;          // EMG sensor pinout
  int _ledPin;       // LED pinout
  bool _ledState;    // LED state (on/off)
  int _servoPin;     // Servo pinout
  int _maxAngle;     // Maximum servo angle
  int _steps;        // Steps for stepper motor
  int _prevStep;     // Previous stepper position
  int _pinOUT;       // Generic device pinout
  Stepper stepper;   // Stepper motor object
  Servo servo;       // Servo object
  LiquidCrystal lcd; // LCD object
};

#endif
