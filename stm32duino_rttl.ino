
#include <Arduino.h>
#undef _Tone_h
#include "rtttl.h"


Rtttl player;

char song[2048]; 
const int octave = 0;
const int pinspeaker = PB7;

void setup() {
     pinMode(LED_BUILTIN, OUTPUT);
     digitalWrite(LED_BUILTIN, HIGH);

     // pin for tone on PB7
     pinMode(pinspeaker, OUTPUT);
     player.begin(pinspeaker);
     Serial.begin();
}

void loop() {
  Serial.println("copy and paste the RTTL and press enter");
  if(Serial.available()) {
    Serial.readBytesUntil('\r',song,2048);
    player.play(song);
  }
  //sleep for 2 secs
  delay(3000);
}
