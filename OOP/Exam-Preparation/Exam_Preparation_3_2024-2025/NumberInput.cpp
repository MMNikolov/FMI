#include "NumberInput.hpp"

NumberInput::NumberInput(const char *name, const char *helpMessage, int initialVal, int minVal, int maxVal)
    : Control(name, helpMessage)
{
    if (initialVal > maxVal || initialVal < minVal)
    {
        throw std::invalid_argument("well something is right");
    }

    this->initialVal = initialVal;
    this->minVal = minVal;
    this->maxVal = maxVal;
}

void NumberInput::print() const
{
    std::cout << "[NumberInput] " << name << " = " << initialVal << " [" << minVal << "," << maxVal << "]\n";
}

const char *NumberInput::settings()
{
    char *buffer = new char[32];
    std::sprintf(buffer, "%d", initialVal);

    return buffer;
}

void NumberInput::store(std::ofstream &file) const
{
    Control::store(file);
    file.write(reinterpret_cast<const char *>(&this->initialVal), sizeof(initialVal));
    file.write(reinterpret_cast<const char *>(&this->minVal), sizeof(this->minVal));
    file.write(reinterpret_cast<const char *>(&this->maxVal), sizeof(maxVal));
}

void NumberInput::load(std::ifstream &file)
{
    Control::load(file);
    file.read(reinterpret_cast<char *>(&this->initialVal), sizeof(this->initialVal));
    file.read(reinterpret_cast<char *>(&this->minVal), sizeof(this->minVal));
    file.read(reinterpret_cast<char *>(&this->maxVal), sizeof(this->maxVal));
}

void NumberInput::operator++()
{
    if (this->initialVal >= maxVal)
    {
        throw std::invalid_argument("The initial value cant go out of bounds");
    }
    
    this->initialVal++;
}

void NumberInput::operator--()
{
    if (this->initialVal <= minVal)
    {
        throw std::invalid_argument("The initial value cant go out of bounds");
    }
    
    this->initialVal--;
}

void NumberInput::operator+(int value)
{
    if (this->initialVal + value >= maxVal)
    {
        throw std::invalid_argument("The initial value cant go out of bounds");
    }
    
    this->initialVal += value;
}

void NumberInput::operator-(int value)
{
    if (this->initialVal - value <= minVal)
    {
        throw std::invalid_argument("The initial value cant go out of bounds");
    }
    
    this->initialVal -= value;
}
