// Sound Sensor Module

/*
  LED1 - Power Indicator
  LED2 - Sound Input Indicator
  Input Sensitivity is adjusted by the potentiometer.
*/

// Variable Definitions
const int  sensorAnalogPin = A0;    // Analog Input Pin to accept analog output from the Sound Sensor 
const int  sensorDigitalPin = 3;    // Digital Input Pin to accept digital output from the Sound Sensor
const int  analogValue = 0;         // Analog sensor value
const int  digitalValue;            // Digital sensor value
const int  Led13 = 13;              // Define LED port 13; this is the LED built in to the Arduino (labled L)
                              

void setup(){
  // Begin serial connection with Baud Rate of 9600
  Serial.begin(9600);              
  // Set Pin 3 as Digital INPUT
  pinMode(sensorDigitalPin, INPUT);
  // Define LED13 as an OUTPUT port, to indicate digital trigger reached
  pinMode(Led13, OUTPUT);
}

void loop(){
  // Read the Analog Input value
  analogValue = analogRead(sensorAnalogPin);
  // Read the Digital Input value
  digitalValue = digitalRead(sensorDigitalPin);
  // Send the analog value to the serial transmit interface
  Serial.println(analogValue);
  // If Sound Sensor is sending a signal
  if(digitalValue == HIGH) {
    // Set LED L as HIGH
    digitalWrite(Led13, HIGH);
  }
  else {
    // Set LED L as LOW
    digitalWrite(Led13, LOW);
  }
  // Small delay for serial plotter to refresh
  delay(50);
}
