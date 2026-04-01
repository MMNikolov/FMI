#pragma once

#include <iostream>
#include <fstream>
#include <cstring>

class date
{
public:
    date(unsigned day, unsigned month, unsigned year);
    date();

    bool has31Days();
    bool isVisokosna();
    void readText(std::ifstream &is);
    bool ValidateDate(unsigned day, unsigned month, unsigned year);
    void printDate();
    void changeDate(unsigned day, unsigned month, unsigned year);
    void writeText(std::ofstream &os);

    // getters
    unsigned getDay() const { return day; }
    unsigned getMonth() const { return month; }
    unsigned getYear() const { return year; }

private:
    unsigned day;
    unsigned month;
    unsigned year;
    bool IsValid;
};

void printDateDifference(const date &date1, const date &date2);
unsigned DaysInDate(const date &date1);
unsigned addDaysToDate(date& date1, unsigned int days);
void printNewDate(unsigned int days);
