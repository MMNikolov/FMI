#include "date.hpp"

date::date()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
};

date::date(unsigned day, unsigned month, unsigned year)
    : day(0), month(0), year(0), IsValid(true)
{
    if (!ValidateDate(day, month, year))
    {
        std::cerr << "The date is not valid";
        this->IsValid = false;
        return;
    }

    this->day = day;
    this->month = month;
    this->year = year;
}

bool date::has31Days()
{
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return true;
        break;
    case 2: case 4: case 6: case 9: case 11:
        return false;
        break;
    default:
        std::cerr << "Invalid month for the date";
        return false;
        break;
    }
};

bool date::isVisokosna()
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }

    return false;
};

void date::readText(std::ifstream &is)
{
    char c = '/';
    is >> day >> c >> month >> c >> year;
};

void date::printDate()
{
    std::cout << day << '/' << month << '/' << year << '\n';
};

bool date::ValidateDate(unsigned day, unsigned month, unsigned year)
{
    if (has31Days())
    {
        if (day > 31 || day < 0)
        {
            return false;
        }
        return true;
    }
    else if (!has31Days())
    {
        if (month == 2)
        {
            if (isVisokosna())
            {
                if (day > 29 || day < 0)
                {
                    return false;
                }
                return true;
            }

            if (day > 28 || day < 0)
            {
                return false;
            }
            return true;
        }

        if (day > 30 || day < 0)
        {
            return false;
        }
        return true;
    }

    if (month < 0 || month > 12)
    {
        return false;
    }
    
    if (year < 0 || year > 9999)
    {
        return false;
    }

    return false;
};

void date::changeDate(unsigned day, unsigned month, unsigned year)
{
    if (!ValidateDate(day, month, year))
    {
        std::cerr << "The date u need to change should be valid format";
        this->IsValid = false;
        return;
    }
    
    this->day = day;
    this->month = month;
    this->year = year;
}

void date::writeText(std::ofstream& os)
{
    os << this->day << '/' << this->month << '/' << this->year;
};

void printDateDifference(const date& date1, const date& date2)
{
    int totalDays1 = DaysInDate(date1);
    int totalDays2 = DaysInDate(date2);
    
    int difference = std::abs(totalDays1 - totalDays2);
    
    std::cout << "The difference is " << difference << " days.\n";
}

unsigned DaysInDate(const date& date1)
{
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int y = date1.getYear();
    int m = date1.getMonth();

    int totalDays = y * 365 + date1.getDay();

    for (int i = 0; i < m - 1; i++)
    {
        totalDays += monthDays[i];
    }
    
    if (m <= 2)
    {
        y--;
    }

    //this algorithm was taken from stackoverflow (I aint that smart)
    int leapDays = (y / 4) - (y / 100) + (y / 400);
    totalDays += leapDays;

    return totalDays;
};