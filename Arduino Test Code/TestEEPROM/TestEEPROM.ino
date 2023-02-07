/*
 * This program tests the built-in EEPROM Arduino Nano.
 * 
 * To test the program, first upload the code with OPTION 1 to write some data to EEPROM.
 * Then upload the code with OPTION 0 to read and print the previously written data.
 * The shown data should be the same as the previously written data.
 */

#include <EEPROM.h>

#define EEPROM_ADDR 10 // the EEPROM address to test
#define OPTION      1  // 0:read previously written data; 1: write data

struct MyData
{
  int  value;
  char str[10];
};
MyData data = {0, "none"};

// setup the hardware
void setup() 
{
  Serial.begin(9600);

  if (OPTION==0)
  {
    Serial.print("Reading previously written data at address: ");
    Serial.println(EEPROM_ADDR);

    EEPROM.get(EEPROM_ADDR, data);
    Serial.print("The stored integer: "); Serial.println(data.value);
    Serial.print("The stored string: "); Serial.println(data.str);
  }
  else
  {
    MyData data = {28, "new value"};
    Serial.print("Writing data to address: ");
    EEPROM.put(EEPROM_ADDR, data);
    Serial.print("The integer: "); Serial.println(data.value);
    Serial.print("The string: "); Serial.println(data.str);
  }
}

// the loop function runs over and over again forever
void loop() 
{
}
