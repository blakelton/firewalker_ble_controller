/***********************************************************************
 * File Name: led_controller.h
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Header file for the LEDController class.
 * License: MIT License
 ***********************************************************************/
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ble_controller.h"
#include "led_controller.h"
#include "firewalker_controller.h"

#if defined(ARDUINO)
#include <Arduino.h>


// TODO: Make these global singltons
std::shared_ptr<IBLEController> bleCtrl;
std::shared_ptr<ILEDController> ledCtrl;
std::shared_ptr<FireWalkerController> fwCtrl;

void setup()
{
    // Setup serial monitor speed
    Serial.begin(115200);

    //Intialize Testing
    ::testing::InitGoogleTest();

    // Creating Controller Classes
    bleCtrl = std::make_shared<BLEController>();
    ledCtrl = std::make_shared<LEDController>();
    fwCtrl = std::make_shared<FireWalkerController>(bleCtrl, ledCtrl);

    // Initialize the controller classes
    bool ok = fwCtrl->init();
    if(ok)
    {
        Serial.println("FireWalkerController failed to initialize.");
    } 
    else 
    {
        Serial.println("FireWalkerController initialized successfully");

    }
    fwCtrl.setLEDMode();
}

void loop()
{
  

}
#else
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    // if you plan to use GMock, replace the line above with
    // ::testing::InitGoogleMock(&argc, argv);

    if (RUN_ALL_TESTS())
    ;

    // Always return zero-code and allow PlatformIO to parse results
    return 0;
}
#endif
