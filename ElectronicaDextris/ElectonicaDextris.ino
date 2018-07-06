/*
 * Electronica Dextris Teensy 3.5 Code
 * 
 * Date Created: July 4, 2018
 * 
 * 
 * Details
 * 1. SHAFT
 *    This uses a tachometer on pin A0 to capture the velocity of the shaft
 *    This value is then "differentiated" to capture the instantaneous acceleration
 *    of the shaft. 
 *    The velocity controls the volume of the sound (MidiCC on channel 7)
 *    The acceleration does ¿SOMETHING?
 * 
 */

#define TAC_PIN A0
#define VOLUME_CC 7

int channel = 1; // Defines the MIDI channel to send messages on (values from 1-16)
int note = 60; 

int tac_val = 0;
int tac_prev_val = 0;
int tack
int tac_threshold = 3;
bool isNoteOn = false;


void setup() {
}

void loop() {
  handleTachometer();
  
}

// MARK: Tachometer code. 

void handleTachometer() {
  
  tac_val = analogRead(TAC_PIN);
  maybeToggleNote(tac_val);

  acceleration = (tac_val - prev_tac_val) / nanosPerLoop;
  
  if (abs(tac_val - tac_prev_val) > tac_threshold) {
    sendVolumeCC(tac_val);
    sendAccelCC(acceleration);
  }

  
  
  tac_prev_val = tac_val;
}

void sendVolumeCC(int volume) {
    if (volume < 0 || volume > 127) return;
    
    usbMIDI.sendControlChange(VOLUME_CC,volume,channel);
}


void sendAccelCC(int accel) {
//    if (volume < 0 || volume > 127) return;
    
    usbMIDI.sendControlChange(VOLUME_CC,volume,channel);
}

void maybeToggleNote(int val) {
  if (val == 0 && isNoteOn) {
    usbMIDI.sendNoteOn(note, 100, channel);
    isNoteOn = true;
  } else if (val > 0 && !isNoteOn) {
    usbMIDI.sendNoteOff(note, 100, channel);
    isNoteOn = false;
  }
}

