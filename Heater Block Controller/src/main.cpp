#include <Arduino.h>
#include <Button_Handler.h>
#include <OLED.h>

OLED OLED(132, 32, -1);
Button_Handler Buttons(3, 4, 5);

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Buttons.button_setup();

  if (OLED.begin_display(0x3C)) {
  }

  OLED.clear();
  OLED.print_temperature(24.31, 27.25, 'C');
  OLED.print_pid_values(2, 6, 1);
  OLED.display();
}

void loop() {
  uint8_t pressed_button = Buttons.button_read();
  if (pressed_button != -1) {
    switch (pressed_button) {
      case 0:
        OLED.clear();
        OLED.print_temperature(000.00, 000.00, 'C');
        OLED.display();
        break;
      case 1:
        OLED.clear();
        OLED.print_temperature(111.11, 111.11, 'F');
        OLED.display();
        break;
      case 2:
        OLED.clear();
        OLED.print_temperature(222.22, 222.22, 'K');
        OLED.display();
        break;
      default:
        break;
    }
  }
}
Thermistor Thermistor(A0, 100000, 100000, 25, 3950);
  Thermistor.smooth_read_thermistor_number(7);
  Thermistor.update_thermistor_array();
  Thermistor.check_safety_temperature();
#include <Thermistor.h>