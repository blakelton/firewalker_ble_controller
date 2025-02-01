#ifndef I_BLECONTROLLER_H
#define I_BLECONTROLLER_H
/***********************************************************************
 * File Name: i_ble_controller.h
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Interface file for the BLEController class. Require for
 * object mocks.
 * License: MIT License
 ***********************************************************************/

class IBLEController
{
public:
    virtual ~IBLEController() = default;

    // Called to iniitalize BLE. Return true if successful
    virtual bool begin() = 0;

};

#endif // I_BLECONTROLLER_H