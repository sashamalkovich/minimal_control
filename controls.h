


//
// Created by welm on 2019-12-16.
//
//#include "MIDIUSB/src/MIDIUSB.h"
#include "MIDIUSB.h"
#include <arduino.h>
#include <VL53L0X.h>
#include "def.h"
//#include <libraries/VL53L0X/VL53L0X.h>
//#include <libraries/Adafruit_GFX_Library/Adafruit_GFX.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>

#ifndef BLINK_LEO_CONTROLS_H
#define BLINK_LEO_CONTROLS_H


class Controls {
public:
    explicit Controls();

    ~Controls();

    void goProcess();

    void setup();

   uint8_t getSensorData();

private:
    void controlChange(byte, byte, byte);

    void Potentiometres(char, byte, byte, int, int *, int *);

    void vlxSensor(byte, byte, int, int *, int *);


    VL53L0X sensor;
    byte controlPot_1;
    byte controlPot_2;
    byte controlVLX;
    byte channel;
    int16_t vlxValue;
    int distance;

    int *analogValue;
    int *lastAnalogValue;


};


#endif //BLINK_LEO_CONTROLS_H
