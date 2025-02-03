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
#define LED_COUNT 24

enum class LEDMode {
    LEDOff,
    Carousel,
    ColorWipe,
    TheaterChase,
    Rainbow,
    TheaterChaseRainbow
};

class LEDController
{
private:
    Adafruit_NeoPixel _pixels;           // Instance of neopixels object
    unsigned long _pixelPrevious;        // Previous Pixel Millis
    unsigned long _patternPrevious;      // Previous Pattern Millis
    int           _patternCurrent;       // Current Pattern Number
    int           _patternInterval;      // Pattern Interval (ms)
    bool          _patternComplete;      // Pattern State
    int           _pixelInterval;        // Pixel Interval (ms)
    int           _pixelQueue;           // Pattern Pixel Queue
    int           _pixelCycle;           // Pattern Pixel Cycle
    uint16_t      _pixelNumber;          // Total Number of Pixels

    // The current animation mode selected
    LEDMode _previousMode;
    LEDMode _currentMode;

    void colorWipe(uint32_t color, int wait);
    void theaterChase(uint32_t color, int wait);
    uint32_t wheel(byte wheelPos);
    void rainbow(uint8_t wait);
    void theaterChaseRainbow(uint8_t wait);

public:
    LEDController();
    void begin();
    void setMode(LEDMode mode);
    void update();
};

#endif // LEDCONTROLLER_H
