#include "EMController.hpp"
#include <cstdlib>

void EMController::manageEnergy(const PhotovoltaicPanel &pv, const House &house,
                                Grid &grid, StorageSystem &storageSystem) {
  if (pv.getPowerProduced() >= house.getPowerConsumed()) {
    // The power surplus form the storage system
    int surplus =
        storageSystem.charge(pv.getPowerProduced() - house.getPowerConsumed());
    // if there is surplus after charging the storage system send surplus to
    // grid
    if (surplus >= 0) {
      grid.charge(surplus);
    } else {
      grid.charge(0);
    }
  } else {
    // power needed after discharging the battaries from the storage system
    int powerNeeded = storageSystem.discharge(pv.getPowerProduced() -
                                              house.getPowerConsumed());

    // if powerNeeded is -ve then we still need power from grid
    if (powerNeeded < 0) {
      grid.discharge(std::abs(powerNeeded));
    } else {
      grid.discharge(0);
    }
  }
}