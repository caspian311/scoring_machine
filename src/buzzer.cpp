#include "buzzer.h"
#include "Arduino.h"
#include "configurations.h"
#include "lines.h"

void Buzzer::turn_on_buzzer()
{
   if (!MUTE) 
   {
      digitalWrite(BUZZER, HIGH);
   }
}

void Buzzer::turn_off_buzzer()
{
   digitalWrite(BUZZER, LOW);
}
