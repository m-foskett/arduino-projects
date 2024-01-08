// Countdown Timer

// Shift Register Pinout
#define DATA 12
#define LATCH 11
#define CLOCK 9
// Four Digit Seven Segment Display Digit Control Pinout
#define DIGIT_1 2
#define DIGIT_2 3
#define DIGIT_3 4
#define DIGIT_4 5
// Control Button Pinout
#define SELECT_BUTTON A1
#define SECONDS_BUTTON A3
#define MILLISECONDS_BUTTON 6
// Buzzer Pinout
#define BUZZER A2
// LED Pinout
#define LED A0

#include "PinChangelnt.h"
#include "MsTimer2.h"
#include "MsTimer1.h"
#include "MyTimer.h"

void setup() {
  // Setup the 74HC95 Shift Register pins
  shift_register_setup(LATCH, CLOCK, DATA);
  // Setup the Digit Control pins of the 4-digit-7-segment display
  digit_pins_setup(DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4);
  // Setup the Control Buttons of the timer
  control_buttons_setup(SELECT_BUTTON, SECONDS_BUTTON, MILLISECONDS_BUTTON);
  // Attach Pin Change Interrupts to the pins of Control Buttons
  control_buttons_interrupt_setup(SELECT_BUTTON, SECONDS_BUTTON, MILLISECONDS_BUTTON);
  // Setup the pin to control the Active Buzzer as OUTPUT
  buzzer_setup(BUZZER);
  // Setup LED pin
  led_setup(LED);
  
  MCU_timer_interrupt_init(150 ,1060); //set timer1 0.15s  timer2 1s
  clear_display();
}

void loop() {
//  display_num(number);
  // clear_display();
 time_out();
}
