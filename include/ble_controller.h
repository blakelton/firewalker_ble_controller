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
#include <string>
#include <functional>

class BLEController
{
public:
    BLEController();
    bool begin();
    void update();
    //Callback for when a new mode is recieved
    void setModeChangedCallback(std::function<void(int)> callback);

private:
    BLEService _bleService;
    BLEByteCharacteristic _ledCharacteristic;
    std::string _advertisingName;
    bool isRunning;

    // callback for mode
    std::function<void(int)> _modeChangedCallback;

    // static event handler function and pointer
    static BLEController* instance;
    static void onCharacteristicWritten(BLEDevice central, BLECharacteristic characteristic);
};

#endif // BLECONTROLLER_H
