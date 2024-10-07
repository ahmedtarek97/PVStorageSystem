/**
 * @file Grid.hpp
 * @brief Declaration of the Grid class.
 */

#ifndef GRID_H
#define GRID_H

/**
 * @brief  Main connection from the house to the utility provider grid and the
 * values that can be read from it.
 */
class Grid {
public:
  Grid(const unsigned int &powerSold, const unsigned int &powerBought,
       const unsigned int &voltage, const unsigned int &frequency);
  unsigned int getPowerSold() const;
  unsigned int getPowerBought() const;

private:
  /**
   * Power that is sold to the grid in Watts.
   */
  unsigned int _powerSold;   
  /**
   * Power that is bought from the grid in Watts.
   */
  unsigned int _powerBought; 
  /**
   * Grid voltage in Volts.
   */
  unsigned int _voltage;
  /**
   * Grid frequency in Hertz. 
   */     
  unsigned int _frequency;   
};

#endif // GRID_H
