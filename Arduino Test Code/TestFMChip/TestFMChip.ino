/*
 * This program tests Si4703 FM chip. It is taken from the following repo:
 * - https://github.com/sparkfun/SparkFun_Si4703_Arduino_Library
 * The latest version uses STC. For simplicity in testing, here we use 
 * the 10-Sep-2018 version (commit: e343da381fd1be64474fae0a5e42349984312c2b) 
 * which implements polling rather than STC.
 * 
 * There are also many other implementations of Si4703 libraries. It is 
 * your responsibility to choose one that suits your design. You may
 * use this library or other library with more features.
 * 
 * It uses serial link to provide user interaction, open the serial monitor
 * to interact with the program. It works with the following wiring:
 * 
 *    Arduino        Si4703
 *       Nano    breakout board     Amplifier
 *       ---+    +-------------+    +----..
 *          |    |             |    |
 *     +3.3V|----|VCC          |    |
 *       GND|----|GND      LOUT|--->|AudioLeft
 *        A3|----|!RST      GND|--->|GND
 *        A4|----|SDIO     ROUT|--->|AudioRight
 *        A5|----|SCLK         |    |
 *          |    |             |    +----..
 *       ---+    +-------------+
 */

#include "SparkFunSi4703.h"
#include <Wire.h>

// wiring setup
int resetPin = A3;
int SDIO = A4;
int SCLK = A5;

Si4703_Breakout radio(resetPin, SDIO, SCLK);
int channel;
int volume;
char rdsBuffer[10];

void setup()
{
  Serial.begin(9600);
  Serial.println("\n\nSi4703_Breakout Test Sketch");
  Serial.println("===========================");  
  Serial.println("a b     Favourite stations");
  Serial.println("+ -     Volume (max 15)");
  Serial.println("u d     Seek up / down");
  Serial.println("r       Listen for RDS Data (15 sec timeout)");
  Serial.println("Send me a command letter.");

  radio.powerOn();
  radio.setVolume(0);
}

void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == 'u') 
    {
      channel = radio.seekUp();
      displayInfo();
    } 
    else if (ch == 'd') 
    {
      channel = radio.seekDown();
      displayInfo();
    } 
    else if (ch == '+') 
    {
      volume ++;
      if (volume == 16) volume = 15;
      radio.setVolume(volume);
      displayInfo();
    } 
    else if (ch == '-') 
    {
      volume --;
      if (volume < 0) volume = 0;
      radio.setVolume(volume);
      displayInfo();
    } 
    else if (ch == 'a')
    {
      channel = 930; // Rock FM
      radio.setChannel(channel);
      displayInfo();
    }
    else if (ch == 'b')
    {
      channel = 974; // BBC R4
      radio.setChannel(channel);
      displayInfo();
    }
    else if (ch == 'r')
    {
      Serial.println("RDS listening");
      radio.readRDS(rdsBuffer, 15000);
      Serial.print("RDS heard:");
      Serial.println(rdsBuffer);      
    }
  }
}

void displayInfo()
{
   Serial.print("Channel:"); Serial.print(channel); 
   Serial.print(" Volume:"); Serial.println(volume); 
}
