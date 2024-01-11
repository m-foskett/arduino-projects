#ifndef MYSEGDISPLAY_H
#define MYSEGDISPLAY_H

#include <Arduino.h>

// Function Declarations
void shift_register_setup(const uint8_t latch, const uint8_t clock, const uint8_t data);
void digit_pins_setup(const uint8_t digit_1, const uint8_t digit_2, const uint8_t digit_3, const uint8_t digit_4);
void led_setup(const uint8_t led);
void display_num(uint16_t num);
void display(uint8_t num);
void choose_com(uint8_t com);
void choose_DIGIT_1();
void choose_DIGIT_2();
void choose_DIGIT_3();
void choose_DIGIT_4();
void clear_bit_display();
void clear_display();

#endif