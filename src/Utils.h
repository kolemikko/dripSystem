void delayCounter(int delaySec) {
  for (int i = delaySec; i > 0; i--) {
    displayMessage("Paused for " + String(i / 60) + "m" + String(i % 60) +
                   "s.");
    delay(1000);
  }
}
