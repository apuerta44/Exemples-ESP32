#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "cat_frames.h"

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define OLED_ADDR     0x3C   // a veces 0x3D

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("No se encuentra el SSD1306"));
    while (true);
  }
  display.clearDisplay();
  display.display();
}

void loop() {
  for (uint8_t f = 0; f < FRAME_COUNT; f++) {
    display.clearDisplay();
    display.drawBitmap(0, 0, catFrames[f], SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
    display.display();
    delay(170);   // ajusta la velocidad a tu gusto
  }
}
