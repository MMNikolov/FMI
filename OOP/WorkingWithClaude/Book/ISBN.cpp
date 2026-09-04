#include "ISBN.hpp"
#include <stdexcept>

bool ISBN::isValidDigit(int d)
{
    return d >= 0 && d <= 9;
}

ISBN ISBN::read(std::istream &is)
{
    char buffer[LENGTH];
    is.read(buffer, LENGTH);

    int values[LENGTH];
    for (int i = 0; i < LENGTH; i++)
    {
        values[i] = buffer[i] - '0';
    }

    return ISBN(values[0], values[1], values[2], values[3], values[4],
                values[5], values[6], values[7], values[8], values[9],
                values[10], values[11], values[12]);
}

ISBN::ISBN(int d1, int d2, int d3, int d4, int d5, int d6, int d7,
           int d8, int d9, int d10, int d11, int d12, int d13)
{
    int values[LENGTH] = {d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13};

    for (int i = 0; i < LENGTH; i++)
    {
        if (!isValidDigit(values[i]))
        {
            throw std::invalid_argument("ISBN: every digit must be between 0 and 9");
        }
    }

    if (d1 != 9 || d2 != 7 || d3 != 8)
    {
        throw std::invalid_argument("ISBN: must start with 978");
    }

    for (int i = 0; i < LENGTH; i++)
    {
        digits[i] = static_cast<char>('0' + values[i]);
    }
}

void ISBN::print(std::ostream &os) const
{
    os << digits[0] << digits[1] << digits[2] << '-'
       << digits[3] << '-'
       << digits[4] << digits[5] << '-'
       << digits[6] << digits[7] << digits[8] << digits[9] << digits[10] << digits[11] << '-'
       << digits[12];
}

std::ostream &operator<<(std::ostream &os, const ISBN &isbn)
{
    isbn.print(os);
    return os;
}

bool operator==(const ISBN &isbn1, const ISBN &isbn2)
{
    int counter = 0;
    for (unsigned i = 0; i < 13; i++)
    {
        if (isbn1.digits[i] == isbn2.digits[i])
        {
            counter++;
        }
    }

    return (counter == 13);
}
