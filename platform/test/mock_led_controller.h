#ifndef MOCK_LED_CONTROLLER_H
#define MOCK_LED_CONTROLLER_H

#include <gmock/gmock.h>
#include "i_led_controller.h"

class MockLEDController : public ILEDController
{
public:
    MOCK_METHOD(bool, begin, (), (override));
    MOCK_METHOD(bool, setMode, (), (override));
};

#endif // MOCK_LED_CONTROLLER_H
