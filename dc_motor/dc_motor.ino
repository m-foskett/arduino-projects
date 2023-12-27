// DC Motor

// Definitions
#define ENABLE_PIN 5
#define DIRECTION_A 3
#define DIRECTION_B 4
 
void setup() {
  // Setup the motor controller pins
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(DIRECTION_A, OUTPUT);
  pinMode(DIRECTION_B, OUTPUT);
  // Begin a serial connection with Baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Alternating Directions Example
  Serial.println("Alternating Directions Example");
  // Enable Motor 1
  digitalWrite(ENABLE_PIN, HIGH);
  for (int i = 0; i < 5; i++) {
    // Clockwise
    digitalWrite(DIRECTION_A, HIGH);
    digitalWrite(DIRECTION_B, LOW);
    delay(500);
    // Anti-clockwise
    digitalWrite(DIRECTION_A, LOW);
    digitalWrite(DIRECTION_B, HIGH);
    delay(500);
  }
  // Disable Motor 1
  digitalWrite(ENABLE_PIN,LOW);
  delay(2000);

  // Alternating Speeds Example
  Serial.println("Alternating Speeds Example");
  // Enable Motor 1
  digitalWrite(ENABLE_PIN, HIGH);
  // Clockwise
  digitalWrite(DIRECTION_A, HIGH);
  digitalWrite(DIRECTION_B, LOW);
  delay(3000);
  // Disable Motor 1 for a slow stop
  digitalWrite(ENABLE_PIN, LOW);
  delay(1000);
  // Enable Motor 1
  digitalWrite(ENABLE_PIN, HIGH);
  // Anti-clockwise
  digitalWrite(DIRECTION_A, LOW);
  digitalWrite(DIRECTION_B, HIGH);
  delay(3000);
  // Fast Stop
  digitalWrite(DIRECTION_A,LOW);
  delay(2000);

  // Adjusting Speed using PWM signal Example
  Serial.println("PWM Speed Adjustment Example");
  // Enable Motor 1
  analogWrite(ENABLE_PIN, 255);
  // Clockwise
  digitalWrite(DIRECTION_A,HIGH);
  digitalWrite(DIRECTION_B,LOW);
  delay(2000);
  // Reduce Speed
  analogWrite(ENABLE_PIN,180);
  delay(2000);
  // Reduce Speed
  analogWrite(ENABLE_PIN,128);
  delay(2000);
  // Reduce Speed
  analogWrite(ENABLE_PIN,50);
  delay(2000);
  // Increase Speed
  analogWrite(ENABLE_PIN,128);
  delay(2000);
  // Increase Speed
  analogWrite(ENABLE_PIN,180);
  delay(2000);
  // Increase Speed
  analogWrite(ENABLE_PIN,255);
  delay(2000);
  // Disable Motor 1
  digitalWrite(ENABLE_PIN,LOW);
  delay(10000);
}
   
