/**
 * Flex keys
 *
 *   The flex keys are used to (de)activate and control the pitch
 *   bend of the keys. Only 3 keys are used and are tuned to
 *   C4, D4 and E4. 
 *
 *   There is a threshold as to when the note is to activate/deactivate
 *   compared to the "resting" location of the sensor. Additionally there
 *   is another threshold to dictate when the pitch should star to bend
 */

const int numKeys = 3;
const int velocity = 100;
FlexKey keys[numKeys];

void flexkeySetup() {
  keys[0] = (FlexKey) {
    FLEX_PIN_1, 60, false
  };
  keys[1] = (FlexKey) {
    FLEX_PIN_2, 62, false
  };
  keys[2] = (FlexKey) {
    FLEX_PIN_3, 64, false
  };
}

void handleFlexkeys() {
  for (int i = 0; i < numKeys; i++) {
    handleFlexkey(keys[i]);
  }
}

int handleFlexkey(FlexKey key) {
  int keyVal = analogRead(key.pin);
  sendNoteMessage(keyVal, key);
  if (key.isOn) {
    sendPitchBend(keyVal);
  }
  return 0;
}

void sendNoteMessage(int keyVal, FlexKey key) {
  if (keyVal < FLEX_THRESHOLD && !key.isOn) {
    key.isOn = true;
    usbMIDI.sendNoteOn(key.note, velocity, CHANNEL);
  } else if (keyVal > FLEX_THRESHOLD && key.isOn) {
    usbMIDI.sendNoteOff(key.note, velocity, CHANNEL);
    key.isOn = false;
  }
}

void sendPitchBend(int keyVal) {
  if (keyVal < BEND_THRESHOLD) {
    int bend = round((BEND_THRESHOLD - keyVal * 1.0) / BEND_THRESHOLD * 127);
    usbMIDI.sendControlChange(BEND_CC, bend, CHANNEL);
  } else {
    usbMIDI.sendControlChange(BEND_CC, 0 , CHANNEL);
  }
}

