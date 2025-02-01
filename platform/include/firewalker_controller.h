#ifndef FIREWALKERCONTROLLER_H
#define FIREWALKERCONTROLLER_H

/***********************************************************************
 * File Name: firewalker_controller.h
 * Author(s): Blake Azuela
 * Date Created: 2025-02-01
 * Description: Header file for the FireWalkerController class.
 * License: MIT License
 ***********************************************************************/

#include <memory>
#include "ble_controller.h"
#include "led_controller.h"

class FireWalkerController {
public:
    FireWalkerController();
    FireWalkerController(std::shared_ptr<BLEController> ble,
                         std::shared_ptr<LEDController> led);

    // Initialize the FireWalkerController 
    bool init();
    void update();

private:
    //Subsystem Controllers
    std::shared_ptr<BLEController> _bleController;
    std::shared_ptr<LEDController> _ledController;
};

#endif // FIREWALKERCONTROLLER_H
