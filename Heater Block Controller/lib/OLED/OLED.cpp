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

void OLED::print_temperature(uint8_t _size, float _temperature, char _units) {
  Display.clearDisplay();
  Display.setTextSize(_size);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 0);
  Display.print(F(_temperature));
  Display.print((char) 247);
  Display.print(F(_units));
  Display.display();
}

void OLED::print_setpoint(uint8_t _size, float _setpoint, char _units) {
  Display.setTextSize(_size);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 16);
  Display.print(F(_setpoint));
  Display.print((char) 247);
  Display.print(F(_units));
  Display.display();
}

void OLED::print_numbers(float _print_value) {
}

void OLED::_splash_screen() {
  Display.display();
  Display.clearDisplay();

  Display.drawBitmap(0, 0, splash_screen, 128, 32, WHITE);

  Display.display();
  delay(2000);
}