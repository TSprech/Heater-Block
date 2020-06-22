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

  void print_temperature(float _temperature, float _setpoint, char _units);

  void print_pid_values(uint16_t _kp, uint16_t _ki, uint16_t _kd);

  void display();
  void clear();

 private:
  Adafruit_SSD1306 Display;

  void _splash_screen();
};

#endif