#include "Arduino.h"
#include "fencers.h"
#include "configurations.h"
#include "lines.h"

void Fencers::receive_inputs()
{
   reading1_a = analogRead(FENCER1_A); 
   reading1_b = analogRead(FENCER1_B); 
   reading1_c = analogRead(FENCER1_C); 

   reading2_a = analogRead(FENCER2_A); 
   reading2_b = analogRead(FENCER2_B); 
   reading2_c = analogRead(FENCER2_C); 
}

void Fencers::update_fencer1_state()
{
   if (!fencer1_scored && fencer1_registered_on_target()) 
   {
      if (fencer2_scored) 
      {
         if (time_since_touch() < EPEE_TIMEOUT_DURATION) 
         {
            fencer1_scored = true;
         }
      }
      else 
      {
         fencer1_scored = true;
         touch_time = millis();
      }
   }
}

void Fencers::update_fencer2_state()
{
   if (!fencer2_scored && fencer2_registered_on_target()) 
   {
      if (fencer1_scored) 
      {
         if (time_since_touch() < EPEE_TIMEOUT_DURATION) 
         {
            fencer2_scored = true;
         }
      }
      else 
      {
         fencer2_scored = true;
         touch_time = millis();
      }
   }
}

void Fencers::reset()
{
   fencer1_scored = false;
   fencer2_scored = false;

   touch_time = 0;
}

long Fencers::time_since_touch()
{
   return millis() - touch_time;
}

bool Fencers::did_fencer1_score()
{
   return fencer1_scored;
}

bool Fencers::did_fencer2_score()
{
   return fencer2_scored;
}

bool Fencers::fencer1_registered_on_target()
{
   return is_1b_high() && is_2c_low();
}

bool Fencers::fencer2_registered_on_target()
{
   return is_2b_high() && is_1c_low();
}

bool Fencers::is_1c_low()
{
   return reading1_c < THRESHOLD_LOW;
}

bool Fencers::is_2c_low()
{
   return reading2_c < THRESHOLD_LOW;
}

bool Fencers::is_1b_high()
{
   return reading1_b > THRESHOLD_MEDIUM;
}

bool Fencers::is_2b_high()
{
   return reading2_b > THRESHOLD_MEDIUM;
}
