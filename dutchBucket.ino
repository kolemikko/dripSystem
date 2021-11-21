#include "Display.h"

// Pump output pins
const int pump1 = 9;

void setup()
{
  Serial.begin(300);
  initDisplay();

  pinMode(pump1, OUTPUT);
}

void loop()
{
  displayMessage("Pump started.");
  runPump(pump1, 3000);
  displayMessage("Delay started.");
  delay(3000);
}

void runPump(int pumpNumber, int time)
{
  digitalWrite(pumpNumber, HIGH);
  delay(time);
  digitalWrite(pumpNumber, LOW);
}
