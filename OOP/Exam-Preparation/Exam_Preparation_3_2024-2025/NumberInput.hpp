#ifndef NUMBER_INPUT_HPP
#define NUMBER_INPUT_HPP

#include "Control.hpp"

class NumberInput : public Control
{
public:
    NumberInput(const char* name, const char* helpMessage, int initialVal, int minVal, int maxVal);

    //overriden methods
    void print() const override;
    const char *settings() override;
    void store(std::ofstream& file) const override;
    void load(std::ifstream& file) override;

    //methods
    void operator++();
    void operator--();
    void operator+(int value);
    void operator-(int value);

    //getters
    int getInitialVal() const { return this->initialVal; }
    int getMinVal() const { return this->minVal; }
    int getMaxVal() const { return this->maxVal; }

private:
    int initialVal;
    int minVal;
    int maxVal;
};

#endif // NUMBER_INPUT_HPP
