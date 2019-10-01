#include <Arduino.h>

/*
 Created by Rui Santos
 
 All the resources for this project:
 http://randomnerdtutorials.com/
*/

#include "LedControl.h"
#include "binary.h"

/*
 DIN connects to pin 12
 CLK connects to pin 11
 CS connects to pin 10 
*/
LedControl lc=LedControl(12,11,10,1);

// delay time between faces
unsigned long delaytime=1000;
unsigned long drawDelay = 100;

// happy face
byte hf[8]= {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};
// neutral face
byte nf[8]={B00111100, B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};
// sad face
byte sf[8]= {B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100};

//Letter R
byte r[8] = {B01111000,B01000100,B01000100,B01000100,B01111000,B01001000,B01000100,B01000010};

//letter E
byte e[8] = {B01111110,B01000000,B01000000,B01111100,B01000000,B01000000,B01111110,B00000000};

void setup() {
  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,3);
  // Clear the display
  lc.clearDisplay(0);  
}


// step 1; wrtting our name letter e and r
void writeLetters(){

  //clear
  lc.clearDisplay(0);
  // r
  for(int i = 0; i < 8; i++){
    lc.setRow(0,i,r[i]);
    delay(drawDelay);
  }
  //hold letter on
  delay(delaytime);

  //clear 
  lc.clearDisplay(0);
  // e
  for(int i = 0; i < 8; i++){
    lc.setRow(0,i,e[i]);
    delay(drawDelay);
  }
  //hold letter on
  delay(delaytime);
}

void draw(byte character[8]){
  //clear 
  lc.clearDisplay(0);
  // char
  for(int i = 0; i < 8; i++){
    lc.setRow(0,i,character[i]);
  }
  //hold letter on
  delay(delaytime);
}

void drawFaces(){
  // sad face
  for(int i = 0; i < 8; i++){
    lc.setRow(0,i,sf[i]);
  }
  delay(delaytime);

  // neutral face
  for(int i = 0; i < 8; i++){
    lc.setRow(0,i,nf[i]);
  }
  delay(delaytime);

  // happy face
  for(int i = 0; i < 8; i++){
    lc.setRow(0,i,hf[i]);
  }
  delay(delaytime);
}


void loop(){

  // DEMO SETEP 4
  lc.clearDisplay(0);
  draw(e);
  delay(delaytime);

  // for loop for letters
  lc.clearDisplay(0);
  for(int i = 1; i < 5; i++){
    writeLetters();
  }

  // Step 2: for loop for faces
  lc.clearDisplay(0);
  for(int i = 1; i < 5; i++) {
    drawFaces();
  }


  // shut down display
  lc.clearDisplay(0);
  exit(0);
}