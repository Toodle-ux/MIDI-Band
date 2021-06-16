#include <MIDIUSB.h>
#include <pitchToNote.h>

const int threshold = 100;
int notes[] = {
pitchC4+1, pitchD4, pitchE4, pitchF4+1, pitchG4+1, pitchG4+2, pitchG4+4, pitchG4+6};

void setup() {
  Serial.begin(9600);       // initialize serial communications
}

// send a 3-byte midi message
void midiCommand(byte cmd, byte data1, byte  data2) {
  Serial.write(cmd);     // command byte (should be > 127)
  Serial.write(data1);   // data byte 1 (should be < 128)
  Serial.write(data2);   // data byte 2 (should be < 128)
  // First parameter is the event type (top 4 bits of the command byte).
  // Second parameter is command byte combined with the channel.
  // Third parameter is the first data byte
  // Fourth parameter second data byte

  midiEventPacket_t midiMsg = {cmd >> 4, cmd, data1, data2};
  MidiUSB.sendMIDI(midiMsg);
}

void loop() {
  int thisRead=analogRead(0);
  if (thisRead < 140) {
    // play the note corresponding to this sensor:
    midiCommand(0x90, notes[0], 0x7F);
  }
  else{
    // turn the note off:
    midiCommand(0x80, notes[0], 0);
  }
  thisRead=analogRead(1);
  if (thisRead < 180) {
    // play the note corresponding to this sensor:
    midiCommand(0x90, notes[1], 0x7F);
  }
  else{
    // turn the note off:
    midiCommand(0x80, notes[1], 0);
  }
  thisRead=analogRead(2);
  if (thisRead < 100) {
    // play the note corresponding to this sensor:
    midiCommand(0x90, notes[2], 0x7F);
  }
  else{
    // turn the note off:
    midiCommand(0x80, notes[2], 0);
  }
  thisRead=analogRead(3);
  if (thisRead < 220) {
    // play the note corresponding to this sensor:
    midiCommand(0x90, notes[3], 0x7F);
  }
  else{
    // turn the note off:
    midiCommand(0x80, notes[3], 0);
  }
  thisRead=analogRead(4);
  if (thisRead < 750) {
    // play the note corresponding to this sensor:
    midiCommand(0x90, notes[4], 0x7F);
  }
  else{
    // turn the note off:
    midiCommand(0x80, notes[4], 0);
  }
  thisRead=analogRead(5);
  if (thisRead < 750) {
    // play the note corresponding to this sensor:
    midiCommand(0x90, notes[5], 0x7F);
  }
  else{
    // turn the note off:
    midiCommand(0x80, notes[5], 0);
  }
  thisRead=analogRead(6);
  if (thisRead < 120) {
    // play the note corresponding to this sensor:
    midiCommand(0x90, notes[6], 0x7F);
  }
  else{
    // turn the note off:
    midiCommand(0x80, notes[6], 0);
  }
  delay(10);
  thisRead=analogRead(7);
  if (thisRead < 100) {
    // play the note corresponding to this sensor:
    midiCommand(0x90, notes[7], 0x7F);
  }
  else{
    // turn the note off:
    midiCommand(0x80, notes[7], 0);
  }
}
