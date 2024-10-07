/**
 * @file Inverter.hpp
 * @brief Declaration of the Inverter class.
 */

#ifndef INVERTER_H
#define INVERTER_H

/**
 * @brief Device inside the Battery in charge of controlling the power flow to
 * the batteries and the values that can be read from it.
 */
class Inverter {
public:
  Inverter(const unsigned int &maxInverterPower,
           const unsigned int &battaryVoltage,
           const unsigned int &battaryCurrent, const int &outputPower,
           const unsigned int &gridFrequancy, const unsigned int &gridVoltage);

  unsigned int getMaxInverterPower() const;

private:
  /**
   * Maximum power that the inverter can charge/discharge in Watts.
   */
  unsigned int _maxInverterPower;
  /**
   * In Volts.
   */
  unsigned int _battaryVoltage;
  /**
   * Current that is flowing to/from inverter in Amps.
   */
  unsigned int _battaryCurrent;
  /**
   * Power inverter is releasing/storing in the batteries in Watts.
   * If +ve battaries are charging.
   * If -ve battaries are discharging.
   */
  int _outputPower;
  /**
   * Inverter sensed grid frequency in Hertz.
   */
  unsigned int _sensedGridFrequancy;
  /**
   * Inverter sensed grid Voltage in Volts.
   */
  unsigned int _sensedGridVoltage;
};

#endif // INVERTER_H