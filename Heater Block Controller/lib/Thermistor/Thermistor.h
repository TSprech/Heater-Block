#include <Arduino.h>

#ifndef THERMISTOR_H
#define THERMISTOR_H

class Thermistor {
 public:
  Thermistor(uint8_t _input_pin, uint32_t _nominal_resistance, uint32_t _series_resistance, float _nominal_temperature, uint16_t _beta_coefficient);

  void safety_temperature(uint16_t _safety_temperature_limit, uint16_t _lookback_length);
  bool check_safety_temperature(uint16_t _current_temperature);
  void set_max_lookback_variance(uint16_t _max_variance);
  void set_lookback_read_time(int _lookback_read_time);

  float read_thermistor();
  float read_thermistor(char _units);
  void smooth_read_thermistor_number(uint8_t _number_of_reading);
  void update_thermistor_array();

  float average_thermistor_values();
  float thermistor_degree_value(float _thermistor_raw_input, char _units);
  float average_degree_value(char _units);

  void set_new_setpoint(float _new_setpoint);
  float get_setpoint();

 private:
  void _update_safety_array(uint16_t _new_raw_temperature);

  uint16_t _safety_temperature_limit = 0;
  uint16_t *_safety_temperature_array;
  uint16_t _max_variance = 5;
  uint16_t _lookback_length;
  int _lookback_read_time = 1000;
  uint16_t _lookback_current_reading = 0;
  unsigned long _previous_milliseconds = 0;

  uint8_t _current_reading = 0;
  float *_temperature_readings_array;

  uint8_t _number_of_readings;

  uint8_t _input_pin;                 // Analog input pin
  uint32_t _nominal_resistance;       // Thermistor resistance
  uint32_t _series_resistance;        // Reference resistor value
  float _nominal_temperature = 25.0;  // MUST BE IN DEGREES CELSIUS, Usually around room temp (25° C)
  uint16_t _beta_coefficient = 3950;  // Thermistor beta coefficient

  float _current_setpoint = 0;
};

#endif