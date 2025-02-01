/***********************************************************************
 * File Name: ble_controller.cpp
 * Author(s): Blake Azuela
 * Date Created: 2024-05-06
 * Description: Source code file for the BLEController class.
 * License: MIT License
 ***********************************************************************/

#include "ble_controller.h"

// Define the static instance pointer
BLEController* BLEController::instance = nullptr;

BLEController::BLEController()
: _bleService("19B10000-E8F2-537E-4F6C-D104768A1214"), // Custom service UUID
  _ledCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite),
  isRunning(false)  
{   
    _advertisingName = "FireWalkerBT";
    instance = this;
}


bool BLEController::begin()
{
    // Intialize BLE Hardware
    if(!BLE.begin()) 
    {
        Serial.println("Error: BLE initialization failed!");
        return false;
    }

    // Set the BLE device local name for advertising
    BLE.setLocalName(_advertisingName.c_str());

    // Set the service that should be advertised
    BLE.setAdvertisedService(_bleService);

    // Add characteristic to the service
    _bleService.addCharacteristic(_ledCharacteristic);

    //Register the custom service with the BLE stack
    BLE.addService(_bleService);

    // Set initial value for the characteristics
    _ledCharacteristic.writeValue(0);

    // Register event handling
    _ledCharacteristic.setEventHandler(BLEWritten, BLEController::onCharacteristicWritten);

    // Start advertising the BLE service
    BLE.advertise();

    Serial.println("BLE Service is Advertising.");

    isRunning = true;
    return true;
}

void BLEController::setModeChangedCallback(std::function<void(int)> callback)
{
    _modeChangedCallback = callback;
}

void BLEController::onCharacteristicWritten(BLEDevice central, BLECharacteristic characteristic)
{
        if (characteristic.valueLength() > 0) 
        {
            int newMode = characteristic.value()[0];
            Serial.println("New mode received over BLE: ");
            Serial.println(newMode);
            if(instance && instance->_modeChangedCallback) 
            {
                instance->_modeChangedCallback(newMode);
            }
        }
}