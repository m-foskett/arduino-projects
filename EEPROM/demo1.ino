// EEPROM Demo Test 1
void demo1 (void)
{
  // Char Arrays to write/read
  char company[7] = {"elegoo"};
  char company2[7] = {"0"};
  
  for(int i = 0 ; i < sizeof(company)/sizeof(company[0]); i++ ) {
    // Write to EEPROM
    EEPROM.write(i, company[i]);
  }

  for(int i = 0 ; i < sizeof(company2)/sizeof(company2[0]); i++ ) {
    // Read from EEPROM
    company2[i] = EEPROM.read(i);
  }
  // Print the read/write results to serial monitor
  Serial.print("Company 2: ");
  Serial.println(company2);
}
