#include "Arduino.h"
#include "myo_utilities.h"

MyoUtil::MyoUtil(int pin){
  _pin=pin;
}

void MyoUtil::serialPlot()
{
  pinMode(_pin, INPUT_PULLUP);
  Serial.begin(115200);
  int currVal=analogRead(_pin);
  Serial.print("\nCurrent EMG Reading: ");
  Serial.print(currVal);
  delay(50);
}
