#include "Grid.hpp"

Grid::Grid(const unsigned int &powerSold, const unsigned int &powerBought,
           const unsigned int &voltage, const unsigned int &frequency)
    : _powerSold(powerSold), _powerBought(powerBought), _voltage(voltage),
      _frequency(frequency) {}

unsigned int Grid::getPowerBought() const { return _powerBought; }

unsigned int Grid::getPowerSold() const { return _powerSold; }