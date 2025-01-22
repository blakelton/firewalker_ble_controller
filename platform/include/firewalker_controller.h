#ifndef FIREWALKERCONTROLLER_H
#define FIREWALKERCONTROLLER_H

/***********************************************************************
 * File Name: firewalker_controller.h
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Header file for the FireWalkerController class.
 * License: MIT License
 ***********************************************************************/

#include <memory>
#include "ble_controller.h"
#include "led_controller.h"

class FireWalkerController {
public:
    FireWalkerController();
    FireWalkerController(std::shared_ptr<BLEController> bleController,
                         std::shared_ptr<LEDController> ledController);

    // Initialize the FireWalkerController 
    bool init();
    bool setLEDMode();

private:
    //Subsystem Controllers
    std::shared_ptr<BLEController> _bleController;
    std::shared_ptr<LEDController> _ledController;
}

#endif // FIREWALKERCONTROLLER_H
