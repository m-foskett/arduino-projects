// Stepper Motor

#include <Stepper.h>

// Variable Definitions
const int stepsPerRevolution = 2048;
const int rpm = 15;

// Instantiate an object of class Stepper
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // Set the speed of the stepper motor
  myStepper.setSpeed(rpm);
  // Open the serial connection with Baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Clockwise Direction
  Serial.println("Clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);
  // Anti-clockwise Direction
  Serial.println("Anti-clockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
