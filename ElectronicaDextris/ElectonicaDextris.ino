/*
 * Electronica Dextris Teensy 3.5 Code
 * 
 * Authors: SYDE 361 Group 9 
 * Date Created: July 4, 2018
 * 
 * 
 * Details
 * 1. SHAFT
 *    This uses a tachometer on pin A0 to capture the velocity of the shaft
 *    This value is then "differentiated" to capture the instantaneous acceleration
 *    of the shaft. 
 *    The velocity controls the volume of the sound (MidiCC on channel 7)
 *    The acceleration sends a "
 * 
 */

#define TAC_PIN A0
#define VOLUME_CC 7
#define EXPRESSION_CC 11

int channel = 1; // Defines the MIDI channel to send messages on (values from 1-16)

const int numReadings = 5;
int currentIndex = 0;
int tacHistory[numReadings];

int avgVelocity = 0;
void setup() {
  for (int i = 0; i < numReadings; i++) tacHistory[i] = 0;
}

void loop() {
     handleTachometer();
     delay(10);
}

// MARK: Tachometer code. 

void handleTachometer() {  
  tacHistory[currentIndex++] = analogRead(TAC_PIN);    

  if (currentIndex >= numReadings)
    currentIndex = 0;

  avgVelocity = min(calculateAverage() / 3, 127);
  sendVolumeCC(avgVelocity);
  sendTrompetteCC(avgVelocity);
}

int calculateAverage() {
  int sum = 0;
  for (int i = 0; i < numReadings; i++) {
    sum += tacHistory[i];
  }
  return sum / numReadings;
}

void sendVolumeCC(int volume) {
    usbMIDI.sendControlChange(VOLUME_CC,volume,channel);
}


void sendTrompetteCC(int velocity) {
    if (velocity > 70) {
      usbMIDI.sendControlChange(EXPRESSION_CC,velocity,channel);
    } else {
      usbMIDI.sendControlChange(EXPRESSION_CC,0,channel);
    }
}
