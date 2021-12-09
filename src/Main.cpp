#include "Display.h"
#include "Pump.h"

// Pump output pins (digital)
const int pump1 = 7;

void setup()
{
  initDisplay();
  pinMode(pump1, OUTPUT);
}

void delayCounter(int delaySec)
{
  for (int i = delaySec; i > 0; i--)
  {
    displayMessage("Paused for " + String(i / 60) + "m" + String(i % 60) + "s.");
    delay(1000);
  }
}

void loop()
{
  displayMessage("Pump running.");
  runPump(pump1, 15);
  delayCounter(60 * 60 * 4);
}
