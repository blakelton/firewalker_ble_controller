#ifndef I_LEDCONTROLLER_H
#define I_LEDCONTROLLER_H
/***********************************************************************
 * File Name: i_led_controller.h
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Interface file for the LEDController class. Require for
 * object mocks.
 * License: MIT License
 ***********************************************************************/

#include <stdint.h>

class ILEDController {
public:
    virtual ~ILEDController() = default;

    // Called to initialize LEDs. Return true if successful. 
    virtual bool begin() = 0;

    // Called to set the ledControllerMode
    virtual bool setMode() = 0;
    
};

#endif // I_LEDCONTROLLER_H
