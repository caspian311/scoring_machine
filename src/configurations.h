#ifndef _CONF_H
#define _CONF_H

// Set to true to use the serial debugger
const bool DEBUG = false;

// Length light should show (in milliseconds)
const float LIGHT_LENGTH = 3000;
// Length buzzer should sound (in milliseconds) ** Must be less than light_length
const float BUZZER_LENGTH = 1000;

// Mute the buzzer
const bool MUTE = true;

// When current is split 3 ways (weapon A + weapon B + ground)
const int THRESHOLD_LOW = 125;
// When current is split 2 ways (weapon A + weapon B)
const int THRESHOLD_MEDIUM = 270;
// When current is not split (weapon A)
const int THRESHOLD_HIGH = 400;

// Epee Timing
// Stop registering touches after x milliseconds
const int EPEE_TIMEOUT_DURATION = 40;

#endif
