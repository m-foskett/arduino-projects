#include <Arduino.h>

#include "MsTimer2.h"
#include "MsTimer1.h"
#include "MyTimer.h"

// Function Declarations
void MCU_timer_interrupt_init(unsigned long time1, unsigned long time2);
void timer1_interrupt();
void timer2_interrupt();

void MCU_timer_interrupt_init(unsigned long time1, unsigned long time2)
{
  MsTimer2::set(time2, timer2_interrupt); // 100ms period
  MsTimer2::start();

  MsTimer1::set(time1, timer1_interrupt); // 100ms period
  MsTimer1::start();
}

void timer1_interrupt()
{
  time_timer = millis();

  if (!digitalRead(MILLISECONDS_BUTTON) && 1000 < (abs(time_milliseconds_button - time_timer)))
  {
    number += 1;
    if (number % 100 == 60 && number != 60)
      number = number / 100 * 100 + 100;

    if (number == 60)
      number = 100;
  }

  if (!digitalRead(SECONDS_BUTTON) && 1000 < (abs(time_seconds_button - time_timer)))
  {
    number += 100;
  }
}

void timer2_interrupt()
{
  if (flag_begin)
  {
    if (number > 9999)
      number = 9999;

    if (number % 100 > 60)
      number = number / 100 * 100 + 59;

    if (number > 0)
      number--;

    if (number > 9999)
      number = 9999;

    if (number % 100 > 60)
      number = number / 100 * 100 + 59;
  }
}
