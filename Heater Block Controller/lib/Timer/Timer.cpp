#include "Timer.h"

#include <Arduino.h>

Timer::Timer(){};

bool Timer::check_time(uint32_t _delay_time) {
  _current_milliseconds = millis();
  if (_current_milliseconds - _previous_milliseconds >= _delay_time) {
    _previous_milliseconds = _current_milliseconds;
    return true;
  } else {
    return false;
  }
}