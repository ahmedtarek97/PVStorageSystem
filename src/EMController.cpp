#include "EMController.hpp"
#include <iostream>

void EMController::manageEnergy(const PhotovoltaicPanel &pv, const House &house,
                                Grid &grid, StorageSystem &storageSystem) {
  std::cout << "Energy is being managed ..." << std::endl;
  if (pv.getPowerProduced() >= house.getPowerConsumed()) {
    int surplus =
        storageSystem.charge(pv.getPowerProduced() - house.getPowerConsumed());

    if (surplus > 0) {
      grid.charge(surplus);
    }
  } else {
        int powerNeeded = storageSystem.discharge(pv.getPowerProduced() - house.getPowerConsumed());
        if(powerNeeded < 0){
            grid.discharge(powerNeeded);
        }
  }
}