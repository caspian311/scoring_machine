#ifndef _FENCER_H
#define _FENCER_H

class Fencers
{
   public:
      void receive_inputs();

      void update_fencer1_state();
      void update_fencer2_state();
      
      bool did_fencer1_score();
      bool did_fencer2_score();

      long time_since_touch();

      void reset();

   private:
      int reading1_a; 
      int reading1_b; 
      int reading1_c; 

      int reading2_a; 
      int reading2_b; 
      int reading2_c; 

      bool fencer1_scored; 
      bool fencer2_scored; 

      long touch_time; 

      bool fencer1_registered_on_target();
      bool fencer2_registered_on_target();

      bool is_1b_high();
      bool is_2c_low();

      bool is_2b_high();
      bool is_1c_low();

      void print_debugging_info();
};

#endif
