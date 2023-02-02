/*
 * This program tests KY-040 Rotary Encoder. 
 * 
 * It is copied from the given datasheet. It prints the rotation outcome on 
 * the serial monitor. The program works with the following wiring:
 * 
 *    Arduino    KY-040 
 *       Nano    Rotary Encoder
 *       ---+    +---
 *          |    |
 *        D2|----|CLK
 *        D4|----|DT
 *          |    |
 *       ---+    +---
 *       
 * The program works but it's far from reliable. It uses the main 
 * loop (rather than interrupt) to detect clock state which can be 
 * laggy when the main loop has many active tasks. Besides, it 
 * does not fix the switch bouncing issue. It is your responsibility 
 * to address those issues, no solution will be shared.
 */

int pinA  = 2; // Connected to CLK on KY-040
int pinB  = 4; // Connected to DT  on KY-040

int encoderPosCount = 0;
int pinALast;
int aVal;
boolean bCW;

void setup() {
  pinMode (pinA,INPUT);
  pinMode (pinB,INPUT);
  /* Read Pin A
     Whatever state it's in will reflect the last position
   */
  pinALast = digitalRead(pinA);
  Serial.begin (9600);
}

void loop() {
  aVal = digitalRead(pinA);
  if (aVal != pinALast){ // Means the knob is rotating
    // if the knob is rotating, we need to determine direction
    // We do that by reading pin B.
    if (digitalRead(pinB) != aVal) { // Means pin A Changed first - We're Rotating Clockwise
    encoderPosCount ++;
    bCW = true;
    } else { // Otherwise B changed first and we're moving CCW
      bCW = false;
      encoderPosCount--;
    }
  
    Serial.print ("Rotated: ");
    if (bCW) {
      Serial.println ("clockwise");
    } else {
      Serial.println("counterclockwise");
    }
    Serial.print("Encoder Position: ");
    Serial.println(encoderPosCount);
  }
  pinALast = aVal;
}
