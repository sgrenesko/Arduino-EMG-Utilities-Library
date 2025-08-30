#include "Arduino.h"
#include <Servo.h>
#include "myo_utilities.h"

MyoUtil::MyoUtil(int pin)
{
  _pin = pin;
  pinMode(_pin, INPUT);
}

void MyoUtil::begin(long baud)
{
  Serial.begin(baud);
}

void MyoUtil::serialPlot()
{
  int currVal = analogRead(_pin);
  Serial.println(currVal);
}

int MyoUtil::readRaw()
{
  return analogRead(_pin);
}

void MyoUtil::ledToggle(bool ledState, int ledPin, int threshold)
{
  _ledState = ledState;
  _ledPin = ledPin;
  pinMode(_ledPin, OUTPUT);

  int currVal = analogRead(_pin);
  int mappedVal = map(currVal, 0, 1023, 0, 255);

  if (mappedVal > threshold)
  {
    if (_ledState)
    {
      digitalWrite(_ledPin, HIGH);
    }
    else
    {
      digitalWrite(_ledPin, LOW);
    }
  }
  else
  {
    if (_ledState)
    {
      digitalWrite(_ledPin, LOW);
    }
    else
    {
      digitalWrite(_ledPin, HIGH);
    }
  }
}

void MyoUtil::servoInit(int servoPin, int maxAngle)
{
  _servoPin = servoPin;
  _maxAngle = maxAngle;
  servo.attach(_servoPin);
}

void MyoUtil::servoUpdate()
{
  int currVal = analogRead(_pin);
  int angle = map(currVal, 0, 1023, 0, _maxAngle);
  servo.write(angle);
}
