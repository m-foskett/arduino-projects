// Serial to Parallel Converter

// Variable Definitions
int timeDelay = 500; // 500 milliseconds
int latchPin = 11; // ST_CP [RCK]
int clockPin = 9; // SH_CP [SCK]
int dataPin = 12; // DS [S1]

// Holds the pattern of LEDs currently turned on
byte leds = 0;

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
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  // Set the latch pin back to HIGH
  digitalWrite(latchPin, HIGH);
}

void setup() 
{
  // Setup the pins to be OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  // Turn all the LEDs off
  leds = 0;
  // Update the LED pattern within the shift register
  updateShiftRegister();
  // Half second pause
  delay(timeDelay);
  // Count from 0-7
  for (int i = 0; i < 8; i++) {
    bitSet(leds, i); // Set the bit that controls the current LED
    updateShiftRegister(); // Update shift register to reflect change
    delay(timeDelay); // Half second delay
  }
}
