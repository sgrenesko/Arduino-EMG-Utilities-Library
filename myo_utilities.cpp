#include "Arduino.h"
#include "Servo.h"
#include "myo_utilities.h"

// Constructor to initialize the MyoUtil object with the specified pin
MyoUtil::MyoUtil(int pin)
{
  _pin = pin;
  pinMode(_pin, INPUT);
}

// Initialize serial communication with the specified baud rate
void MyoUtil::serialPlot()
{
  int currVal = analogRead(_pin);
  Serial.println(currVal);
}

// Return the raw EMG reading from the sensor
int MyoUtil::readRaw()
{
  return analogRead(_pin);
}

void MyoUtil::ledInit(int ledPin)
{
  _ledPin = ledPin;
  pinMode(_ledPin, OUTPUT);
}

// Control an LED based on muscle activity (toggle state)
void MyoUtil::ledToggle(bool ledState, int threshold)
{
  _ledState = ledState;

  int currVal = analogRead(_pin);

  bool active = (currVal > threshold);

  if (_ledState)
  {
    digitalWrite(_ledPin, active ? HIGH : LOW);
  }
  else
  {
    digitalWrite(_ledPin, active ? LOW : HIGH);
  }
}

// Initialize the servo with the specified pin and maximum angle
void MyoUtil::servoInit(int servoPin, int maxAngle)
{
  _maxAngle = maxAngle;
  servo.attach(servoPin);
}

// Update the servo position based on muscle activity
void MyoUtil::servoUpdate()
{
  int currVal = analogRead(_pin);
  int angle = map(currVal, 0, 1023, 0, _maxAngle);
  servo.write(angle);
}

// Control a buzzer based on muscle activity (frequency modulation)
void MyoUtil::buzzControl(int buzzPin, long maxFrequency)
{
  int currVal = analogRead(_pin);
  int frequency = map(currVal, 0, 1023, 100, maxFrequency);
  tone(buzzPin, frequency);
}