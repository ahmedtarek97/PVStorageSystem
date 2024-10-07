#include "Grid.hpp"
#include "House.hpp"
#include "Inverter.hpp"
#include "PhotovoltaicPanel.hpp"
#include "BatteryModule.hpp"
#include "EMController.hpp"
#include "StorageSystem.hpp"
#include <iostream>

using namespace std;

int main() {
  PhotovoltaicPanel p1(2, 3, 5);
  Grid g1(4, 5, 6, 7);
  House h1(10, 11, 12, 13);
  Inverter i1(1, 2, 3, 4, 5, 6);
  BatteryModule b1(3,6,9);
  EMController c1;
  StorageSystem ss1(i1,SystemSetup::STANDARD);
  cout << p1.getPowerProduced() << endl
       << g1.getPowerSold() << endl
       << g1.getPowerBought() << endl
       << h1.getPowerConsumed() << endl
       << i1.getMaxInverterPower() << endl
       << b1.getPower() << endl
       << (int) ss1.getSystemSetup()<<endl;
}