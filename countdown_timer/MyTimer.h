#ifndef MYTIMER_H
#define MYTIMER_H

void time_out();

static int time_select_button = 0;
static int time_seconds_button = 0;
static int time_milliseconds_button = 0;

static int time_timer=0;

static int last_time_select_button = 0;
static int last_time_seconds_button = 0;
static int last_time_milliseconds_button = 0;

static uint16_t flag_begin = 0;

static uint16_t number = 0;

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
  0x6f
};

#endif
