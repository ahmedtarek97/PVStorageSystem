#include "gtest/gtest.h"
#include "BatteryModule.hpp" 

TEST(BatteryModuleTest, ConstructorAndGetter) {
  unsigned int temp = 25;
  unsigned int voltage = 48;
  unsigned int power = 100;
  BatteryModule module1(temp, voltage, power);
  EXPECT_EQ(module1.getPower(), power);
}