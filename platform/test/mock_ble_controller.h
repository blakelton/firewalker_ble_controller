#ifndef MOCK_BLE_CONTROLLER_H
#define MOCK_BLE_CONTROLLER_H

#include <gmock/gmock.h>
#include "i_ble_controller.h"

class MockBLEController : public IBLEController
{
    public:
        MOCK_METHOD(bool, begin, (), (override));

};

#endif // MOCK_BLE_CONTROLLER_H
