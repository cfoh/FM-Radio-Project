/*
 * This program blinks the built-in LED on Arduino Nano.
 * 
 * You can use this program to test your Arduino development environment.
 * To be absolutely sure that Arduino runs your code, you should apply different
 * on/off patterns in the code and check that the LED blinks based on the
 * given pattern.
 */

// setup the hardware
void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{
  // configure the on/off time period
  int onPeriod  = 1500; // msec
  int offPeriod = 1000; // msec

  // execute the blinking
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(onPeriod);                   // wait
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(offPeriod);                  // wait
}
