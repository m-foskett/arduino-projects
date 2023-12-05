// Digital Input: Toggling an LED

// Variable Definitions
int ledPin = 5;
int buttonOnPin = 9;
int buttonOffPin = 8;

void setup() 
{
  // Led Pin set to output
  pinMode(ledPin, OUTPUT);
  // Buttons set to Input Pullup so that the default value is HIGH unless pulled low
  pinMode(buttonOnPin, INPUT_PULLUP);  
  pinMode(buttonOffPin, INPUT_PULLUP);  
}

void loop() 
{
  // Check if the On button has been pressed
  if (digitalRead(buttonOnPin) == LOW)
  {
    // Write HIGH to the LED
    digitalWrite(ledPin, HIGH);
  }
  // Check if the Off button has been pressed
  if (digitalRead(buttonOffPin) == LOW)
  {
    // Write LOW to the LED
    digitalWrite(ledPin, LOW);
  }
}
