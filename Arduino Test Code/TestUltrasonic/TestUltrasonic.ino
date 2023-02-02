/*
 * This program tests HC-SR04 ultrasonic sensor. 
 * The library is taken from the following repo:
 * - https://github.com/ErickSimoes/Ultrasonic
 * 
 * This test program prints the ranging outcome on the serial monitor.
 * The program works with the following wiring:
 * 
 *    Arduino    HC-SR04 Ultrasonic
 *       Nano    sensor
 *       ---+    +---
 *          |    |
 *       D14|----|TRIG
 *       D15|----|ECHO
 *          |    |
 *       ---+    +---
 */

#include "Ultrasonic.h"

// pin map setting
constexpr uint8_t ULTRASONIC_TRIG = 14;
constexpr uint8_t ULTRASONIC_ECHO = 15;

// create an `ultrasonic` object for our project
Ultrasonic ultrasonic(ULTRASONIC_TRIG, ULTRASONIC_ECHO);

void setup() 
{
  Serial.begin(9600);
  Serial.println("Start HC-SR04 testing");
}

void loop() 
{
  // read and print the distance in centimeters
  // if the sensor is not connected, the output is zero
  Serial.print("Distance (in cm): ");
  Serial.println(ultrasonic.read(CM));
  delay(1000);
}
