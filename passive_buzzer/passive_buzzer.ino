#include "pitches.h"
 
// Variable Definitions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Melody: Array of Notes
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
// Note Duration: 500 milliseconds
int duration = 500;
// Buzzer Pin
int buzzerPin = 8;
 
void setup() {
 
}
 
void loop() {  
  for (int currentNote = 0; currentNote < sizeof(melody)/sizeof(int); currentNote++) {
    // Play the current note
    tone(buzzerPin, melody[currentNote], duration);
    // Delay between notes
    delay(1000);
  }
  // Restart the melody after delay
  delay(2000);
}
