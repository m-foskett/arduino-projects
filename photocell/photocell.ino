// Photocell

// Variable Definitions
int latchPin = 11; // ST_CP [RCK]
int clockPin = 9; // SH_CP [SCK]
int dataPin = 12; // DS [S1]
int lightPin = 0; // Analog Pin 0 for photocell analog input
byte ledPattern = B00000000; // Bit Pattern to store the pattern of active LEDs

void setup() 
{
  // Setup the pins to be OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void updateShiftRegister()
{
  // Set the latch pin to LOW
  digitalWrite(latchPin, LOW);
  // Shift the data out
  // Parameters:
  //  - Data Pin
  //  - Clock Pin
  //  - Which end of data to start at
  //  - Data to shift into the shift register
  shiftOut(dataPin, clockPin, LSBFIRST, ledPattern);
  // Set the latch pin back to HIGH
  digitalWrite(latchPin, HIGH);
}

void loop() 
{
  // Read the raw analog measurement from the photocell
  int reading  = analogRead(lightPin);
  // Convert the raw analog measurement to a discrete amount of LEDS
  int activeLEDS = reading / 57;  // Calculation: (1023/9)/2
  // Check if the currently active LEDS is exceeding the threshold, if so set to a maximum of 8 active LEDs
  if (activeLEDS > 8) activeLEDS = 8;
  // Reset the active LEDs pattern
  ledPattern = B00000000;
  // Activate the correct amount of LEDs based on the photocell reading
  for (int i = 0; i < activeLEDS; i++) {
    // Set the i'th bit of the LED pattern
    ledPattern = ledPattern + (1 << i);
  }
  // Update the serial to parallel converter with the new LED pattern
  updateShiftRegister();
}