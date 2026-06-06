#pragma once

#include "Event.hpp"

class Task : public Event
{
public:
    Task(const char* name, const char* description, unsigned hours, bool isRepeatedMonthly, const char* endDate);

    Task(const Task& other);
    Task& operator=(const Task& other);

    ~Task();

    //overriden methods
    Task* clone() const override;

    //methods
    friend std::ostream& operator<<(std::ostream& out, const  Task& task);
    friend std::istream& operator>>(std::istream& in, Task& task);

    //getters
    const char* GetEndDate() const { return this->endDate; };

private:
    char* endDate;

    void free();
};

bool operator>(const Task& one, const Task& two);
bool operator<(const Task& one, const Task& two);