#include "BatteryModule.hpp"

BatteryModule::BatteryModule(const unsigned int &temprature,
                             const unsigned int &voltage,
                             const unsigned int &power)
    : _temperature(temprature), _voltage(voltage), _power(power) {}

unsigned int BatteryModule::getPower() const { return _power; }