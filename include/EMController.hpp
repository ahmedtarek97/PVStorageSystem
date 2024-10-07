/**
 * @file EMController.hpp
 * @brief Declaration of the EMController class.
 */

#ifndef EM_CONTROLLER_H
#define EM_CONTROLLER_H

#include "Grid.hpp"
#include "House.hpp"
#include "PhotovoltaicPanel.hpp"
#include "StorageSystem.hpp"

/**
 * @brief handles the energy logic and issues all necessary commands to each of
 * the devices
 */
class EMController {
public:
  /**
   * @brief Handles the logic of the power Mangment
   *
   */
  void manageEnergy(const PhotovoltaicPanel &pv, const House &house, Grid &grid,
                    StorageSystem &storageSystem);

private:
};

#endif // EM_CONTROLLER_H