// Ultrasonic Sensor Module

#include "SR04.h"

// Variable Definitions
const int trigPin = 12;
const int echoPin = 11;

// Instantiate an object with class SR04
SR04 sr04 = SR04(echoPin, trigPin);
// Measured distance in cm
long measuredDistance;

void setup() {
  // Initialise the serial port with a Baud rate of 9600
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // Measure the distance to an object
  measuredDistance = sr04.Distance();
  // Print out the measured distance
  Serial.print(measuredDistance);
  Serial.println("cm");
  delay(1000);
}
