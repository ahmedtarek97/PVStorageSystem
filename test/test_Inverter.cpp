#include "gtest/gtest.h"
#include "Inverter.hpp"

TEST(InverterTest, ConstructorAndGetter) {
  Inverter inverter(5000, 48, 100, 0, 50, 220); 
  EXPECT_EQ(inverter.getMaxInverterPower(), 5000);
}

TEST(InverterTest, Charge) {
  Inverter inverter(5000, 48, 100, 0, 50, 220);
  int result = inverter.charge(6000); 
  EXPECT_EQ(result, 1000); // surplus power is : 6000 - 5000 = 1000
}

TEST(InverterTest, DischargeNoPowerNeededFromGrid) {
  Inverter inverter(5000, 48, 100, 0, 50, 220);
  int result = inverter.discharge(-3000); 
  EXPECT_EQ(result, 2000); // -3000 + 5000 = 2000
}

TEST(InverterTest, DischargePowerNeededFromGrid) {
  Inverter inverter(5000, 48, 100, 0, 50, 220);
  int result = inverter.discharge(-6000); 
  EXPECT_EQ(result, -1000); // -6000 + 5000 = -1000
}