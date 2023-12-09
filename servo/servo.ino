// Servo

#include <Servo.h>

// Create an object myServo of the class Servo
Servo myservo;

// Variable Definitions
const int signalWire = 9;

void setup(){
  myservo.attach(signalWire); // Connect pin 9 to the signal wire of the servo
  myservo.write(90); // Move the servo to the center position (90 degrees)
}

void loop(){
  // Move servo by increments of 10 degrees
  for(int i = 0; i < 18; i++){
    myservo.write((i+1)*10);
    delay(300);
  }
}
