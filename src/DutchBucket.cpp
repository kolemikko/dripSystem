#include "Display.h"
#include "Pump.h"

// Pump output pins (PWM)
const int pump1 = 5;

void setup()
{
  initDisplay();
  pinMode(pump1, OUTPUT);
}

void loop()
{
  displayMessage("Pump started.");
  runPump(pump1, 3000, 200);
  displayMessage("Delay started.");
  delay(3000);
}

