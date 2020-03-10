/**
 * This example for esp32 200x200 b/w e-ink display,
 * Use GxEDP and Adafruit_GFX libraries drive screen,
 * Display a QRcode 180x180 with encode version 7 in the center,
 * Update partial
**/

#include <GxEPD.h>
#include <Arduino.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxGDEP015OC1/GxGDEP015OC1.h>
#include "qrcode.h"

GxIO_Class io(SPI, SS, 17, -1);
GxEPD_Class display(io, -1, -1);
QRcode qrcode(&display);

void setup() {
    Serial.begin(115200);
    Serial.println("display init");
    display.init();
    display.update();
    qrcode.create("hello world!");
}

void loop() {
}