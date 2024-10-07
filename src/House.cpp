#include "House.hpp"

House::House(const unsigned int &powerConsumed, const unsigned int &voltage,
             const unsigned int &frequency, const unsigned int &current)
    : _powerConsumed(powerConsumed), _voltage(voltage), _frequency(frequency),
      _current(current) {}

unsigned int House::getPowerConsumed() const { return _powerConsumed; }
