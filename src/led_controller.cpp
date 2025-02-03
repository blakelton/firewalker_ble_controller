/***********************************************************************
 * File Name: led_controller.cpp
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Source file for the LEDController class.
 * License: MIT License
 ***********************************************************************/

#include "led_controller.h"

LEDController::LEDController()
:   _pixelPrevious(0),
    _patternPrevious(0),
    _patternCurrent(0),
    _patternInterval(5000),
    _patternComplete(false),
    _pixelInterval(50),
    _pixelQueue(0),
    _pixelCycle(0),
    _pixelNumber(LED_COUNT),
    _previousMode(LEDMode::LEDOff),
    _currentMode(LEDMode::Rainbow)
{
    _pixels = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED Controller Initialized");
}


void LEDController::begin()
{
    _pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    _pixels.clear();  // Initialize all pixels to 'off'
    _pixels.show();  // Turn OFF all pixels 
}

void LEDController::setMode(LEDMode mode)
{
    _currentMode = mode;
    _patternComplete = false;
    _pixelCycle = 0;
    _pixelQueue = 0;
    this->update();
}

void LEDController::update()
{
    //if (_currentMode == _previousMode) return;
    // This function is intended to run frequently
    switch (_currentMode)
    {
        case LEDMode::LEDOff:
            Serial.println("LED Mode: Off");
            _pixels.clear();
            _pixels.show();
            break;
        case LEDMode::ColorWipe:
            Serial.println("LED Mode: Color Wipe");
            colorWipe(_pixels.Color(255,0,0), 50);
            break;
        case LEDMode::TheaterChase:
            Serial.println("LED Mode: Theater Chase");
            theaterChase(_pixels.Color(127,127,127), 50);
            break;
        case LEDMode::Rainbow:
            Serial.println("LED Mode: Rainbow");
            rainbow(50);
            break;       
        case LEDMode::TheaterChaseRainbow:
            Serial.println("LED Mode: Theater Chase Rainbow");
            theaterChaseRainbow(50);
            break;      
        default:
            //TODO create Carousel Effect - for now, default to TheaterChaseRainbow
            Serial.println("Default Mode");
            theaterChaseRainbow(50);
            break;
    }
    _previousMode = _currentMode;
}


// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void LEDController::colorWipe(uint32_t color, int wait) 
{
    static uint16_t current_pixel = 0;
    _pixelInterval = wait;                        //  Update delay time
    _pixels.setPixelColor(current_pixel++, color); //  Set pixel's color (in RAM)
    _pixels.show();                                //  Update strip to match
    if(current_pixel >= LED_COUNT)             //  Loop the pattern from the first LED
    {           
        current_pixel = 0;
        _patternComplete = true;
    }
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void LEDController::theaterChase(uint32_t color, int wait) 
{
    static uint32_t loop_count = 0;
    static uint16_t current_pixel = 0;

    _pixelInterval = wait;                   //  Update delay time

    _pixels.clear();

    for(int c=current_pixel; c < LED_COUNT; c += 3) 
    {
        _pixels.setPixelColor(c, color);
    }
    _pixels.show();

    current_pixel++;
    if (current_pixel >= 3) 
    {
        current_pixel = 0;
        loop_count++;
    }

    if (loop_count >= 10) 
    {
        current_pixel = 0;
        loop_count = 0;
        _patternComplete = true;
    }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t LEDController::wheel(byte wheelPos) 
{
    wheelPos = 255 - wheelPos;
    if(wheelPos < 85) 
    {
        return _pixels.Color(255 - wheelPos * 3, 0, wheelPos * 3);
    }
    if(wheelPos < 170) 
    {
        wheelPos -= 85;
        return _pixels.Color(0, wheelPos * 3, 255 - wheelPos * 3);
    }
    wheelPos -= 170;
    return _pixels.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
}

// Rainbow cycle along whole _pixels. Pass delay time (in ms) between frames.
void LEDController::rainbow(uint8_t wait) 
{
    if(_pixelInterval != wait) _pixelInterval = wait;                   
    for(uint16_t i=0; i < _pixelNumber; i++) 
    {
        _pixels.setPixelColor(i, this->wheel((i + _pixelCycle) & 255)); //  Update delay time  
    }
    _pixels.show();                           //  Update _pixels to match
    _pixelCycle++;                            //  Advance current cycle
    if(_pixelCycle >= 256) _pixelCycle = 0;   //  Loop the cycle back to the begining
}

//Theatre-style crawling lights with rainbow effect
void LEDController::theaterChaseRainbow(uint8_t wait) 
{
    if(_pixelInterval != wait) _pixelInterval = wait;    //  Update delay time  
    for(int i=0; i < _pixelNumber; i+=3) 
    {
        _pixels.setPixelColor(i + _pixelQueue, 
        this->wheel((i + _pixelCycle) % 255)); //  Update delay time  
    }
    _pixels.show();
    for(int i=0; i < _pixelNumber; i+=3) 
    {
        _pixels.setPixelColor(i + _pixelQueue, _pixels.Color(0, 0, 0)); //  Update delay time  
    }      
    _pixelQueue++;                           //  Advance current queue  
    _pixelCycle++;                           //  Advance current cycle
    if(_pixelQueue >= 3) _pixelQueue = 0;    //  Loop
    if(_pixelCycle >= 256) _pixelCycle = 0;  //  Loop
}