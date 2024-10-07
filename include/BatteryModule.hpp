/**
 * @file BatteryModule.hpp
 * @brief Declaration of the BatteryModule class.
 */

#ifndef BATTERY_MODULE_H
#define BATTERY_MODULE_H

/**
 * @brief  Battery packs that can be connected into a storage system. and the
 * values that can be read from it.
 */
class BatteryModule {
public:
  BatteryModule(const unsigned int &temprature, const unsigned int &voltage,
                const unsigned int &power);
  unsigned int getPower() const;

private:
  /**
   * Module temperature in Celsius degrees.
   */
  unsigned int _temperature;
  /**
   * Module voltage in Volts
   */
  unsigned int _voltage;
  /**
   * Maximum power that the battery module can charge or discharge in Watts.
   */
  unsigned int _power;
};

#endif // BATTERY_MODULE_H