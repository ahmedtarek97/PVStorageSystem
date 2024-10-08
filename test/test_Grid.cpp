#include "gtest/gtest.h"
#include "Grid.hpp"

TEST(GridTest, ConstructorAndGetter) {
  Grid grid(220, 50); 
  EXPECT_EQ(grid.getPowerSold(), 0);
  EXPECT_EQ(grid.getPowerBought(), 0);
}

TEST(GridTest, Charge) {
  Grid grid(220, 50);
  grid.charge(80); 
  EXPECT_EQ(grid.getPowerSold(), 80);
  EXPECT_EQ(grid.getPowerBought(), 0);
}

TEST(GridTest, Discharge) {
  Grid grid(220, 50);
  grid.discharge(70); 
  EXPECT_EQ(grid.getPowerSold(), 0);
  EXPECT_EQ(grid.getPowerBought(), 70);
}