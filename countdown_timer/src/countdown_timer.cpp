// Countdown Timer
#include <Arduino.h>

#include "avr8-stub.h"
#include "app_api.h" // only needed with flash breakpoints

#include "MyTimer.h"
// #include "PinChangelnt.h"
#include "MsTimer2.h"
#include "MsTimer1.h"
#include <MsTimer1.h>
#include <MsTimer2.h>

#include "MySegDisplay.h"
#include "button.h"
#include "buzzer.h"

void setup()
{
  // initialize GDB stub
  // debug_init();
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

  // MCU_timer_interrupt_init(150 ,1060); //set timer1 0.15s  timer2 1s
  // clear_display();
}

void loop()
{
  digitalWrite(BUZZER, HIGH);
  // display_num(number);
  //
  // clear_display();
  // time_out();
}
