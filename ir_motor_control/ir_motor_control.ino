// Stepper Motor Control with IR Remote

#include "IRremote.h"
#include "Stepper.h"

// Variable Definitions and Pinout
// Steps per revolution of internal shaft
const int stepsPerRevolution = 2048;
const int rpm = 500;
int steps = 32;
// IR Receiver Signal Pin
int receiverSignal = 12 ;
// Time delay between subsequent step frequency changes
int timeDelay = 2000;

// Instantiate an object of class Stepper
Stepper myStepper(steps, 8, 10, 9, 11);
// Instantiate an object of class IRrecv
IRrecv irrecv(receiverSignal);

// Define a struct to store the IR codes and their corresponding steps/revolution
typedef struct {
  IRRawDataType ir_code;
  int steps;
} step_code;
// Create an array of structs of type step_map
step_code step_map[8] = {
  {
    ir_code: 0xF30CFF00,
    steps: 256,
  },
  {
    ir_code: 0xE718FF00,
    steps: 512,
  },
  {
    ir_code: 0xA15EFF00,
    steps: 768,
  },
  {
    ir_code: 0xF708FF00,
    steps: 1024,
  },
  {
    ir_code: 0xE31CFF00,
    steps: 1280,
  },
  {
    ir_code: 0xA55AFF00,
    steps: 1536,
  },
  {
    ir_code: 0xBD42FF00,
    steps: 1792,
  },
  {
    ir_code: 0xAD52FF00,
    steps: 2048,
  }
};

void setup()
{ 
  // Set the speed of the stepper motor
  myStepper.setSpeed(rpm);
  // Enable the IR receiver
  irrecv.enableIRIn();
  // Open serial connection with Baud Rate of 9600
  Serial.begin(9600);
  Serial.println("Stepper Motor Control with IR Remote");
}

void loop()
{
  // Look for an IR signal
  if (irrecv.decode()) {
    // Loop through the map of IR_codes
    for(int i = 0; i < sizeof(step_map)/sizeof(step_code); i++) {
      // Check if the decoded IR code is within the accepted values
      if(irrecv.decodedIRData.decodedRawData == step_map[i].ir_code) {
        // Output the IR code on the serial monitor
        Serial.print("IR code:0x");
        Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
        // Set the corresponding steps/revolution value
        myStepper.setSpeed(rpm);
        myStepper.step(step_map[i].steps);
        delay(timeDelay); 
        break;
      }
    }
    // Prepare to receive the next value
    irrecv.resume();
    // Write LOW to all four stepper motor signals
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);       
  }
}