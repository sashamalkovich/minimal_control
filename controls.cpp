//
// Created by welm on 2019-12-16.
//

#include "controls.h"

Controls::Controls() {
  analogValue = new int[3];
  lastAnalogValue = new int[3];
  vlxValue = 0;
  channel = 1;
  controlVLX = 38;
  controlPot_1 = 42;
  controlPot_2 = 36;
}

Controls::~Controls() {
  delete[] analogValue;
  delete[] lastAnalogValue;

}

void Controls::setup() {
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
}

void Controls::controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}

void Controls::Potentiometres(char anRead, byte control, byte channel, int sensor_number, int *analogValue, int *lastAnalogValue) {
  analogValue[sensor_number] = analogRead(anRead) / 8;
  if ((analogValue[sensor_number] - lastAnalogValue[sensor_number]) > 1 ||
      (analogValue[sensor_number] - lastAnalogValue[sensor_number]) < -1) {
    if (analogValue[sensor_number] != lastAnalogValue[sensor_number]) {
      controlChange(channel, control, analogValue[sensor_number]);
      lastAnalogValue[sensor_number] = analogValue[sensor_number];
    }
  }
}

void Controls::vlxSensor(byte control, byte channel, int sensor_number, int *analogValue, int *lastAnalogValue) {
  distance = sensor.readRangeContinuousMillimeters();
  if (distance > MIN_VLX && distance < MAX_VLX) {
    analogValue[sensor_number] = map(distance, MIN_VLX, MAX_VLX, 0, 127);
    if ((analogValue[sensor_number] - lastAnalogValue[sensor_number]) > 1 ||
        (analogValue[sensor_number] - lastAnalogValue[sensor_number]) < -1) {
      if (analogValue[sensor_number] != lastAnalogValue[sensor_number]) {
        controlChange(channel, control, analogValue[sensor_number]);
        lastAnalogValue[sensor_number] = analogValue[sensor_number];

      }
    }
  } if (distance < MIN_VLX && distance > MIN_VLX - 20) {
    analogValue[sensor_number] = 0;
    controlChange(channel, control, analogValue[sensor_number]);
  }
  if (distance > MAX_VLX && distance < MAX_VLX + 20) {
    analogValue[sensor_number] = 127;
    controlChange(channel, control, analogValue[sensor_number]);
  }
}

void Controls::goProcess() {
  Potentiometres(POT_1, controlPot_1, channel, 0, analogValue, lastAnalogValue);
  Potentiometres(POT_2, controlPot_2, channel, 1, analogValue, lastAnalogValue);
  vlxSensor(controlVLX, channel, 2, analogValue, lastAnalogValue);
}

uint8_t Controls::getSensorData() {
  return (analogValue[0] + analogValue[1] + analogValue[2]) / 3;
}
