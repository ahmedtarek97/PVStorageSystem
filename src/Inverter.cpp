#include "Inverter.hpp"

Inverter::Inverter(const unsigned int &maxInverterPower,
                   const unsigned int &battaryVoltage,
                   const unsigned int &battaryCurrent, const int &outputPower,
                   const unsigned int &gridFrequancy,
                   const unsigned int &gridVoltage)
    : _maxInverterPower(maxInverterPower), _battaryVoltage(battaryVoltage),
      _battaryCurrent(battaryCurrent), _outputPower(outputPower),
      _sensedGridFrequancy(gridFrequancy), _sensedGridVoltage(gridVoltage) {}

unsigned int Inverter::getMaxInverterPower() const {
    return _maxInverterPower;
}