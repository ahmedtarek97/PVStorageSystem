/**
 * @file House.hpp
 * @brief Declaration of the House class.
 */

#ifndef HOUSE_H
#define HOUSE_H

/**
 * @brief  Measurement point of all house connected loads and the values that
 * can be read from it.
 */
class House {
public:
  House(const unsigned int &powerConsumed, const unsigned int &voltage,
        const unsigned int &frequency, const unsigned int &current);
  unsigned int getPowerConsumed() const;

private: 
  /**
   * Power that is going into the house in Watts. 
   */
  unsigned int _powerConsumed; 
  /**
   * Voltage of the house grid in Volts.
   */
  unsigned int _voltage;
  /**
   * Frequency of the house grid in Hertz. 
   */
  unsigned int _frequency;
  /**
   * Current flowing into the house in Amps.
   */
  unsigned int _current;       
};

#endif // HOUSE_H
