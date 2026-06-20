#include "ThermostatImput.hpp"

ThermostatImput::ThermostatImput(const char *tag, const char *location, int value, int minValue, int maxValue)
    : Component(tag, location)
{
    if (value < minValue || value > maxValue)
    {
        throw std::invalid_argument("There is something wrong with the value...");
    }
    
    this->value = value;
    this->maxValue = maxValue;
    this->minValue = minValue;
}

void ThermostatImput::render(std::ostream &out) const
{
    out << "[ThermostatInput] ID: " << id << ", Tag: " << tag 
        << ", Temp: " << value << "C (Range: " << minValue << "C - " << maxValue << "C)\n";
}

void ThermostatImput::save(std::ofstream &out) const
{
    Component::saveBase(out);

    out.write(reinterpret_cast<const char*>(&this->value), sizeof(this->value));
    out.write(reinterpret_cast<const char*>(&this->minValue), sizeof(this->minValue));
    out.write(reinterpret_cast<const char*>(&this->maxValue), sizeof(this->maxValue));
}

void ThermostatImput::load(std::ifstream &in)
{
    Component::loadBase(in);

    in.read(reinterpret_cast<char*>(&value), sizeof(value));
    in.read(reinterpret_cast<char*>(&minValue), sizeof(minValue));
    in.read(reinterpret_cast<char*>(&maxValue), sizeof(maxValue));
}

const char *ThermostatImput::status() const
{
    // 1. Преброяваме колко символа ще ни трябват (дължината на числото)
    int temp = this->value;
    int len = 0;
    
    if (temp <= 0) len++; // Място за '0' или за знака '-'
    
    int countTemp = temp;
    while (countTemp != 0)
    {
        len++;
        countTemp /= 10;
    }

    // 2. Заделяме точно количество динамична памет
    char* str = new char[len + 1];
    str[len] = '\0'; // Терминираща нула

    temp = this->value;
    int index = len - 1;

    if (temp == 0)
    {
        str[0] = '0';
    }
    else
    {
        bool isNegative = false;
        if (temp < 0)
        {
            isNegative = true;
            temp = -temp; 
        }

        // Пълним масива отзад напред с остатъците от деленето на 10
        while (temp > 0)
        {
            str[index--] = '0' + (temp % 10);
            temp /= 10;
        }

        if (isNegative)
        {
            str[0] = '-';
        }
    }

    return str;
}

ThermostatImput *ThermostatImput::clone() const
{
    return new ThermostatImput(*this);
}

ThermostatImput &ThermostatImput::operator++()
{
    IsActive();
    if (this->value >= maxValue)
    {
        this->value = maxValue;
        std::cout << "Maximum capacity reached\n";
        return *this;
    }
    
    this->value++;
    return *this;
}

ThermostatImput ThermostatImput::operator++(int)
{
    IsActive();
    ThermostatImput copy(*this); 

    if (this->value < this->maxValue)
    {
        this->value++; 
    }
    else
    {
        std::cout << "Maximum capacity reached\n";
    }
    return copy; 
}

ThermostatImput &ThermostatImput::operator--()
{
    IsActive();
    if (this->value <= minValue)
    {
        this->value = minValue;
        std::cout << "minimum capacity reached\n";
        return *this;
    }
    
    this->value--;
    return *this;
}

ThermostatImput ThermostatImput::operator--(int)
{
    IsActive();
    ThermostatImput copy(*this); 

    if (this->value > this->minValue)
    {
        this->value--; 
    }
    else
    {
        std::cout << "Minimum capacity reached\n";
    }
    return copy; 
}

ThermostatImput ThermostatImput::operator+(int val) const
{
    IsActive();
    ThermostatImput copy(*this);

    if (copy.value + val >= copy.maxValue)
    {
        copy.value = copy.maxValue;
        std::cout << "Maximum capacity reached\n";
        return copy;
    }
    
    copy.value += val;
    return copy;
}

ThermostatImput ThermostatImput::operator-(int val) const
{
    IsActive();
    ThermostatImput copy(*this);

    if (copy.value - val <= copy.minValue)
    {
        copy.value = copy.minValue;
        std::cout << "Minimum capacity reached\n";
        return copy;
    }
    
    copy.value -= val;
    return copy;
}

ThermostatImput::operator int() const
{
    return this->value;
}
