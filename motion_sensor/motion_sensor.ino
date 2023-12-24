// Motion Sensor

// Variable Definitions
// Use the LED on Pin 13 as a motion indicator
const int motionDetectedPin = 13;
// Motion Sensor Input Pin
int motionInputPin = 7;
// Detected PIR value
int pirValue;


void setup() {
  // Setup the input and output pins
  pinMode(motionDetectedPin, OUTPUT);
  pinMode(motionInputPin, INPUT);
  // Write LOW initially to the motion indicator LED
  digitalWrite(motionDetectedPin, LOW);
}

void loop() {
  // Read the Input pin for potential motion detection
  pirValue = digitalRead(motionInputPin);
  // Set the indicator to the appropriate value (LOW for no motion, HIGH for motion detected)
  digitalWrite(motionDetectedPin, pirValue);
}
