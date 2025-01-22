#include <gtest/gtest.h>
#include "firewalker_controller.h"
#include "ble_controller.h"
#include "led_controller.h"

// TODO - May need to use object mocking to 

// TEST Construction
TEST(FireWalkerControllerTest, CanConstruct)
{
    FireWalkerController controller;
    // Only testing to see if we can safely construct
    SUCCEED();
}

TEST(FireWalkerControllerTest, InitReturnsTrueWhenSubsystemsAreOk)
{
    FireWalkerController controller;
    EXPECT_TRUE(controller.init);
}

TEST(FireWalkerControllerTest, SetLEDModeCallSuccessfully)
{
    FireWalkerController controller;
    controller.init();
    EXPECT_TRUE(controller.setLEDMode());
}
