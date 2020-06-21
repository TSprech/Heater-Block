#include <Arduino.h>

#include <PID_v1.h>
#include <Thermistor.h>

#define PIN_OUTPUT 2
#define PIN_MIRROR 3

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Define the aggressive and conservative Tuning Parameters
double aggKp = 90, aggKi = 30, aggKd = 80;
double consKp = 45, consKi = 15, consKd = 40;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);

Thermistor Thermistor(A0, 100000, 100000, 25, 3950);

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Thermistor.smooth_read_thermistor_number(7);

  //Setpoint = 50;

  //turn the PID on
  //myPID.SetMode(AUTOMATIC);
}

void loop() {
  Thermistor.update_thermistor_array();

  Serial.print("Average Degree Value: ");
  Serial.print(Thermistor.average_degree_value('C'));
  Serial.print("  Read Thermistor: ");
  Serial.print(Thermistor.read_thermistor('C'));
  Serial.print("  Read Thermistor Raw: ");
  Serial.print(Thermistor.read_thermistor());
  Serial.println();

  delay(100);

  // double gap = abs(Setpoint - Input);  //distance away from setpoint
  // if (gap < 10) {                      //we're close to setpoint, use conservative tuning parameters
  //   myPID.SetTunings(consKp, consKi, consKd);
  //   Serial.print(" Conservative PID ");
  // } else {
  //   //we're far from setpoint, use aggressive tuning parameters
  //   myPID.SetTunings(aggKp, aggKi, aggKd);
  //   Serial.print(" Aggressive PID ");
  // }

  // myPID.Compute();
  // Serial.print("Output: ");
  // Serial.println(Output);
  // analogWrite(PIN_OUTPUT, Output);
  // analogWrite(PIN_MIRROR, Output);
}























// Thermistor Example #3 from the Adafruit Learning System guide on Thermistors 
// https://learn.adafruit.com/thermistor/overview by Limor Fried, Adafruit Industries
// MIT License - please keep attribution and consider buying parts from Adafruit

// // which analog pin to connect
// #define THERMISTORPIN A0         
// // resistance at 25 degrees C
// #define THERMISTORNOMINAL 100000      
// // temp. for nominal resistance (almost always 25 C)
// #define TEMPERATURENOMINAL 25   
// // how many samples to take and average, more takes longer
// // but is more 'smooth'
// #define NUMSAMPLES 5
// // The beta coefficient of the thermistor (usually 3000-4000)
// #define BCOEFFICIENT 3950
// // the value of the 'other' resistor
// #define SERIESRESISTOR 100000    

// int samples[NUMSAMPLES];

// void setup(void) {
//   Serial.begin(9600);
//   //analogReference(EXTERNAL);
// }

// void loop(void) {
//   uint8_t i;
//   float average;

//   // take N samples in a row, with a slight delay
//   for (i=0; i< NUMSAMPLES; i++) {
//    samples[i] = analogRead(THERMISTORPIN);
//    delay(10);
//   }
  
//   // average all the samples out
//   average = 0;
//   for (i=0; i< NUMSAMPLES; i++) {
//      average += samples[i];
//   }
//   average /= NUMSAMPLES;

//   Serial.print("Average analog reading "); 
//   Serial.println(average);
  
//   // convert the value to resistance
//   average = 1023 / average - 1;
//   average = SERIESRESISTOR / average;
//   Serial.print("Thermistor resistance "); 
//   Serial.println(average);
  
//   float steinhart;
//   steinhart = average / THERMISTORNOMINAL;     // (R/Ro)
//   steinhart = log(steinhart);                  // ln(R/Ro)
//   steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
//   steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
//   steinhart = 1.0 / steinhart;                 // Invert
//   steinhart -= 273.15;                         // convert to C
  
//   Serial.print("Temperature "); 
//   Serial.print(steinhart);
//   Serial.println(" *C");
  
//   delay(1000);
// }
