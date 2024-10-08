/**
 * @file StorageSystem.hpp
 * @brief Declaration of the StorageSystem class.
 */

#ifndef STORAGE_SYSTEM_H
#define STORAGE_SYSTEM_H

#include "BatteryModule.hpp"
#include "Inverter.hpp"
#include <vector>

enum class SystemSetup { BASIC = 2, STANDARD = 3, PRO = 5 };

/**
 * @brief Storage system consists of an inverter, a controller and battery
 * modules based on the system setup . It can release energy from the battery
 * modules into the house grid or store energy from the house grid into the
 * batterymodules
 */
class StorageSystem {
public:
  StorageSystem(const Inverter &inverter, const SystemSetup &setup);

  SystemSetup getSystemSetup() const;
  /**
   * @brief Add battery module to the storage system if the system type allows
   * it
   * @param batteryModule Battery module which we want to add to the system
   * @return true if the battery module is added successfully
   * @return false if storage system reached the maximum number of battery
   * modules based on the system setup
   */
  bool addBatteryModule(const BatteryModule &batteryModule);
  /**
   * @brief Charge the Storage System Batteries
   *
   * @param power +ve value in Watts which the system will charge with
   *
   * @return int The surplus after charging the batteries with the max power
   */
  int charge(int power);
  /**
   * @brief Discharge the Storage System Batteries
   *
   * @param power -ve value in Watts which the system will discharge with
   *
   * @return int The power needed after discharging the batteries with the max
   * power
   */
  int discharge(int power);

private:
  Inverter _inverter;
  std::vector<BatteryModule> _batteryModules;
  /**
   * @brief Basic setup contains up to 2 battery modules.
   * Standard setup contains up to 3 battery modules.
   * Pro setup contains up to 5 battery modules.
   */
  SystemSetup _setup;
  /**
   * @brief if +ve value in Watts then batteries are charging
   * if -ve value in Watts then battries are discharging
   */
  int _powerCommand;
};

#endif // STORAGE_SYSTEM_H