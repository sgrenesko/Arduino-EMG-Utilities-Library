#include "myo_utilities.h"


int MyoUtil::data(int analog){
  int sensorVal = analogRead(analog);
  Serial.print("\nCurrent EMG Value: ");
  Serial.print(sensorVal);
  Serial.print(" microVolts");
  delay(50);
  return sensorVal;
}

void MyoUtil::led(int led, int val, String state){
  pinMode(led, OUTPUT);
  state=state.toUpperCase();
  if(state=='ON'){
    digitalWrite(led,HIGH);
  }
  else if (state=="OFF"){
    digitalWrite(led,LOW);
  }
  else if (state=="BLINK"){
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
  else{
    Serial.print("\nERROR: INVALID STATE, PLEASE INPUT EITHER ON, OFF, OR BLINK");
  }
}
