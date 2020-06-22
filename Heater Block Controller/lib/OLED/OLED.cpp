#include "OLED.h"

#include <Arduino.h>

#include "Splash_Screen.cpp"

// Constructor to assign all constants for temperature calculations
OLED::OLED(uint8_t _screen_width, uint8_t _screen_height, uint8_t _reset_pin) {
  Adafruit_SSD1306 Display(_screen_width, _screen_height, &Wire, _reset_pin);
}

bool OLED::begin_display(byte address) {
  if (Display.begin(SSD1306_SWITCHCAPVCC, address)) {  // Default address is 0x3C
    _splash_screen();
    return true;
  } else {
    return false;
  }
}

void OLED::print_temperature(float _temperature, float _setpoint, char _units) {
  Display.setTextSize(2);
  Display.setTextColor(WHITE);

  //Current temperature printing
  Display.setCursor(0, 0);
  Display.print(F(_temperature));
  Display.print((char) 247);
  Display.print(F(_units));

  //Setpoint printing
  Display.setCursor(0, 16);
  Display.print(F(_setpoint));
  Display.print((char) 247);
  Display.print(F(_units));
}

void OLED::print_pid_values(uint16_t _kp, uint16_t _ki, uint16_t _kd) {
  const uint8_t _x_offset = 90;
  Display.setTextSize(1);
  Display.setTextColor(WHITE);

  Display.setCursor(_x_offset, 0);
  Display.print(F("Kp:"));
  Display.print(F(_kp));
  Display.setCursor(_x_offset, 11);
  Display.print(F("Ki:"));
  Display.print(F(_ki));
  Display.setCursor(_x_offset, 22);
  Display.print(F("Kd:"));
  Display.print(F(_kd));
}

void OLED::display() {
  Display.display();
}

void OLED::clear() {
  Display.clearDisplay();
}

void OLED::_splash_screen() {
  Display.display();
  Display.clearDisplay();

  Display.drawBitmap(0, 0, splash_screen, 128, 32, WHITE);

  Display.display();
  delay(2000);
}