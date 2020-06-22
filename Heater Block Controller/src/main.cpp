#include <Arduino.h>
#include <OLED.h>

OLED OLED(132, 32, -1);

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  if (OLED.begin_display(0x3C)) {

  }

  OLED.clear();
  OLED.print_temperature(24.31, 27.25, 'C');
  OLED.print_pid_values(2, 6, 1);
  OLED.display();
}

void loop() {
}