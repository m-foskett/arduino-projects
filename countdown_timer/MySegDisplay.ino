#define TIME 2

// Function: shift_register_setup
//  - Purpose:
//    - Setup the 74HC95 Shift Register pins to be OUTPUT
//  - Returns:
//    - void
void shift_register_setup(const uint8_t latch, const uint8_t clock, const uint8_t data) {
  pinMode(latch, OUTPUT); // ST_CP [RCK]
  pinMode(clock, OUTPUT); // SH_CP [SCK]
  pinMode(data, OUTPUT); // DS [S1]
}

// Function: digit_pins_setup
//  - Purpose:
//    - Setup the Digit Control pins of the 4-digit-7-segment display to be OUTPUT
//  - Returns:
//    - void
void digit_pins_setup(const uint8_t digit_1, const uint8_t digit_2, const uint8_t digit_3, const uint8_t digit_4) {
  pinMode(digit_1, OUTPUT);
  pinMode(digit_2, OUTPUT);
  pinMode(digit_3, OUTPUT);
  pinMode(digit_4, OUTPUT);
}
// Function: led_setup
//  - Purpose:
//    - Setup LED pin
//  - Returns:
//    - void
void led_setup() {
   digitalWrite(LED, HIGH);
}

void display_num(uint16_t num) {
  uint8_t com = 0;
  uint8_t polling = 0;
  uint8_t bit_num = 0;
  uint8_t num_place[4] = {0};
  
  if(num > = 1000 && num <= 9999) {
    polling = 4;
    bit_num = 3;
    num_place[3] = num/1000;
    num_place[2] = num/100%10;
    num_place[1] = num/10%10;
    num_place[0] = num%10;
    for(int i = 0; i < 4; i++) {
      clear_bit_display();
      choose_com(polling);
      polling--;
      display(num_place[bit_num--]);
      delay(TIME);
    }
   }
   else if(num>=100&&num<1000)
   {
    polling=3;
    bit_num=2;
    num_place[2]=num/100;
    num_place[1]=num/10%10;
    num_place[0]=num%10;
      for(int i=0;i<3;i++)
     {clear_bit_display();
      choose_com(polling);
      polling--;
      display(num_place[bit_num--]);
      delay(TIME);
     }
    }
    else if(num>=10&&num<100)
   {clear_bit_display();
    polling=2;
    bit_num=1;
    num_place[1]=num/10;
    num_place[0]=num%10;
       for(int i=0;i<2;i++)
       {
        choose_com(polling);
        polling--;
        display(num_place[bit_num--]);
        delay(TIME);
       }
    }
    else if(num>=0 && num<=9)
    { clear_bit_display();
        num_place[0]=num%10;
        choose_com(1);
        display(num_place[0]);
        delay(TIME);
     }
    else
     {num=9999;}
 
  }

void display(uint8_t num)
{
  digitalWrite(LATCH,LOW);
  shiftOut(DATA,CLOCK,MSBFIRST,num_buf[num]);
  digitalWrite(LATCH,HIGH);
}

void choose_com(uint8_t com)
 {
  switch(com)
  {
    case 1:choose_DIGIT_1();
            
            break;
    case 2:choose_DIGIT_2();

            break;
   case 3:choose_DIGIT_3();

            break;
    case 4:choose_DIGIT_4();
            
            break;         
    default :break;
    }
  }

void choose_DIGIT_1()
{
    digitalWrite(DIGIT_1, LOW);
    digitalWrite(DIGIT_2, HIGH);
    digitalWrite(DIGIT_3, HIGH);
    digitalWrite(DIGIT_4, HIGH);  
 }

 void choose_DIGIT_2()
{
    digitalWrite(DIGIT_1, HIGH);
    digitalWrite(DIGIT_2, LOW);
    digitalWrite(DIGIT_3, HIGH);
    digitalWrite(DIGIT_4, HIGH);  
 }
 void choose_DIGIT_3()
{
    digitalWrite(DIGIT_1, HIGH);
    digitalWrite(DIGIT_2, HIGH);
    digitalWrite(DIGIT_3, LOW);
    digitalWrite(DIGIT_4, HIGH);  
 }
 void choose_DIGIT_4()
{
    digitalWrite(DIGIT_1, HIGH);
    digitalWrite(DIGIT_2, HIGH);
    digitalWrite(DIGIT_3, HIGH);
    digitalWrite(DIGIT_4, LOW);    
 }

void clear_bit_display()
{
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, 0);
  digitalWrite(LATCH, HIGH);
  digitalWrite(LATCH, LOW);
  delay(TIME);
}


 void clear_display()
{
  for(int i = 0; i < 4; i++) {
    choose_com(i);
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST,0);
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);
    delay(TIME);
  }
}
