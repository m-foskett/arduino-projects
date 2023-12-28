// EEPROM Testing

#include <EEPROM.h>

void setup() {
  // Begin a serial connection with Baud rate of 9600
  Serial.begin(9600);
  // EEPROM Demo 1: Byte Sized or less data type
  demo1();


  // EEPROM Demo 2: Greater than Byte Size data type

  // Float Type
  float a = 3.14;
  float a2 = 0;
  // Write the float type to EEPROM
  EEPROM_write(a, 0);
  // Read the float data from EEPROM and write to serial monitor
  Serial.print("float a2: ");
  Serial.println(EEPROM_read(a2, 0));

  // Date String
  char d1[50] = __DATE__;
  char d2[50] = "0";
  EEPROM_write(d1, 0);
  Serial.print("Date String: ");
  Serial.println(EEPROM_read(d2, 0));
}

void loop() 
{
 
}
