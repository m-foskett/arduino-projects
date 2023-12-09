// Ball Switch

// Variable Definitions
const int ledPin = 13; //
const int switchPin = 2; //

void setup()
{ 
  pinMode(ledPin, OUTPUT); // Set ledPin to OUTPUT
  pinMode(switchPin,INPUT); // Set switchPin to INPUT
  digitalWrite(switchPin, HIGH); // Set switchPin to HIGH
} 

void loop() 
{ 
  int digitalVal = digitalRead(switchPin); // Read the current state of the switchPin

  if(HIGH == digitalVal) {
    digitalWrite(ledPin, LOW); // Turn the led OFF
  } else {
    digitalWrite(ledPin, HIGH); // Turn the led ON
  }
}
