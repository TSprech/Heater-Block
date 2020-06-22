/*Created May 2020 by Trey Sprecher.

Licensed under the GPL, Version 3.0 (the "License");
software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/

#include <Arduino.h>

#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

class Button_Handler {
 public:
  Button_Handler(uint8_t _pin_0, uint8_t _pin_1, uint8_t _pin_2);  // Setup for pins used for buttons and LEDs
  void button_setup();                                                                                             // Sets pinMode for each pin
  int8_t button_read();                                                                                           // Read each button pin and return if any are pressed

 private:
  // Pins used for IO
  uint8_t _pin_0;
  uint8_t _pin_1;
  uint8_t _pin_2;
};

#endif