#include "controls.h"
#include "User_Setup.h"
#include "Leds.h"

#if OLED
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#endif

Controls ctrl;
Leds leds(&ctrl);

void setup() {
    Wire.begin();
    ctrl.setup();
    leds.setup();

#if OLED
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
      Serial.println(F("SSD1306 allocation failed"));
      for (;;); // Don't proceed, loop forever
    }

    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display.display();
    delay(200);

    // Clear the buffer
    display.clearDisplay();
#endif

    delay(3000); // power-up safety delay
}

void loop() {

#if OLED
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);
    display.print(sensor.readRangeContinuousMillimeters());
    display.display();
#endif
    ctrl.goProcess();
    leds.runPattern();

}
