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
#include "i_ble_controller.h"
#include "i_led_controller.h"

class FireWalkerController {
public:
    FireWalkerController();
    FireWalkerController(std::shared_ptr<IBLEController> ble,
                         std::shared_ptr<ILEDController> led);

    // Initialize the FireWalkerController 
    bool init();
    bool setLEDMode();

private:
    //Subsystem Controllers
    std::shared_ptr<IBLEController> _bleController;
    std::shared_ptr<ILEDController> _ledController;
};

#endif // FIREWALKERCONTROLLER_H
