// Serial Monitor Device Control
//  - Using the serial monitor to control
//    a 7-Segment Display

// Variable Definitions
int timeDelay = 1000; // 1000 milliseconds
int latchPin = 11; // ST_CP [RCK]
int clockPin = 9; // SH_CP [SCK]
int dataPin = 12; // DS [S1]
byte currentSegments = B00000000; // Holds the pattern for the currently active segments

// Define a struct to store the segment character names and their bit patterns
typedef struct {
  char segmentName;
  byte segmentPattern;
  bool active;
} segment;
// Create an array of structs of type segment
segment seven_segment_patterns[9] = {
  {
    segmentName: 'P',
    segmentPattern: B10000000,
    active: false,
  },
  {
    segmentName: 'A',
    segmentPattern: B01000000,
    active: false,
  },
  {
    segmentName: 'B',
    segmentPattern: B00100000,
    active: false,
  },
  {
    segmentName: 'C',
    segmentPattern: B00010000,
    active: false,
  },
  {
    segmentName: 'D',
    segmentPattern: B00001000,
    active: false,
  },
  {
    segmentName: 'E',
    segmentPattern: B00000100,
    active: false,
  },
  {
    segmentName: 'F',
    segmentPattern: B00000010,
    active: false,
  },
  {
    segmentName: 'G',
    segmentPattern: B00000001,
    active: false,
  },
  {
    segmentName: 'X',
    segmentPattern: B00000000,
    active: false,
  }
};

// Function: sevensegmentWrite
//  Purpose: Takes a seven segment pattern of size byte and writes
//           the corresponding data to the shift register
//  Parameters: byte digit
//  Returns: N/A
void sevenSegmentWrite(byte activeSegmentPattern) {
  // Set the latch pin to LOW before sending data
  digitalWrite(latchPin, LOW);
  // Shift the data out
  // Parameters:
  //  - Data Pin
  //  - Clock Pin
  //  - Which end of data to start at
  //  - Data to shift into the shift register
  shiftOut(dataPin, clockPin, LSBFIRST, activeSegmentPattern);
  // set the latch pin to HIGH after sending data
  digitalWrite(latchPin, HIGH);
}

void setup() {
  // Setup the pins to be OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  // Set all the segments to be initially cleared
  sevenSegmentWrite(B00000000);
  // Begin a serial connection with Baud rate of 9600
  Serial.begin(9600);
  Serial.println("Enter a segment from 'A' - 'G', 'P' for the dot or 'X' to clear.");
}

void loop() {
  // Check if a serial connection is active and the serial buffer has stored data
  if (Serial.available()) {
    // Read the serial buffer for the user input
    char userInput = Serial.read();
    // Check if the user's input is a valid segment
    if (userInput == 'A' || userInput == 'B' || userInput == 'C' || userInput == 'D' || userInput == 'E' || userInput == 'F' || userInput == 'G' || userInput == 'P') {
      // Search array of structs for matching segment name
      for (int i = 0; i <= sizeof(seven_segment_patterns)/sizeof(segment); i++) {
        if (userInput == seven_segment_patterns[i].segmentName && seven_segment_patterns[i].active != true) {
          // Update the currently active segments pattern
          currentSegments += seven_segment_patterns[i].segmentPattern;
          // Mark the newly added segment as active
          seven_segment_patterns[i].active = true;
        }
      }
      // Display the current active segments
      sevenSegmentWrite(currentSegments);
      // Give the user feedback on the updated segment
      Serial.print("Turned on segment ");
      Serial.println(userInput);
      Serial.print("Current Active Segment Pattern: ");
      Serial.println(currentSegments);
    }
    // Check if the user is trying to clear all the segments
    if (userInput == 'X') {
      // Clear all the segments
      currentSegments = B00000000;
      sevenSegmentWrite(currentSegments);
      // Mark the segments as inactive
      for (int i = 0; i <= sizeof(seven_segment_patterns)/sizeof(segment); i++) {
        seven_segment_patterns[i].active = false;
      }
      Serial.println("Cleared");
    }
  }
}