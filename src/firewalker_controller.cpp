/***********************************************************************
 * File Name: firewalker_controller.cpp
 * Author(s): Blake Azuela
 * Date Created: 2025-02-01
 * Description: Header file for the FireWalkerController class.
 * License: MIT License
 ***********************************************************************/

#include "firewalker_controller.h"
#include "ble_controller.h"
#include "led_controller.h"

FireWalkerController::FireWalkerController()
{
    //When no controllers are injected, set them by default here
    _bleController = std::make_shared<BLEController>();
    _ledController = std::make_shared<LEDController>();
}

FireWalkerController::FireWalkerController(std::shared_ptr<BLEController> ble,
                                           std::shared_ptr<LEDController> led)
: _bleController(ble), _ledController(led)
{
}

bool FireWalkerController::init()
{
    bool bleInitialized = _bleController->begin();
    _ledController->begin();

    // Registering the callback from BLEController to handle mode changes
    _bleController->setModeChangedCallback([this](int mode){
    LEDMode newMode;
    //TODO: Make proper mapping from mobile app side
    switch (mode)
    {
    case 0: 
        newMode = LEDMode::LEDOff;
        break;
    case 1: 
        newMode = LEDMode::ColorWipe;
        break;
    case 2: 
        newMode = LEDMode::TheaterChase;
        break;
    case 3: 
        newMode = LEDMode::Wheel;
        break;
    case 4: 
        newMode = LEDMode::Rainbow;
        break;
    default:
        newMode = LEDMode::Carousel;
        break;
    }
    Serial.println("Setting LED mode to:");
    Serial.println(mode);
    // TODO: once proper mapping is set update this line
    // _ledController->setMode(newMode);
    _ledController->setMode(LEDMode::Rainbow);
    });
    return (bleInitialized);
}

void FireWalkerController::update()
{
    _ledController->update();
}