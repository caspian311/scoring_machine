#ifndef _SCORING_MACHINE_H
#define _SCORING_MACHINE_H

#include "fencers.h"
#include "lights.h"
#include "buzzer.h"

class ScoringMachine
{
   public: 
      void cycle();

   private:
      Fencers fencers;
      Lights lights;
      Buzzer buzzer;

      void update_lights();
      void update_buzzer();
};

#endif
