#include <Arduino.h>
#include <Button_Handler.h>
#include <OLED.h>
#include <Thermistor.h>
#include <Timer.h>

static const uint8_t INCREMENT = 2;

unsigned long previous_milliseconds = 0;

OLED OLED(132, 32, -1);
Button_Handler Buttons(3, 4, 5);
Thermistor Thermistor(A0, 100000, 100000, 25, 3950);
Timer Timer;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Thermistor.smooth_read_thermistor_number(7);

  Buttons.button_setup();

  if (OLED.begin_display(0x3C)) {
  }
}

void loop() {
  Thermistor.update_thermistor_array();

  if (Timer.check_time(50)) {
    float new_setpoint = Buttons.adjust_value(Thermistor.get_setpoint(), INCREMENT);
    if (new_setpoint == -1) {
      //Invert heater logic
    } else {
      Thermistor.set_new_setpoint(new_setpoint);
    }
  }

  if (Timer.check_time(5)) {
    OLED.clear();
    OLED.print_temperature(Thermistor.average_degree_value('C'), Thermistor.get_setpoint(), 'C');
    OLED.display();
  }
}