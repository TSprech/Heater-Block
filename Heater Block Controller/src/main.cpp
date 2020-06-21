#include <Arduino.h>
#include <Thermistor.h>

Thermistor Thermistor(A0, 100000, 100000, 25, 3950);

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Thermistor.smooth_read_thermistor_number(7);
}

void loop() {
  Thermistor.update_thermistor_array();
  Thermistor.check_safety_temperature();
}