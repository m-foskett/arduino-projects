// Relay - Motor Control

// Pinout Definitions 
#define ENABLE 5
#define DIRECTION_A 3
#define DIRECTION_B 4

void setup() {
  // Setup motor controller pins as OUTPUT
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRECTION_A, OUTPUT);
  pinMode(DIRECTION_B, OUTPUT);
  // Begin a serial connection with Baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Enable Motor 1
  digitalWrite(ENABLE, HIGH);
  // Spin Motor 1
  Serial.println("Spin Motor 1");
  digitalWrite(DIRECTION_A, HIGH);
  digitalWrite(DIRECTION_B, LOW);
  delay(2000);
  // Stop Motor 1
  Serial.println("Stop Motor 1");
  digitalWrite(DIRECTION_A, LOW);
  digitalWrite(DIRECTION_B, HIGH);
  delay(2000);
}
