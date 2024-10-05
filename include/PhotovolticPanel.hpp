/**
 * \file PhotovolticPanel.hpp
 * \brief This file contains the declaration of the PhotovolticPanel class.
 */

#ifndef PHOTOVOLTIC_PANEL_H
#define PHOTOVOLTIC_PANEL_H

/**
 * \brief This class represents a photovoltic panel and the values that can be read from it.
 */
class PhotovolticPanel{
public:
    /**
     * \brief Constructor for the PhotovolticPanel class.
     * \param power Amount of power the PV is producing in Watts.
     * \param voltage Voltage that the PV is producing in Volts.
     * \param current urrent that the PV is producing in Amp.
     */
    PhotovolticPanel(unsigned int power, unsigned int voltage, unsigned int current);

    /**
     * \brief Gets the amount of power the PV is producing in Watts
     * 
     * \returns the amount of power the PV is producing in Watts
     */
    unsigned int getPowerProduced();   
      
private:
    unsigned int _powerProduced;     // Amount of power the PV is producing in Watts.
    unsigned int _voltageProduced;   // Voltage that the PV is producing in Volts.
    unsigned int _currentProduced;   // Current that the PV is producing in Amp.
};

#endif // PHOTOVOLTIC_PANEL_H 