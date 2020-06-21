#include <Arduino.h>

#ifndef THERMISTOR_H
#define THERMISTOR_H

class Thermistor {
 public:
  Thermistor(uint8_t _input_pin, uint32_t _nominal_resistance, uint32_t _series_resistance, float _nominal_temperature, uint16_t _beta_coefficient);
  float read_thermistor();
  float read_thermistor(char _units);
  void smooth_read_thermistor_number(uint8_t _number_of_reading);
  void update_thermistor_array();
  float average_thermistor_values();
  float thermistor_degree_value(float _thermistor_raw_input, char _units);
  float average_degree_value(char _units);

 private:
  uint8_t _current_reading = 0;
  float* _temperature_readings_array;

  uint8_t _number_of_readings;

  uint8_t _input_pin;                 // Analog input pin
  uint32_t _nominal_resistance;       // Thermistor resistance
  uint32_t _series_resistance;        // Reference resistor value
  float _nominal_temperature = 25.0;  // MUST BE IN DEGREES CELSIUS, Usually around room temp (25° C)
  uint16_t _beta_coefficient = 3950;  // Thermistor beta coefficient
};

#endif