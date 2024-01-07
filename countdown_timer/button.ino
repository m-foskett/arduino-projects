// Function: control_buttons_setup
//  - Purpose:
//    - Setup the Control Buttons of the timer to be INPUT_PULLUP
//  - Returns:
//    - void
void control_buttons_setup(const uint8_t select_button, const uint8_t seconds_button, const uint8_t milliseconds_button) {
  pinMode(select_button, INPUT_PULLUP);
  pinMode(seconds_button, INPUT_PULLUP);
  pinMode(milliseconds_button, INPUT_PULLUP); 
}
// Function: control_buttons_interrupt_setup
//  - Purpose:
//    - Attach Pin Change Interrupts to the pins of Control Buttons
//  - Returns:
//    - void
void control_buttons_interrupt_setup(const uint8_t select_button, const uint8_t seconds_button,const uint8_t milliseconds_button) {
  attachPinChangeInterrupt(select_button, select_button_interrupt, FALLING);
  attachPinChangeInterrupt(seconds_button, seconds_button_interrupt, FALLING);
  attachPinChangeInterrupt(milliseconds_button, milliseconds_button_interrupt, FALLING);
}


void seconds_button_interrupt()
{
  time_seconds_button=millis();
  
  if (200 < (abs(time_seconds_button - last_time_seconds_button)))
  {
    flag_begin=0; 
    
    number +=100;
    
    last_time_seconds_button = time_seconds_button;
    
    if (number >= 9900)
        number = 9999;
  }   
}

  void milliseconds_button_interrupt()
{
  time_milliseconds_button=millis();
  
  if (200 < (abs(time_milliseconds_button - last_time_milliseconds_button)))
  {
     flag_begin=0;
     
     number +=1;
     
     if(number%100 == 60 && number != 60)
       number = number/100*100+100;
       
     if(number==60)
        {number=100;}

     if(number >= 9900)
        number = 9999;

      last_time_milliseconds_button = time_milliseconds_button;
  }    
}

void select_button_interrupt ()
{
   time_select_button=millis();

   if (200 < (abs(time_select_button - last_time_select_button)))
    { 
      if(flag_begin)
        {
          number=0;
         }
         
      flag_begin=!flag_begin;
      
      last_time_select_button = time_select_button;
    }
}
