#ifndef MYTIMER_H
#define MYTIMER_H

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

static int time_select_button{0};
static int time_seconds_button{0};
static int time_milliseconds_button{0};

static int time_timer{0};

static int last_time_select_button{0};
static int last_time_seconds_button{0};
static int last_time_milliseconds_button{0};

static uint16_t flag_begin = {1};

static uint16_t number = {0};

const static uint8_t num_buf[] = {
    0x3f,
    0x06,
    0x5b,
    0x4f,
    0x66,
    0x6d,
    0x7d,
    0x07,
    0x7f,
    0x6f};

#endif
