# Arduino EMG Sensor Utility Library
Written by Stephen R Grenesko

This library was written with the intent to streamline the software used to have myoelectric sensors interact with standard electronic components such as bare LEDs, servo motors, etc. There will be several methods built to support these components, and attempts will be made to keep things well abstracted for beginner users. The goal of this library is to keep sketches involved free of the clutter of pin declarations, input and output managements etc. The secondary goal is to make the software needed to use myoelectric sensors more accessible to hobbyists and non coding background users.

## Current functionality

### EMG Sensor Object

***MyoUtil myo(int myoPin)*** - This is the EMG sensor object. You must call it at the beginning of the sketch and initialize the object with the *int myoPin* the EMG sensor is connected to.


### Basic EMG Readings

The library has two functions to pull readings from the EMG sensor.

***myo.begin(long baud)*** This function sets up the serial for reading data from the EMG. You must pass in a valid frequency *long baud*  (i.e. 115200) 

***myo.serialPlot()*** - This void function has no parameters and prints the values read from the EMG sensor onto a Serial plot in the IDE

***myo.readRaw()*** - This int function returns the current value being read by the EMG sensor. **NOTE**: if read in the loop function this value will constantly update.


### Basic LED Control

The library supports basic control of bare LEDs via the EMG sensor readings.

***myo.ledToggle(bool ledState, int ledPin, int threshold)*** - This function toggles an LED connected via *int ledPin*, to the state declared in *bool ledState*, after the EMG passes an arbitrary *int threshold* This essentially uses muscle movement as a momentary switch for a bare led.


### Basic Servo Control

The library supports a basic mapping of muscle flexing intensity to the degrees a servo is turned to.

***myo.servoInit(int servoPin, int maxAngle)*** - This void function sets up the servo for the user using the given *int servoPin*, as well as passes in the *int maxAngle* the servo can turn for use in the mapping process.

***myo.servoUpdate()*** - This void function changes the angle of the servo to match the intensity of the EMG reading. A stronger flex being read translates to an angle closer to the given servo's maximum rotation. Will not work with continuous rotation servos as is.


### Basic Stepper Motor Control

The library supports the basic mapping of EMG readings to the movement of a stepper motor.

***myo.stepperInit(int steps, int speed)*** - This void function initializes a stepper motor object with *int steps* number of steps at an RPM of *int speed*. **NOTE** This setup uses the generic Arduino stepper motor pin configuration (pins 8, 9, 10, 11), ensure they are not overwritten in your code. This functionality also requires a bipolar motor connected to the Arduino via an H-Bridge for proper signal manipulation needed for the stepper to change its polarity to mvoe.
***myo.stepperUpdate()*** - This function maps the EMG reading proportionally to the number of steps on the motor, and moves the motor accordingly.


### Basic Buzzer Control

The library supports a basic mapping of the EMG readings to the pitch of a piezo buzzer.

***myo.buzzerControl(int buzzPin, long maxFrequency)*** - This function initializes a buzzer with a maximum frequency. The reading of the EMG sensor then creates a tone proportional to its strength across the buzzer.


### Generic 16x2 LCD Support

The library supports using a hobbyist 16x2 liquid crystal display (LCD) to display the EMG reading. This uses the generic pin assignments typically shown in the Arduino LiquidCrystal library. Please check your pin usage in your design to ensure there is no overlap.

***myo.lcdInit()*** - Sets up the lcd object using the generic pinouts (12, 11, 5, 4, 3, 2)
***myo.lcdPrint()*** - Displays the EMG reading on the LCD
