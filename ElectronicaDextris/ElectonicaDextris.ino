/*
   Electronica Dextris Teensy 3.5 Code

   Authors: SYDE 361 Group 9
   Date Created: July 4, 2018
*/

// MARK: Const and struct definitions
#define TAC_PIN A0
#define TAC_REF A1
#define FLEX_PIN_1 A2
#define FLEX_PIN_2 A3
#define FLEX_PIN_3 A4

#define FLEX_PIN_LED_1 A6
#define FLEX_PIN_LED_2 A7
#define FLEX_PIN_LED_3 A8

#define BEND_CC 2
#define VOLUME_CC 7
#define EXPRESSION_CC 11

#define CHANNEL 1

#define TROMPETTE_THRESHOLD 70
#define FLEX_THRESHOLD 320
#define BEND_THRESHOLD 240

struct flexkey {
  int pin;
  int note;
  bool isOn;
  int ledPin;
  // LED 
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

