#ifndef BLECONTROLLER_H
#define BLECONTROLLER_H

/***********************************************************************
 * File Name: ble_controller.h
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Header file for the BLEController class.
 * License: MIT License
 ***********************************************************************/

#include <ArduinoBLE.h>
#include "i_ble_controller.h"

class BLEController
{
    bool isRunning;
    virtual bool begin() override;
};

#endif // BLECONTROLLER_H
