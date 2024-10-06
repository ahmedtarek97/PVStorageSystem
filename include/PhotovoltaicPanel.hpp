/**
 * @file PhotovoltaicPanel.hpp
 * @brief Contains the declaration of the PhotovoltaicPanel class.
 */

#ifndef PHOTOVOLTAIC_PANEL_H  
#define PHOTOVOLTAIC_PANEL_H

/**
 * @brief Represents a photovoltic panel and the values that can be read from it.
 */
class PhotovoltaicPanel{
public:
    /**
     * @brief Constructor for the PhotovoltaicPanel class.
     * @param power Amount of power the PV is producing in Watts.
     * @param voltage Voltage that the PV is producing in Volts.
     * @param current Current that the PV is producing in Amp.
     */
    PhotovoltaicPanel(const unsigned int & power, const unsigned int & voltage, const unsigned int & current);

    /**     
     * @returns the amount of power the PV is producing in Watts
     */
    unsigned int getPowerProduced() const;   
      
private:
    unsigned int _powerProduced;     ///< Amount of power the PV is producing in Watts.
    unsigned int _voltageProduced;   ///< Voltage that the PV is producing in Volts.
    unsigned int _currentProduced;   ///< Current that the PV is producing in Amp.
};

#endif // PHOTOVOLTAIC_PANEL_H 