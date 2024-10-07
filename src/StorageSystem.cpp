#include "StorageSystem.hpp"

StorageSystem::StorageSystem(const Inverter &inverter,
                             const EMController &controller,
                             const SystemSetup &setup)
    : _inverter(inverter), _emController(controller), _setup(setup) {
  switch (_setup) {
  case SystemSetup::BASIC:
    // If system setup is basic number of battery modules is up to 2
    _batteryModules.reserve((std::size_t)SystemSetup::BASIC);
    break;
  case SystemSetup::STANDARD:
    // If system setup is basic number of battery modules is up to 3
    _batteryModules.reserve((std::size_t)SystemSetup::STANDARD);
    break;
  case SystemSetup::PRO:
    // If system setup is basic number of battery modules is up to 5
    _batteryModules.reserve((std::size_t)SystemSetup::PRO);
    break;
  }
}

SystemSetup StorageSystem::getSystemSetup() const {
    return _setup;
}

bool StorageSystem::addBatteryModule(const BatteryModule &batteryModule){
    if(_batteryModules.size() < (std::size_t)_setup) {
        _batteryModules.push_back(batteryModule);
        return true;
    } else {
        return false;
    }

}