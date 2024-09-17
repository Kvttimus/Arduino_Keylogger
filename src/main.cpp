#include <Arduino.h>
#include <Keyboard.h>

// constant values
const int buttonPin = 4;
int counter = 0;
int ledPin = 9;

uint8_t prevButtonState = LOW;
uint8_t ledValue = HIGH;
void program_startStop()
{
  uint8_t buttonState = digitalRead(buttonPin);
  if ((buttonState != prevButtonState) && (buttonState == HIGH))
  {
    ledValue = !ledValue;
    Serial.println("Swapped Values Again");
  }
  digitalWrite(ledPin, ledValue);
  prevButtonState = buttonState;
}


// default functions below ---------------
void setup() {
  Serial.begin(9600);  // sets the baud rate for comms
  while (!Serial) {;}  // wait for serial to connect

  // initializing pins
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  //Keyboard.begin();
}

void loop() {
  program_startStop();
}