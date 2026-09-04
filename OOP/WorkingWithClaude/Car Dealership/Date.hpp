#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <fstream>

class Date
{
public:
    // Three ints: day (1-31), month (1-12), year (real calendar year,
    // e.g. 2024 -- must be between 1970 and 2033, since only 6 bits are
    // available to store it as an OFFSET from 1970).
    Date(int day, int month, int year);

    // String in "dd/mm/yyyy" format.
    Date(const char* dateStr);

    // NOTE: no destructor, copy constructor, or assignment operator
    // declared here on purpose. There's no dynamic memory anymore --
    // just one plain unsigned short -- so the compiler-generated
    // versions of all three are already exactly correct.

    void print(std::ostream& out) const;

    int getDay() const;
    int getMonth() const;
    int getYear() const;   // returns the real calendar year, e.g. 2024

private:
    static const int YEAR_BASE = 1970;

    unsigned short packedDate;   // THE ONLY DATA THIS CLASS STORES -- 16 bits total.
                                  // bits 15-11: day, bits 10-7: month, bits 5-0: year-offset.
                                  // bit 6 is unused (15 bits used of 16 available).

    void pack(int day, int month, int year);   // validates, then builds packedDate
    static bool parseDateString(const char* str, int& day, int& month, int& year);
};

std::ostream& operator<<(std::ostream& out, const Date& date);

#endif