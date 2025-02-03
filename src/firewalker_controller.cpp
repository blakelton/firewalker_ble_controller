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
        Serial.println("Setting LED Off");
        newMode = LEDMode::LEDOff;
        break;
    case 1: 
        Serial.println("Setting Color Wipe");
        newMode = LEDMode::ColorWipe;
        break;
    case 2: 
        Serial.println("Setting Theater Chase");
        newMode = LEDMode::TheaterChase;
        break;
    case 3: 
        Serial.println("Setting Rainbow");
        newMode = LEDMode::Rainbow;
        break;
    default:
        Serial.println("Setting Default Mode - Carousel");
        newMode = LEDMode::Carousel;
        break;
    }
    _ledController->setMode(newMode);
    });
    return (bleInitialized);
}

void FireWalkerController::update()
{
    _bleController->update();
    _ledController->update();
}