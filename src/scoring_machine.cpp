#include "scoring_machine.h"
#include "configurations.h"

void ScoringMachine::update_buzzer()
{
   if (fencers.time_since_touch() < BUZZER_LENGTH) 
   {
      buzzer.turn_on_buzzer();
   }
   else 
   {
      buzzer.turn_off_buzzer();
   }
}

void ScoringMachine::update_lights()
{
   if (fencers.did_fencer1_score()) 
   {
      lights.turn_on_light1();
   }
   else 
   {
      lights.turn_off_light1();
   }

   if (fencers.did_fencer2_score()) 
   {
      lights.turn_on_light2();
   } 
   else 
   {
      lights.turn_off_light2();
   }
}

void ScoringMachine::cycle() 
{
   fencers.receive_inputs();

   fencers.update_fencer1_state();
   fencers.update_fencer2_state();

   if (fencers.did_fencer1_score() || fencers.did_fencer2_score()) 
   {
      if (fencers.time_since_touch() > LIGHT_LENGTH) 
      {
         fencers.reset();
      }
   }

   if (fencers.did_fencer1_score() || fencers.did_fencer2_score()) 
   {
      update_buzzer();
   }

   update_lights();
}
