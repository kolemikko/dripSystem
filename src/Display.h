#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void initDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Screen allocation failed!"));
    for (;;)
      ;
  }
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void turnOffDisplay() {
  display.clearDisplay();
  display.display();
}

void displayMessage(String text) {
  display.clearDisplay();
  display.setCursor(10, 10);
  display.print(text);
  display.display();
}

void displayScrollingMessage(String text) {
  int textDelay = 300 * text.length();
  display.clearDisplay();
  display.setCursor(10, 10);
  display.print(text);
  display.display();
  display.startscrollleft(0x00, 0x0F);
  delay(textDelay);
  display.stopscroll();
}
