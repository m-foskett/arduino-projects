#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

// Function Declarations
void control_buttons_setup(const uint8_t select_button, const uint8_t seconds_button, const uint8_t milliseconds_button);
void control_buttons_interrupt_setup(const uint8_t select_button, const uint8_t seconds_button, const uint8_t milliseconds_button);
void seconds_button_interrupt();
void milliseconds_button_interrupt();
void select_button_interrupt();

#endif