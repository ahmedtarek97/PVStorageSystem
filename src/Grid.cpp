#include "Grid.hpp"

Grid::Grid(const unsigned int &voltage, const unsigned int &frequency)
    : _powerSold(0), _powerBought(0), _voltage(voltage),
      _frequency(frequency) {}

unsigned int Grid::getPowerBought() const { return _powerBought; }

unsigned int Grid::getPowerSold() const { return _powerSold; }

void Grid::charge(int power) {
  _powerSold = power;
  _powerBought = 0;
}

void Grid::discharge(int power) {
  _powerSold = 0;
  _powerBought = power;
}
