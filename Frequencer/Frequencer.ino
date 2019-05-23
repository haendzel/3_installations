#include <Servo.h>
#include "pitches.h"
 
Servo myservo;  // create servo object to control a servo

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
 
int potpin = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;
int val;
int val2; // variable to read the value from the analog pin

int freq = 1000;
 
void setup() {
  pinMode(7, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}
 
void loop() {  
               
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);
 

  val2 = analogRead(potpin2);
  val2 = map(val2, 0, 1023, 0, 180);
  myservo.write(val2);
  
   
  if (val2 >= 60 && val2 <= 65) {
  tone(8, 4300); //generate 4300khz
  delay(150);  
  tone(8, 3500); //generate 3500khz
  delay(150);
  }
  if (val2 >= 30 && val2 <= 35) {
  int czestotliwosc = 0;
  for (czestotliwosc = 31; czestotliwosc < 7000; czestotliwosc++) { 
    tone(8, czestotliwosc);
  }
  }
  if (val2 >= 180 && val2 <= 170) {
    tone(8, 1000, 500);
  }
  if (val >= 60 && val <= 65) {
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }  
  }
  else {
  }
}
