// Active Buzzer

// Variable Definitions
int buzzer = 12; // Active Buzzer on Pin 12

void setup()
{
  pinMode(buzzer, OUTPUT); // Set the buzzer pin as an OUTPUT
}

void loop()
{
  int sound_duration = 500; // 500 milliseconds sound duration

  for (int i = 0; i < 20; i++)
  {
    // Lower the duration of the sound as iterations increase
    sound_duration = (21 - i) * 25;

    // Activate the active buzzer for the specified duration
    digitalWrite(buzzer, HIGH);
    delay(sound_duration);

    // Deactivate the active buzzer for the specified duration
    digitalWrite(buzzer, LOW);
    delay(sound_duration);
  }
}
