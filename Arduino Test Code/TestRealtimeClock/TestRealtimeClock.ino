/*
 * This program tests PCF8563 real-time clock module.
 * The library is taken from the following repo:
 * - https://github.com/elpaso/Rtc_Pcf8563 (code version: 19 Oct 2020)
 * 
 * PCF8563 is mounted on a breakout board. It uses I2C.
 */
 
#include "Rtc_Pcf8563.h"

// create an rtc object for our project
Rtc_Pcf8563 rtc;
bool rtcFound = false;
 
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Serial.println("Start RTC testing");

  // test if RTC module is present
  Wire.beginTransmission(RTCC_R>>1);
  if (Wire.endTransmission()==0)
  {
    rtcFound = true;
    Serial.println("RTC module found");

    // if the date is not right, use the following to set 
    // the date: dd, weekday, mm, century (0 for 20yy, 1 for 19yy), yy
    //rtc.setDate(31, 5, 12, 0, 21); // Friday 31/12/2021
  
    // if the time is not right, use the following to set 
    // the time: hh,mm,ss
    //rtc.setTime(20, 30, 0); // 8:30pm
  }
  else
  {
    Serial.println("RTC module not found");
  }
}
                                                                                
void loop()
{
  if (rtcFound)
  {
    Serial.print("Time:");
    Serial.print(rtc.formatTime(RTCC_TIME_HMS));
  
    Serial.print("\t Date:");
    Serial.println(rtc.formatDate(RTCC_DATE_WORLD));
    
    delay(1000);
  }
}
  
