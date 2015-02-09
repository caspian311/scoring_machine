#include "Arduino.h"
#include "lines.h"

void initialize_lights()
{
   pinMode(FENCER1_LIGHT, OUTPUT);
   pinMode(FENCER2_LIGHT, OUTPUT);

   pinMode(ONBOARD_LED, OUTPUT);
}

void initialize_weapon_inputs()
{
   pinMode(FENCER1_A, INPUT);
   digitalWrite(FENCER1_A, HIGH);

   pinMode(FENCER2_A, INPUT);
   digitalWrite(FENCER2_A, HIGH);

   pinMode(FENCER1_B, INPUT);
   pinMode(FENCER2_B, INPUT);

   pinMode(FENCER2_C, INPUT);
   pinMode(FENCER1_C, INPUT);
}

void initialize_buzzer()
{
   pinMode(BUZZER, OUTPUT);
}

void setup_pins() 
{
   initialize_weapon_inputs();

   initialize_lights();

   initialize_buzzer();
}
