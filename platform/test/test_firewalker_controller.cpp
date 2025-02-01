#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#include "firewalker_controller.h" // The class under test

// Include Mocks
#include "mock_ble_controller.h"
#include "mock_led_controller.h"

using ::testing::Exactly;
using ::testing::Return;
using ::testing::_;

// TEST Construction
TEST(FireWalkerControllerTest, Init_CallsBeginOnBothControllers_ReturnsTrueIfBothSucceed)
{
    auto mockBLE = std::make_shared<MockBLEController>();
    auto mockLED = std::make_shared<MockLEDController>();

    EXPECT_CALL(*mockBLE, begin()).Times(Exactly(1)).WillOnce(Return(true));
    EXPECT_CALL(*mockLED, begin()).Times(Exactly(1)).WillOnce(Return(true));

    FireWalkerController fw(mockBLE, mockLED);

    bool result = fw.init();

    EXPECT_TRUE(result) 
        << "FireWalkerController::init() should return true if both subsystems are OK.";
}


TEST(FireWalkerControllerTest, SetLEDMode_CallsControllerSetLEDMode_ReturnsTrueIfSuccessful)
{
    auto mockBLE = std::make_shared<MockBLEController>();
    auto mockLED = std::make_shared<MockLEDController>();

    EXPECT_CALL(*mockLED, setMode()).Times(Exactly(1)).WillOnce(Return(true));

    FireWalkerController fw(mockBLE, mockLED);

    bool result = fw.setLEDMode();

    EXPECT_TRUE(result)
    << "FireWalkerController::setLEDMode() should return true if LEDController code is OK.";
}