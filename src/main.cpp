/*
   Grounding Test

    1. See if a button can be connected to two pins instead of ground without destroying the Arduino
    2. See if resistors will allow control over which path the current takes

 created 2015
 by B.J. Self

*/

#include "Arduino.h"
#include "lines.h"
#include "pin_setup.h"
#include "configurations.h"
#include "scoring_machine.h"

ScoringMachine scoringMachine;

void signal_setup_complete() 
{
   for (int i=0; i < 5; i++) 
   {
      digitalWrite(ONBOARD_LED, HIGH);
      delay(250);
      digitalWrite(ONBOARD_LED, LOW);
      delay(250);
   }

   if (!MUTE) 
   {
      digitalWrite(BUZZER, HIGH);
      delay(250);
      digitalWrite(BUZZER, LOW);
   }
}

void setup_debugging()
{
   if (DEBUG) 
   {
      Serial.begin(9600);
      Serial.println("Debugging Started...");
   }
}

void setup() 
{
   setup_debugging();

   setup_pins();

   signal_setup_complete();
}

void loop() 
{
   scoringMachine.cycle();
}

