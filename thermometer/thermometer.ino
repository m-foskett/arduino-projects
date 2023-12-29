// Thermometer

/* Pinout
 * VDD: 5V
 * VSS: GND
 * VO: Controlled by 10K Potentiometer
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

// Variable Definitions
const int temperaturePin = 0;

// Instantiate an object of class LiquidCrystal with the pinout as described above
LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup()
{
  // Set the number of columns and rows of the LCD
  lcd.begin(16, 2);
}

void loop()
{
  // Reading analogue value from thermistor
  int tempReading = analogRead(temperaturePin);

  // Converting analogue reading into a temperature to display
  // Kelvin Calculation
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );
  // Convert Kelvin to Celcius
  float tempC = tempK - 273.15;
  // Convert Celcius to Fahrenheit
  float tempF = (tempC * 9.0)/ 5.0 + 32.0;

  // Display Temperature in Celsius
  lcd.setCursor(0, 0);
  lcd.print("Temp         C  ");
  lcd.setCursor(6, 0);
  lcd.print(tempC);
  delay(500);
}
