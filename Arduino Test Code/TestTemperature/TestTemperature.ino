/*
 * This program tests HTU21D temperature & humidity sensor.
 * The library is taken from the following repo:
 * - https://github.com/sparkfun/SparkFun_HTU21D_Breakout_Arduino_Library
 * 
 * This program prints the temperature & humidity on the serial monitor.
 * The sensor uses I2C. 
 * If no sensor is detected, it prints 998.
 * If data is corrupted (i.e. CRC failed), it prints 999.
 */

#include "SparkFunHTU21D.h"

// create a sensor object
HTU21D sensorHTU21D;
bool htu21dFound = false;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start HTU21D testing");
  sensorHTU21D.begin();

  // test if HTU21D module is present
  if (sensorHTU21D.readTemperature()==998)
  {
    Serial.println("HTU21D module not found");
  }
  else
  {
    htu21dFound = true;
    Serial.println("HTU21D module found");
  }
}

void loop()
{
  if (htu21dFound)
  {
    float humdity = sensorHTU21D.readHumidity();
    float temperature = sensorHTU21D.readTemperature();
  
    Serial.print("Temperature: ");
    Serial.print(temperature, 1);
    Serial.print("C;\t");
    Serial.print("Humidity: ");
    Serial.print(humdity, 1);
    Serial.println("%");
    delay(1000);
  }
}
