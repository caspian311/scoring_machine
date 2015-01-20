/*
  Grounding Test
 
   1. See if a button can be connected to two pins instead of ground without destroying the Arduino
   2. See if resistors will allow control over which path the current takes 
 
 created 2015
 by B.J. Self
 

 */

// Constants won't change.
#include "lines.h"
#include "configurations.h"




const boolean debug = true;          // Set to true to use the serial debugger

// Variables will change as the program runs
boolean fencer1_hit_state = false;    // State of the fencer1 B line
//boolean fencer2_hit_state = false;    // State of the fencer2 B line

//boolean fencer1_ground_state = false; // State of the fencer2 C line
boolean fencer2_ground_state = false; // State of the fencer1 C line


void setup() {
  // Set up debugging
  if (debug) {
    Serial.begin(9600);
  }
  
  // initialize buttons
  pinMode(fencer1_a, OUTPUT);
  digitalWrite(fencer1_a, HIGH);
  
  pinMode(fencer1_b, INPUT);
  
  pinMode(fencer2_c, INPUT);

  // initialize the lights:
  pinMode(fencer1_light, OUTPUT);
  
  pinMode(onboard_led, OUTPUT);
  
  // initialize the buzzer
  pinMode(buzzer, OUTPUT);
  
//  // Signal when setup is done
//  for (int i=0; i < 5; i++) {
//    digitalWrite(onboard_led, HIGH);
//    delay(250);
//    digitalWrite(onboard_led, LOW);
//    delay(250);
//  }
//  digitalWrite(buzzer, HIGH);
//  delay(250);
//  digitalWrite(buzzer, LOW);

}

void loop(){
  Serial.println("== Loop Start ==");
  
  // Check Hit and Ground States
  if (digitalRead(fencer1_b) == HIGH) {
    fencer1_hit_state = true;
  } else {
    fencer1_hit_state = false;
  }
  if (digitalRead(fencer2_c) == HIGH) {
    fencer2_ground_state = true;
  } else {
    fencer2_ground_state = false;
  }
  
  if (fencer2_ground_state && fencer1_hit_state) {
    Serial.println("Hit and Ground");
    digitalWrite(onboard_led, HIGH);
    digitalWrite(fencer1_light, LOW);
    delay(debounce);
  } else if (fencer2_ground_state) {
    Serial.println("Ground Only");
    digitalWrite(onboard_led, HIGH);
    digitalWrite(fencer1_light, LOW);
    delay(debounce);
  } else if (fencer1_hit_state) {
    Serial.println("Hit Only");
    digitalWrite(onboard_led, LOW);
    digitalWrite(fencer1_light, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(buzzer_length * 1000);
    digitalWrite(buzzer, LOW);
    delay((light_length * 1000) - (buzzer_length * 1000));
    digitalWrite(fencer1_light, LOW);
    
  } else {
    Serial.println("Neither Hit nor Ground");
    digitalWrite(onboard_led, LOW);
    digitalWrite(fencer1_light, LOW);
  }
}
