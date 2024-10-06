#include "PhotovoltaicPanel.hpp"

PhotovoltaicPanel::PhotovoltaicPanel(const unsigned int & power, const unsigned int & voltage, const unsigned int & current): _powerProduced(power), _voltageProduced(voltage), _currentProduced(current){};

unsigned int PhotovoltaicPanel::getPowerProduced() const {
    return _powerProduced;
}