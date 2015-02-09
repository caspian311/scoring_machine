#include "lights.h"
#include "Arduino.h"
#include "lines.h"

void Lights::turn_on_light1()
{
   digitalWrite(FENCER1_LIGHT, HIGH);
}

void Lights::turn_on_light2()
{
   digitalWrite(FENCER2_LIGHT, HIGH);
}

void Lights::turn_off_light1()
{
   digitalWrite(FENCER1_LIGHT, LOW);
}

void Lights::turn_off_light2()
{
   digitalWrite(FENCER2_LIGHT, LOW);
}

