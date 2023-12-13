// LED Matrix Module

#include "LedControl.h"

// Create an instance of the LedControl class
  //  Pin 12 is connected to the DataIn
  //  Pin 11 is connected to LOAD(CS)
  //  Pin 10 is connected to the CLK
LedControl lc=LedControl(12,10,11,1);

// Custom delays between images
unsigned long delay1 = 500;
unsigned long delay2 = 50;

void setup() {
  // Wakeup call to get the module out of power-saving mode
  lc.shutdown(0,false);
  // Set the brightness to a medium value
  lc.setIntensity(0,8);
  // Clear the display
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the LED matrix. 
 */
void writeArduinoOnMatrix() {
  /* Character Data */
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00010000,B00100000,B00100000,B00010000,B00111110};
  byte d[5]={B11111110,B00010010,B00100010,B00100010,B00011100};
  byte u[5]={B00111110,B00000100,B00000010,B00000010,B00111100};
  byte i[5]={B00000000,B00000010,B10111110,B00100010,B00000000};
  byte n[5]={B00011110,B00100000,B00100000,B00010000,B00111110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* Display them one by one with a small delay */
  lc.setRow(0,0,a[0]);
  lc.setRow(0,1,a[1]);
  lc.setRow(0,2,a[2]);
  lc.setRow(0,3,a[3]);
  lc.setRow(0,4,a[4]);
  delay(delay1);
  lc.setRow(0,0,r[0]);
  lc.setRow(0,1,r[1]);
  lc.setRow(0,2,r[2]);
  lc.setRow(0,3,r[3]);
  lc.setRow(0,4,r[4]);
  delay(delay1);
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  delay(delay1);
  lc.setRow(0,0,u[0]);
  lc.setRow(0,1,u[1]);
  lc.setRow(0,2,u[2]);
  lc.setRow(0,3,u[3]);
  lc.setRow(0,4,u[4]);
  delay(delay1);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(delay1);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  delay(delay1);
  lc.setRow(0,0,o[0]);
  lc.setRow(0,1,o[1]);
  lc.setRow(0,2,o[2]);
  lc.setRow(0,3,o[3]);
  lc.setRow(0,4,o[4]);
  delay(delay1);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delay1);
}

// This function lights up some LEDs in a given row, blinking n times
void rows() {
  for(int row=0;row<8;row++) {
    delay(delay2);
    lc.setRow(0,row,B10100000);
    delay(delay2);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delay2);
      lc.setRow(0,row,B10100000);
      delay(delay2);
      lc.setRow(0,row,(byte)0);
    }
  }
}

// This function lights up some LEDs in a given column, blinking n times
void columns() {
  for(int col=0;col<8;col++) {
    delay(delay2);
    lc.setColumn(0,col,B10100000);
    delay(delay2);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delay2);
      lc.setColumn(0,col,B10100000);
      delay(delay2);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

// This function will light up every LED on the matrix blinking n times.
void single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delay2);
      lc.setLed(0,row,col,true);
      delay(delay2);
      for(int i=0;i<col;i++) {
        lc.setLed(0,row,col,false);
        delay(delay2);
        lc.setLed(0,row,col,true);
        delay(delay2);
      }
    }
  }
}

void loop() { 
  writeArduinoOnMatrix();
  rows();
  columns();
  single();
}
