// 7-Segment Display

// LED Digit Patterns
// Serial To Parallel Converter Pins: Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7
// Segments: DP, A, B, C, D, E, F, G
byte seven_segment_patterns[10] = {
  B01111110, // = 0
  B00110000, // = 1
  B01101101, // = 2
  B01111001, // = 3
  B00110011, // = 4
  B01011011, // = 5
  B01011111, // = 6
  B01110000, // = 7
  B01111111, // = 8
  B01110011  // = 9
};
 
// Variable Definitions
int timeDelay = 1000; // 1000 milliseconds
int latchPin = 11; // ST_CP [RCK]
int clockPin = 9; // SH_CP [SCK]
int dataPin = 12; // DS [S1]
 
void setup() {
  // Setup the pins to be OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
 
// Function: sevensegmentWrite
//  Purpose: Takes a seven segment pattern of size byte and writes
//           the corresponding data to the shift register
//  Parameters: byte digit
//  Returns: N/A
void sevenSegmentWrite(byte digit) {
  // Set the latch pin to LOW before sending data
  digitalWrite(latchPin, LOW);
  // Shift the data out
  // Parameters:
  //  - Data Pin
  //  - Clock Pin
  //  - Which end of data to start at
  //  - Data to shift into the shift register
  shiftOut(dataPin, clockPin, LSBFIRST, seven_segment_patterns[digit]);
  // set the latch pin to HIGH after sending data
  digitalWrite(latchPin, HIGH);
}
 
void loop() {       
  // Count down from 9 to 0
  for(byte digit = 10; digit > 0; --digit) {
    // Add a delay between digit changes
    delay(timeDelay);
    // Display the current digit on the 7-Segment Display
    sevenSegmentWrite(digit - 1);
  }
}