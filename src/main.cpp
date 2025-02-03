/***********************************************************************
 * File Name: main.cpp
 * Author(s): Blake Azuela
 * Date Created: 2025-02-01
 * Description: Starting point for the firewalker project.
 * License: MIT License
 ***********************************************************************/
#include <Arduino.h>

#include "firewalker_controller.h"
#include "ble_controller.h"
#include "led_controller.h"


// TODO: Make these global singltons
std::shared_ptr<FireWalkerController> fwCtrl;

void setup()
{
    // Setup serial monitor speed
    Serial.begin(115200);

    // Creating Controller Classes
    fwCtrl = std::make_shared<FireWalkerController>();

    // Initialize the controller classes
    bool ok = fwCtrl->init();
    if(ok)
    {
        Serial.println("FireWalkerController initialized successfully.");
    } 
    else 
    {
        Serial.println("FireWalkerController failed to initialize.");
    }

}

void loop()
{  
    // Update the controller classes
    fwCtrl->update();
}