#include <Arduino.h>

#ifndef TIMER_H
#define TIMER_H

class Timer {
 public:
  Timer();
  bool check_time(uint32_t _delay_time);

 private:
  unsigned long _previous_milliseconds;
  unsigned long _current_milliseconds;
};

#endif