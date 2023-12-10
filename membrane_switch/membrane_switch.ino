// Membrane Switch - Matrix Keypad
#include <Keypad.h>

// Variable Definitions
const byte ROWS = 4; // Number of rows
const byte COLS = 4; // Number of cols

// 2D Array Keypad Definition
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Pinouts of the keypad
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};

// Create an instance of the class Keypad
Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  // Open a serial connection with Baud rate of 9600
  Serial.begin(9600);
}
  
void loop(){
  // Acquire the keypad press from the user
  char customKey = myKeypad.getKey();
  
  if (customKey){
    // Print the acquired keypad press to the serial monitor
    Serial.println(customKey);
  }
}
