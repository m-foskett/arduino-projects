// Liquid Crystal Display

/* Pinout
 * VDD: 5V
 * VSS: GND
 * VO: Pin 3
 * - Controlled by 10K Potentiometer
 * RS: Pin 7
 * R/W: GND
 * E(Enable): Pin 8
 * D0-3: Unused
 * D4: Pin 9
 * D5: Pin 10
 * D6: Pin 11
 * D7: Pin 12
 * A: 5V
 * K: GND
*/

#include <LiquidCrystal.h>

// Pinout Definitions
#define RS_PIN  7
#define E_PIN   8
#define D4_PIN  9
#define D5_PIN  10
#define D6_PIN  11
#define D7_PIN  12


// Instantiate an object of class LiquidCrystal with the pinout as described above
LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup() {
  // Set the number of columns and rows of the LCD
  lcd.begin(16, 2);
  // Print a message to the first row of the LCD
  lcd.print("LCD says Hello!");
}

void loop() {
  // Set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  // Print the seconds elapsed since last reset
  lcd.print(millis() / 1000);
}
