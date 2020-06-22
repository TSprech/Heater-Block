#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

#ifndef OLED_H
#define OLED_H

class OLED {
 public:
  OLED(uint8_t _screen_width, uint8_t _screen_height, uint8_t _reset_pin);
  bool begin_display(byte address);

  void print_temperature(uint8_t _size, float _temperature, char _units);
  void print_setpoint(uint8_t _size, float _setpoint, char _units);

  void print_numbers(float _print_value);
  void print_numbers(int _print_value);

 private:
  Adafruit_SSD1306 Display;

  void _splash_screen();
};

#endif