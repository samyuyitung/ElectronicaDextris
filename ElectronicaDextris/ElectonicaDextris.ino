/*
   Electronica Dextris Teensy 3.5 Code

   Authors: SYDE 361 Group 9
   Date Created: July 4, 2018
*/

// MARK: Const and struct definitions
#define TAC_PIN A0
#define FLEX_PIN_1 A1
#define FLEX_PIN_2 A2
#define FLEX_PIN_3 A3

#define BEND_CC 2
#define VOLUME_CC 7
#define EXPRESSION_CC 11

#define CHANNEL 1

#define TROMPETTE_THRESHOLD 70
#define FLEX_THRESHOLD 400
#define BEND_THRESHOLD 200

struct flexkey {
  int pin;
  int note;
  bool isOn;
};
typedef struct flexkey FlexKey;

// MARK: Lifecycle
void setup() {
  tachometerSetup();
  flexkeySetup();
}

void loop() {
  handleTachometer();
  handleFlexkeys();
  delay(10);
}

