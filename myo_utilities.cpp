#include "Arduino.h"
#include "myo_utilities.h"

MyoUtil::MyoUtil(int pin){
  _pin=pin;
  pinMode(_pin, INPUT_PULLUP);
}

void MyoUtil::serialPlot()
{
  Serial.begin(115200);
  int currVal=analogRead(_pin);
  Serial.print("\nCurrent EMG Reading: ");
  Serial.print(currVal);
  delay(50);
}

void MyoUtil::ledAction(bool ledState, int ledPin){
  _ledState=ledState;
  _ledPin=ledPin;
  int currVal=analogRead(_pin);
  pinMode(_ledPin, OUTPUT);
  while(currVal>0){
    if(_ledState==false){
      digitalWrite(_ledPin, LOW);
    }
    else if(_ledState==true){
      digitalWrite(_ledPin, HIGH);
    }
  }
}
