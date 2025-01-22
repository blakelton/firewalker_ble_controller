/***********************************************************************
 * File Name: firewalker_controller.cpp
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Header file for the FireWalkerController class.
 * License: MIT License
 ***********************************************************************/

#include "firewalker_controller.h"

FireWalkerController::FireWalkerController()
{
    //When no controllers are injected, set them by default here
    _bleController = std::make_shared<BLEController>();
    _ledController = std::make_shared<LEDController>();
}

FireWalkerController::FireWalkerController(std::shared_ptr<BLEController> bleController,
                                           std::shared_ptr<LEDController> ledController)
: _bleController(bleController), _ledController(ledController)
{
}

bool FireWalkerController::init()
{
    bool bleInitialized = _bleController->begin();
    bool ledInitialized = _ledController->begin();

    return (bleInitialized && ledInitialized);
}

bool FireWalkerController::setLEDMode()
{
    //TODO
    return _ledController->setMode();
}