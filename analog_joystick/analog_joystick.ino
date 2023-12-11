// Analog Joystick

// Variable Definitions
const int Switch_pin = 2; // Digital pin connected to Switch output
const int X_pin = 0; // Analog pin connected to X output
const int Y_pin = 1; // Analog pin connected to Y output

void setup() {
  // Set the switch to INPUT
  pinMode(Switch_pin, INPUT);
  // Write HIGH to the switch
  digitalWrite(Switch_pin, HIGH);
  // Open up a serial connection with a Baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Print the measured values
  Serial.print("Switch:  ");
  Serial.print(digitalRead(Switch_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(1000);
}
