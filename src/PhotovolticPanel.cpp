#include "PhotovolticPanel.hpp"

PhotovolticPanel::PhotovolticPanel(unsigned int power, unsigned int voltage, unsigned int current): _powerProduced(power), _voltageProduced(voltage), _currentProduced(current){};

unsigned int PhotovolticPanel::getPowerProduced(){
    return _powerProduced;
}