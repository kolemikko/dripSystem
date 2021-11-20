#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Screen
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Serial.begin(300);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop()
{
  displayMessage("Pump started.");
  delay(3000);
  displayMessage("Pump stopped.");
  delay(3000);
}

void displayMessage(String text)
{
  display.clearDisplay();
  display.setCursor(10, 10);
  display.print(text);
  display.display();
}

void displayScrollingMessage(String text)
{
  int textDelay = 300 * text.length();
  display.clearDisplay();
  display.setCursor(10, 10);
  display.print(text);
  display.display();
  display.startscrollleft(0x00, 0x0F);
  delay(textDelay);
  display.stopscroll();
}
