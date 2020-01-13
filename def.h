 //
// Created by welm on 2019-12-16.
//

#ifndef BLINK_LEO_DEF_H
#define BLINK_LEO_DEF_H

#define LED_PIN    5
#define NUM_LEDS    8
#define BRIGHTNESS  255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

#define POT_1 A0
#define POT_2 A1

#define MIN_VLX 50
#define MAX_VLX 290

#define OLED false


#endif //BLINK_LEO_DEF_H
