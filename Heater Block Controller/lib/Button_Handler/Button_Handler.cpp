/*Created May 2020 by Trey Sprecher.

Licensed under the GPL, Version 3.0 (the "License");
software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/

#include "Button_Handler.h"

#include <Arduino.h>

Button_Handler::Button_Handler(uint8_t _pin_0, uint8_t _pin_1, uint8_t _pin_2) {
  this->_pin_0 = _pin_0;
  this->_pin_1 = _pin_1;
  this->_pin_2 = _pin_2;
}

void Button_Handler::button_setup() {
  pinMode(_pin_0, INPUT_PULLUP);
  pinMode(_pin_1, INPUT_PULLUP);
  pinMode(_pin_2, INPUT_PULLUP);
}

int8_t Button_Handler::button_read() {
  if (digitalRead(_pin_0) == false) {
    return (0);
  }

  else if (digitalRead(_pin_1) == false) {
    return (1);
  }

  else if (digitalRead(_pin_2) == false) {
    return 2;
  } else {
    return -1;
  }
}

float Button_Handler::adjust_value(float _current_value, float _increment) {
  float _current = _current_value;
  uint8_t pressed_button = button_read();

  if (pressed_button != -1) {
    switch (pressed_button) {
      case 0:
        _current += _increment;
        return _current;
        break;

      case 1:
        _current -= _increment;
        return _current;
        break;

      case 2:
        return -1;
        break;

      default:
        break;
    }
  }
}