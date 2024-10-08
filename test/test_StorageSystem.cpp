#include "gtest/gtest.h"
#include "StorageSystem.hpp"
#include "Inverter.hpp"

TEST(StorageSystemTest, Constructor) {
  Inverter inverter(5000, 48, 100, 0, 50, 220);

  StorageSystem basicSystem(inverter, SystemSetup::BASIC);
  EXPECT_EQ(basicSystem.getSystemSetup(), SystemSetup::BASIC); 

  StorageSystem standardSystem(inverter, SystemSetup::STANDARD);
  EXPECT_EQ(standardSystem.getSystemSetup(), SystemSetup::STANDARD); 

  StorageSystem proSystem(inverter, SystemSetup::PRO);
  EXPECT_EQ(proSystem.getSystemSetup(), SystemSetup::PRO); 
}

TEST(StorageSystemTest, AddBatteryModule) {
  Inverter inverter(5000, 48, 100, 0, 50, 220);
  StorageSystem system(inverter, SystemSetup::STANDARD); 

  BatteryModule battery1(100, 50, 1000); 
  EXPECT_TRUE(system.addBatteryModule(battery1)); 

  BatteryModule battery2(100, 50, 1000); 
  EXPECT_TRUE(system.addBatteryModule(battery2)); 

  BatteryModule battery3(100, 50, 1000); 
  EXPECT_TRUE(system.addBatteryModule(battery3)); 

  BatteryModule battery4(100, 50, 1000);
  EXPECT_FALSE(system.addBatteryModule(battery4)); // Should fail (max 3 modules)
}

TEST(StorageSystemTest, Charge) {
  Inverter inverter(5000, 48, 100, 0, 50, 220);
  StorageSystem system(inverter, SystemSetup::BASIC);
  int result = system.charge(6000);
  EXPECT_EQ(result, 1000); // Should delegate to Inverter::charge()
}

TEST(StorageSystemTest, Discharge) {
  Inverter inverter(5000, 48, 100, 0, 50, 220);
  StorageSystem system(inverter, SystemSetup::BASIC);
  int result = system.discharge(-3000);
  EXPECT_EQ(result, 2000); // Should delegate to Inverter::discharge()
}