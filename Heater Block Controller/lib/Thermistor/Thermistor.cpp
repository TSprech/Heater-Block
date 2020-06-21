#include "Thermistor.h"

#include <Arduino.h>

// Constructor to assign all constants for temperature calculations
Thermistor::Thermistor(uint8_t _input_pin, uint32_t _nominal_resistance, uint32_t _series_resistance, float _nominal_temperature, uint16_t _beta_coefficient) {
  this->_input_pin = _input_pin;
  this->_nominal_resistance = _nominal_resistance;
  this->_series_resistance = _series_resistance;
  this->_nominal_temperature = _nominal_temperature;
  this->_beta_coefficient = _beta_coefficient;
}

// Read and return the raw value from ADC
float Thermistor::read_thermistor() {
  float _thermistor_raw = analogRead(_input_pin);
  return _thermistor_raw;
}

// Read and return the temperature value in specified units
float Thermistor::read_thermistor(char _units) {  // _units can be C, F, or K
  float _thermistor_raw = analogRead(_input_pin);
  return thermistor_degree_value(_thermistor_raw, _units);
}

// Sets the number of readings to be used when averaging values
void Thermistor::smooth_read_thermistor_number(uint8_t _number_of_readings) {
  this->_number_of_readings = _number_of_readings - 1;  // Adjust for 0 index
  _temperature_readings_array = new float[_number_of_readings];
}

// A rolling temperature reading that updates a single array value each cycle through the main loop
void Thermistor::update_thermistor_array() {
  _temperature_readings_array[_current_reading] = read_thermistor();  // Update the array value with the current temperature reading

  // Increment or reset the current reading number depending on current value
  if (_current_reading >= _number_of_readings) {
    _current_reading = 0;
  } else {
    _current_reading++;
  }
}

float Thermistor::average_thermistor_values() {
  float _average = 0;

  // Cycle through and average the thermistor values
  for (uint8_t lcv = 0; lcv < _number_of_readings; lcv++) {
    _average += _temperature_readings_array[lcv];
  }
  _average /= _number_of_readings;
  return _average;
}

// Convertert resistance to 3 different units
float Thermistor::thermistor_degree_value(float _thermistor_raw_input, char _units) {  // _units can be C, F, or K
  float _thermistor_raw = _thermistor_raw_input;

  // Formula from Adafruit Thermistor Guide
  _thermistor_raw = 1023 / _thermistor_raw - 1;
  _thermistor_raw = _series_resistance / _thermistor_raw;

  float steinhart;
  steinhart = _thermistor_raw / _nominal_resistance;   // (R/Ro)
  steinhart = log(steinhart);                          // ln(R/Ro)
  steinhart /= _beta_coefficient;                      // 1/B * ln(R/Ro)
  steinhart += 1.0 / (_nominal_temperature + 273.15);  // + (1/To)
  steinhart = 1.0 / steinhart;                         // Invert
  steinhart -= 273.15;                                 // convert to C

  if (_units == 'C' || _units == 'c') {  // Celsius
    return steinhart;
  } else if (_units == 'F' || _units == 'f') {  // Fahrenheit
    return (steinhart * 1.8 + 32);
  } else if (_units == 'K' || _units == 'k') {  // Kelvin
    return (steinhart - 273.15);
  } else {  // Invalid character
    return NULL;
  }
}

// Combines averaging and resistance to units into one call, returns thermistor value in specified units
float Thermistor::average_degree_value(char _units) {  // _units can be C, F, or K
  float _average_raw = average_thermistor_values();
  return (thermistor_degree_value(_average_raw, _units));
}