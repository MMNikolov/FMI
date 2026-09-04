#include "Date.hpp"
#include <stdexcept>
#include <cstring>
#include <cstdio>

Date::Date(int day, int month, int year)
{
    pack(day, month, year);
}

Date::Date(const char* dateStr)
{
    int day, month, year;
    if (!parseDateString(dateStr, day, month, year))
    {
        throw std::invalid_argument("Date string must be in dd/mm/yyyy format");
    }
    pack(day, month, year);
}

void Date::pack(int day, int month, int year)
{
    if (day < 1 || day > 31)
    {
        throw std::invalid_argument("day out of range");
    }
    if (month < 1 || month > 12)
    {
        throw std::invalid_argument("month out of range");
    }
    if (year < YEAR_BASE || year > YEAR_BASE + 63)
    {
        throw std::invalid_argument("year must be between 1970 and 2033");
    }

    int yearOffset = year - YEAR_BASE;   // stored relative to 1970 so it fits in 6 bits (0-63)

    packedDate = 0;
    packedDate |= (day << 11);    // day occupies bits 15-11 (5 bits)
    packedDate |= (month << 7);   // month occupies bits 10-7 (4 bits)
    packedDate |= yearOffset;     // year-offset occupies bits 5-0 (6 bits)
}

int Date::getDay() const
{
    return (packedDate >> 11) & 0x1F;   // 0x1F = 0001 1111 = mask for 5 bits
}

int Date::getMonth() const
{
    return (packedDate >> 7) & 0x0F;    // 0x0F = 0000 1111 = mask for 4 bits
}

int Date::getYear() const
{
    return (packedDate & 0x3F) + YEAR_BASE;   // 0x3F = 0011 1111 = mask for 6 bits
}

void Date::print(std::ostream& out) const
{
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%02d/%02d/%04d", getDay(), getMonth(), getYear());
    out << buffer;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
    date.print(out);
    return out;
}

bool Date::parseDateString(const char* str, int& day, int& month, int& year)
{
    if (!str || strlen(str) != 10) return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
        {
            if (str[i] != '/') return false;
        }
        else if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }

    day   = (str[0] - '0') * 10 + (str[1] - '0');
    month = (str[3] - '0') * 10 + (str[4] - '0');
    year  = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0');
    return true;
}