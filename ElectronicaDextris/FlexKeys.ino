/**
   Flex keys

     The flex sensors are used to (de)activate and control the pitch bend
     for all the keys. Currently, only 3 keys are used and are tuned to
     C4, D4 and E4.

     There is a hardcoded threshold deflection to determine when the note is
     activated. Furthermore there is a higher threshold to dictate when the
     pitch bending should start

   Notes:
     1. when a key is on, the corresponding LED is also turned on.
     2. Only one note can be played at a time (and only 1 note on message can be sent)
     3. If none of the notes are on, a base note is turned on
*/

const int numKeys = 3;
const int velocity = 100;
FlexKey keys[numKeys];
FlexKey base;

//MARK: Setup
void flexkeySetup() {
  pinMode(FLEX_PIN_LED_1, OUTPUT);
  pinMode(FLEX_PIN_LED_2, OUTPUT);
  pinMode(FLEX_PIN_LED_3, OUTPUT);

  keys[0] = (FlexKey) {
    FLEX_PIN_1, 60, false, FLEX_PIN_LED_1
  };
  keys[1] = (FlexKey) {
    FLEX_PIN_2, 62, false, FLEX_PIN_LED_2
  };
  keys[2] = (FlexKey) {
    FLEX_PIN_3, 64, false, FLEX_PIN_LED_3
  };
  
  base = (FlexKey) {
    A10, 48, false, A10
  };
}

//MARK: Loop and flex sensor handling
void handleFlexkeys() {
  for (int i = 0; i < numKeys; i++) {
    if (handleFlexkey(keys[i])) return;
  }
  // If none of the keys are on, send an noteOn for the base note
  sendNoteMessage(300, base);
}

bool handleFlexkey(FlexKey &key) {
  int keyVal = analogRead(key.pin);
  sendNoteState(keyVal, key);
  if (key.isOn) {
    sendPitchBend(keyVal);
  }
  return key.isOn;
}

void sendNoteState(int keyVal, FlexKey &key) {
  if (keyVal < FLEX_THRESHOLD && !key.isOn) {
    sendNoteOn(key);
  } else if (keyVal > FLEX_THRESHOLD && key.isOn) {
    sendNoteOff(key);
  }
}

//MARK: Midi messages
void sendNoteOn(FlexKey &key) {
  turnAllNotesOff();
  key.isOn = true;
  usbMIDI.sendNoteOn(key.note, velocity, CHANNEL);
  digitalWrite(key.ledPin, HIGH);
}

void sendNoteOff(FlexKey &key) {
  usbMIDI.sendNoteOff(key.note, velocity, CHANNEL);
  key.isOn = false;
  usbMIDI.sendControlChange(BEND_CC, 0 , CHANNEL);
  digitalWrite(key.ledPin, LOW);
}

void sendPitchBend(int keyVal) {
  if (keyVal < BEND_THRESHOLD) {
    int bend = round((BEND_THRESHOLD - keyVal * 1.0) / BEND_THRESHOLD * 127);
    usbMIDI.sendControlChange(BEND_CC, bend, CHANNEL);
  }
}

//MARK: Helper functions
void turnAllNotesOff() {
  for (int i = 0; i < numKeys; i++) {
    if (keys[i].isOn) {
      sendNoteOff(keys[i]);
    }
  }
  if (base.isOn) {
    sendNoteOff(base);
  }
}


