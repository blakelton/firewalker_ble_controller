/***********************************************************************
 * File Name: led_controller.h
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Header file for the LEDController class.
 * License: MIT License
 ***********************************************************************/

#include "led_controller.h"

LEDController::LEDController()
: _pixels(LED_PIN, LED_COUNT, NEO_GRB + NEO_KHZ800)
{
}


bool LEDController::begin()
{
    _pixels.begin();
    retrun true;
}

bool LEDController::setMode()
{
    return true;
}