#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

/***********************************************************************
 * File Name: led_controller.h
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Header file for the LEDController class.
 * License: MIT License
 ***********************************************************************/
#include <Adafruit_NeoPixel.h>

// This project uses D0 to handle addressible RGB communication
#define LED_PIN D0

class LEDController
{
    private:
        Adafruit_NeoPixel pixels;           // Instance of neopixels object
        unsigned long pixelPrevious;        // Previous Pixel Millis
        unsigned long patternPrevious;      // Previous Pattern Millis
        int           patternCurrent;       // Current Pattern Number
        int           patternInterval;      // Pattern Interval (ms)
        bool          patternComplete;      // Pattern State
        int           pixelInterval;        // Pixel Interval (ms)
        int           pixelQueue;           // Pattern Pixel Queue
        int           pixelCycle;           // Pattern Pixel Cycle
        uint16_t      pixelNumber;          // Total Number of Pixels

    void colorWipe(uint32_t color, int wait);

}

#endif // LEDCONTROLLER_H
