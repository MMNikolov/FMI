#ifndef THERMOSTAT_INPUT_HPP
#define THERMOSTAT_INPUT_HPP

#include "Component.hpp"
#include "StaticDisplay.hpp"

class ThermostatImput : public Component
{
public:
    ThermostatImput(const char* tag, const char* location, int value, int minValue, int maxValue);
    // ~ThermostatImput();

    //overriden methods
    void render(std::ostream& out) const override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    const char* status() const override;
    ThermostatImput* clone() const override;

    //methods
    ThermostatImput& operator++();    // Префиксен ++
    ThermostatImput operator++(int);  // Постфиксен ++
    ThermostatImput& operator--();    // Префиксен --
    ThermostatImput operator--(int);  // Постфиксен --

    ThermostatImput operator+(int val) const;
    ThermostatImput operator-(int val) const;

    operator int() const;

    //getters
    int GetValue() const { return this->value; }
    int GetMinValue() const { return this->minValue; }
    int GetMaxValue() const { return this->maxValue; }

private:
    int value;
    int minValue;
    int maxValue;
};

#endif // THERMOSTAT_INPUT_HPP
