#include "Arduino.h"
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

void MyoUtil::ledAction(bool ledState, int ledPin)
{
  _ledState = ledState;
  _ledPin = ledPin;
  pinMode(_ledPin, OUTPUT);

  if (_ledState)
  {
    digitalWrite(_ledPin, HIGH);
  }
  else
  {
    digitalWrite(_ledPin, LOW);
  }
}

