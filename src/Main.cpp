#include "Display.h"
#include "Pump.h"

// Pump output pins (digital)
const int pump1 = 23;

#define uS_TO_S_MULTIPLIER 1000000
#define SLEEP_TIME 60 * 60 * 4

void setup() {
  initDisplay();
  pinMode(pump1, OUTPUT);
  esp_sleep_enable_timer_wakeup(SLEEP_TIME * uS_TO_S_MULTIPLIER);
}

void loop() {
  displayMessage("Pump running.");
  runPump(pump1, 15);
  displayMessage("Going to sleep...");
  delay(2000);
  turnOffDisplay();
  esp_deep_sleep_start();
}
