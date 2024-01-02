// Four-Digit Seven-Segment Display

// Variable Definitions
int timeDelay = 200; // 500 milliseconds
int latchPin = 11; // ST_CP [RCK]
int clockPin = 9; // SH_CP [SCK]
int dataPin = 12; // DS [S1]

// Character/Digit Table
unsigned char symbolTable[] = {
  0x3f,
  0x06,
  0x5b,
  0x4f,
  0x66,
  0x6d,
  0x7d,
  0x07,
  0x7f,
  0x6f,
  0x77,
  0x7c,
  0x39,
  0x5e,
  0x79,
  0x71,
  0x00
};

void setup() {
  // Setup the pins to be OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void Display(int element) {
  // Set the latch pin to LOW before sending data
  digitalWrite(latchPin, LOW);
  // Shift the data out
  // Parameters:
  //  - Data Pin
  //  - Clock Pin
  //  - Which end of data to start at
  //  - Data to shift into the shift register
  shiftOut(dataPin, clockPin, MSBFIRST, symbolTable[element]);
  // Set the latch pin to HIGH after sending data
  digitalWrite(latchPin, HIGH);
}

void loop() {
  // Loop through the symbol table and display all symbols
  for(int i = 0; i < sizeof(symbolTable)/sizeof(unsigned char); i++) {
    Display(i);
    delay(timeDelay);
  }
}