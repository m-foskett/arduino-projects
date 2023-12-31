// Function: buzzer_setup
//  - Purpose:
//    - Setup the pin to control the Active Buzzer as OUTPUT
//  - Returns:
//    - void
void buzzer_setup(const uint8_t buzzer) {
  pinMode(buzzer, OUTPUT);
}

void time_out()
{
  while(flag_begin && number == 0)
   {
     delay(100);
     digitalWrite(BUZZER, HIGH); 
     digitalWrite(LED, LOW);
     delay(100);
     digitalWrite(BUZZER, LOW);
     delay(100);
     digitalWrite(LED, HIGH);
   }    
}
