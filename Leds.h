//
// Created by welm on 2019-12-17.

#include "controls.h"
#include "FastLED.h"

#ifndef BLINK_LEO_LEDS_H
#define BLINK_LEO_LEDS_H

//#include "FastLED/FastLED.h"


class Leds {
public:
    explicit Leds(Controls *);

    ~Leds();

    void setup();

    void runPattern();

private:
    CRGB leds[NUM_LEDS];

    void rainbow();

    void rainbowWithGlitter();

    void addGlitter(fract8 chanceOfGlitter);

    void confetti();

    void sinelon();

    void bpm();

    void juggle();

    void blackOut();

    uint8_t gHue; // rotating "base color" used by many of the patterns
    unsigned long x, _timer, led_p;
    unsigned int pat;
    Controls *pCtrl;


};


#endif //BLINK_LEO_LEDS_H
