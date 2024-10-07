/**
 * @file PhotovoltaicPanel.hpp
 * @brief Declaration of the PhotovoltaicPanel class.
 */

#ifndef PHOTOVOLTAIC_PANEL_H
#define PHOTOVOLTAIC_PANEL_H

/**
 * @brief Represents a photovoltic panel and the values that can be read from
 * it.
 */
class PhotovoltaicPanel {
public:
  PhotovoltaicPanel(const unsigned int &power, const unsigned int &voltage,
                    const unsigned int &current);
  unsigned int getPowerProduced() const;

private:
  /**
   * Power the PV is producing in Watts.
   */
  unsigned int _powerProduced;
  /**
   * Voltage that the PV is producing in Volts.
   */
  unsigned int _voltageProduced;
  /**
   * Current that the PV is producing in Amp.
   */
  unsigned int _currentProduced;
};

#endif // PHOTOVOLTAIC_PANEL_H