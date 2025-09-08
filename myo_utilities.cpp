#include "Arduino.h"
#include "Servo.h"
#include "LiquidCrystal.h"
#include "Stepper.h"
#include "myo_utilities.h"

// Constructor to initialize the MyoUtil object with the specified pin
MyoUtil::MyoUtil(int pin)
{
  _pin = pin;
  pinMode(_pin, INPUT);
}

// Output EMG reading to Serial for data visualization
void MyoUtil::serialPlot()
{
  _currVal = analogRead(_pin);
  Serial.println(currVal);
  delay(50);
}

// Return the raw EMG reading from the sensor
int MyoUtil::readRaw()
{
  return analogRead(_pin);
}

// Initialize the LED pin
void MyoUtil::ledInit(int ledPin)
{
  _ledPin = ledPin;
  pinMode(_ledPin, OUTPUT);
}

// Control an LED based on muscle activity (toggle state)
void MyoUtil::ledUpdate(bool ledState, int threshold)
{
  _ledState = ledState;

  bool active = (_currVal > threshold);

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
  _servoPin = servoPin;
  _maxAngle = maxAngle;
  servo.attach(_servoPin);
}

// Update the servo position based on muscle activity
void MyoUtil::servoUpdate()
{
  int angle = map(_currVal, 0, 1023, 0, _maxAngle);
  servo.write(angle);
  delay(10);
}

// Control a buzzer based on muscle activity (frequency modulation)
void MyoUtil::buzzInit(int buzzPin, long maxFrequency)
{
  _buzzPin = buzzPin;
  _maxFrequency = maxFrequency;
}

// Update the buzzer pin to play a pitch based on muscle activity
void MyoUtil::buzzUpdate(bool buzzState)
{
  if (buzzState)
  {
    _frequency = map(_currVal, 0, 1023, 100, _maxFrequency);
    tone(_buzzPin, _frequency);
  }
  else
  {
    noTone(_buzzPin);
  }
}

// Initialize the LCD (assuming a standard 16x2 LCD with specific pin configuration)
void MyoUtil::lcdInit()
{
  lcd = new LiquidCrystal(12, 11, 5, 4, 3, 2); // Generic pin configuration for standard hobbyist 16x2 LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("EMG Value (Hz):");
}

// Print the EMG value to the LCD at the specified column and row
void MyoUtil::lcdPrint()
{
  lcd.setCursor(0, 1);
  lcd.print("         ");
  lcd.setCursor(0, 1);
  lcd.print(analogRead(_pin));
  delay(10);
}

// Initialize the stepper motor with the specified number of steps and speed
void MyoUtil::stepperInit(int steps, int speed)
{
  _steps = steps;
  _prevStep = 0;
  stepper = new Stepper(_steps, 8, 9, 10, 11); // Generic pin configuration for bipolar stepper motor and H-Bridge configuration
  stepper.setSpeed(speed);
}

// Update the stepper motor position based on muscle activity
void MyoUtil::stepperUpdate()
{
  int stepVal = map(_currVal, 0, 1023, 0, _steps);
  stepper.step(stepVal - _prevStep);
  _prevStep = stepVal;
}

// Generic initialization for other output devices
void MyoUtil::genericInit(int pin)
{
  _pinOUT = pin;
  pinMode(_pinOUT, OUTPUT);
}

// Generic update function to map EMG readings to device
void MyoUtil::genericUpdate()
{
  int outVal = map(_currVal, 0, 1023, 0, 255);
  analogWrite(_pinOUT, outVal);
}