#include "Display.h"
#include "Pump.h"
#include "Web.h"

#define uS_TO_S_MULTIPLIER 1000000
const int sleepTime = 60 * 60 * 4;

// Pump output pins (digital)
const int pump1 = 23;


void setup() {
  initDisplay();
  pinMode(pump1, OUTPUT);
  esp_sleep_enable_timer_wakeup(sleepTime * uS_TO_S_MULTIPLIER);
  // initWiFi();
  // initServer();
}

void loop() {
  // runServer();
  displayMessage("Pump running.");
  runPump(pump1, 15);
  displayMessage("Going to sleep...");
  delay(2000);
  turnOffDisplay();
  esp_deep_sleep_start();
}
