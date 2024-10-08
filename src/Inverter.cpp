#include "Inverter.hpp"

Inverter::Inverter(const unsigned int &maxInverterPower,
                   const unsigned int &batteryVoltage,
                   const unsigned int &batteryCurrent, const int &outputPower,
                   const unsigned int &gridFrequancy,
                   const unsigned int &gridVoltage)
    : _maxInverterPower(maxInverterPower), _batteryVoltage(batteryVoltage),
      _batteryCurrent(batteryCurrent), _outputPower(outputPower),
      _sensedGridFrequancy(gridFrequancy), _sensedGridVoltage(gridVoltage) {}

unsigned int Inverter::getMaxInverterPower() const { return _maxInverterPower; }

int Inverter::charge(const int &power) {
  _outputPower = power;
  return power - _maxInverterPower;
}

int Inverter::discharge(const int &power) {
  _outputPower = power;
  return power + _maxInverterPower;
}
