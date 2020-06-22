#include <Arduino.h>
#include <OLED.h>

OLED OLED(132, 32, -1);

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  if (OLED.begin_display(0x3C)) {

  }

  OLED.print_temperature(2, 24.3, 'C');
  OLED.print_setpoint(2, 26.0, 'C');
}

void loop() {
}