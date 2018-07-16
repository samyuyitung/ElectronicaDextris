/**
   Tachometer

     The tachometer is used to sense the velocity of the rotating shaft.
     This controls the output volume (MIDI CC7) for the instrument.
     Additionally if the velocity is above a certain threshold an expression
     (MIDI CC11) signal is sent, this simulates the trompette sound of the HG

   Notes: To debounce this a running average is used to calculate the velocity
          of the shaft.
*/

const int numReadings = 5;
int currentIndex = 0;
int tacHistory[numReadings];
int tacRef;
void tachometerSetup() {
  tacRef = analogRead(TAC_REF);
  for (int i = 0; i < numReadings; i++) {
    tacHistory[i] = 0;
  }
}

void handleTachometer() {
  tacHistory[currentIndex++] = abs(analogRead(TAC_PIN) - tacRef);

  if (currentIndex >= numReadings) {
    currentIndex = 0;
  }
  int avgVelocity = min(calculateAverage() / 3, 127);

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
  usbMIDI.sendControlChange(VOLUME_CC, volume, CHANNEL);
}

void sendTrompetteCC(int velocity) {
  if (velocity > 70) {
    usbMIDI.sendControlChange(EXPRESSION_CC, velocity, CHANNEL);
  } else {
    usbMIDI.sendControlChange(EXPRESSION_CC, 0, CHANNEL);
  }
}

