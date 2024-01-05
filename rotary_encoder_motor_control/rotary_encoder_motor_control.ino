// Stepper Motor Control with Rotary Encoder

#include "Stepper.h"

// Variable Definitions and Pinout
const int rpm = 500;
// Steps per revolution of internal shaft, 2048 steps per revolution for external shaft
int steps = 32;
// Rotary Encoder Variables (marked with the qualifier 'volatile' as they will be changed in the interrupt sub routine)
volatile boolean turnDetected = false;
volatile boolean rotationDirection = false; // CW false, CCW true
const int CLK_pin = 2; // Clock signal
const int DT_pin = 3; // DT Signal
const int SW_pin = 4; // Switch button
// Current stepper motor position
int rotaryPosition = 0;
// Previous stepper motor position (used in case motor skips encoder values)
int previousPosition;
// Amount of steps to adjust stepper motor
int stepAmount = 50;

// Instantiate an object of class Stepper
Stepper myStepper(steps, 8, 10, 9, 11);

// Interrupt Sub Routine
//  - Runs on falling edge of clock signal
void isr () {
  // Short debouncing delay
  delay(4);
  // Store rotation direction based on the Clock pin
  if (digitalRead(CLK_pin))
    // Clockwise
    rotationDirection = digitalRead(DT_pin);
  else
    // Counter-clockwise
    rotationDirection = !digitalRead(DT_pin);
  turnDetected = true;
}

void setup() {
  // Set the pins of the rotary encoder to INPUT
  pinMode(CLK_pin, INPUT);
  pinMode(DT_pin, INPUT);
  pinMode(SW_pin, INPUT);
  // Make the switch a pull-up resistor
  digitalWrite(SW_pin, HIGH);
  // Attach Interrupt 0 (connected to pin 2)
  attachInterrupt(0, isr, FALLING);
  // Set the speed of the stepper motor
  myStepper.setSpeed(rpm);
  // Open serial connection with Baud Rate of 9600
  Serial.begin(9600);
  Serial.println("Stepper Motor Control with Rotary Encoder");
}

void loop()
{
  // Check if the switch has been pressed
  if (!digitalRead(SW_pin)) {
    // Check if the switch was not just pressed before
    if (rotaryPosition != 0) {
      myStepper.step(-(rotaryPosition * 50));
      // Reset the rotary position to zero
      rotaryPosition = 0;
    }
  }
  // If rotation is detected
  if (turnDetected) {
    // Store the previous position
    previousPosition = rotaryPosition;
    // Check if the rotationDirection is Clockwise
    if (rotationDirection) {
      // Reduce the rotary position by 1
      rotaryPosition -= 1;
    } else {
      // Increase the rotary position by 1
      rotaryPosition += 1;
    }
    // Reset the turnDetected flag to false for next rotation detection
    turnDetected = false;
    // Move the stepper motor in the determined rotationDirection
    if((previousPosition + 1) == rotaryPosition) {
      // Clockwise
      myStepper.step(stepAmount);
    } else if ((rotaryPosition + 1) == previousPosition) {
      // Counter-Clockwise
      myStepper.step(-stepAmount);
    }
  }
}