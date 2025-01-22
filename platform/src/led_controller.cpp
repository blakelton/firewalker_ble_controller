/***********************************************************************
 * File Name: led_controller.h
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Header file for the LEDController class.
 * License: MIT License
 ***********************************************************************/

#include "led_controller.h"

LEDController::LEDController(uint16_t pixelCount, uint16_t pinNumber){
    pixels = new Adafruit_NeoPixel(pixelCount, pinNumber, NEO_GRB + NEO_KHZ800)

}