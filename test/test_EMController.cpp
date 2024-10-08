#include "EMController.hpp"
#include "Grid.hpp"
#include "House.hpp"
#include "Inverter.hpp"
#include "PhotovoltaicPanel.hpp"
#include "StorageSystem.hpp"
#include "gtest/gtest.h"

class EMControllerTest : public ::testing::Test {
protected:
  void SetUp() override {
    inverter = std::make_unique<Inverter>(5000, 48, 100, 0, 50, 220);
    storageSystem =
        std::make_unique<StorageSystem>(*inverter, SystemSetup::BASIC);
    grid = std::make_unique<Grid>(220, 50);
    controller = std::make_unique<EMController>();
  }

  std::unique_ptr<Inverter> inverter;
  std::unique_ptr<StorageSystem> storageSystem;
  std::unique_ptr<Grid> grid;
  std::unique_ptr<EMController> controller;
};

TEST_F(EMControllerTest, PVProductionGreaterThanHouseConsumption) {
  PhotovoltaicPanel pv(10000, 220, 20); // PV producing 10000W
  House house(6000, 220, 50, 20);       // House consuming 6000W

  controller->manageEnergy(pv, house, *grid, *storageSystem);

  // Expect storage system to be charging with the surplus (10000 - 6000 = 4000)
  // No surplus to the grid as the inverter charges with 5000 Watts to the house
  EXPECT_EQ(grid->getPowerSold(), 0);
  EXPECT_EQ(grid->getPowerBought(), 0);
}

TEST_F(EMControllerTest, PVProductionGreaterThanHouseConsumptionSendToGrid) {
  PhotovoltaicPanel pv(10000, 220, 20); // PV producing 10000W
  House house(2000, 220, 50, 20);       // House consuming 2000W

  controller->manageEnergy(pv, house, *grid, *storageSystem);

  // Expect storage system to be charging with the surplus (10000 - 2000 = 8000)
  // surplus is 3000 Watts go to the grid as the inverter charges with 5000
  // Watts to the house
  EXPECT_EQ(grid->getPowerSold(), 3000);
  EXPECT_EQ(grid->getPowerBought(), 0);
}

TEST_F(EMControllerTest, PVProductionLessThanHouseConsumption) {
  PhotovoltaicPanel pv(4000, 220, 20); // PV producing 4000W
  House house(7000, 220, 50, 20);      // House consuming 7000W

  controller->manageEnergy(pv, house, *grid, *storageSystem);

  // Expect storage system to be discharging to cover the deficit (4000 - 7000 =
  // -3000) No power needed from the grid as the inverter discharges with 5000
  // Watts
  EXPECT_EQ(grid->getPowerBought(), 0);
  EXPECT_EQ(grid->getPowerSold(), 0);
}

TEST_F(EMControllerTest, PVProductionLessThanHouseConsumptionGetPowerFomGrid) {
  PhotovoltaicPanel pv(1000, 220, 20); // PV producing 1000W
  House house(7000, 220, 50, 20);      // House consuming 7000W

  controller->manageEnergy(pv, house, *grid, *storageSystem);

  // Expect storage system to be discharging to cover the deficit (1000 - 7000 =
  // -6000) power is needed from the grid as the inverter discharges with 5000
  // Watts and we need 1000 Watt from grid
  EXPECT_EQ(grid->getPowerBought(), 1000);
  EXPECT_EQ(grid->getPowerSold(), 0);
}

TEST_F(EMControllerTest, PVProductionEqualsHouseConsumption) {
  PhotovoltaicPanel pv(5000, 220, 20); // PV producing 5000W
  House house(5000, 220, 50, 20);      // House consuming 5000W

  controller->manageEnergy(pv, house, *grid, *storageSystem);

  // Expect no change in grid or storage system
  EXPECT_EQ(grid->getPowerBought(), 0);
  EXPECT_EQ(grid->getPowerSold(), 0);
}