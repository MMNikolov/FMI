#pragma once

#include "Event.hpp"
#include "Task.hpp"

class Meeting : public Event
{
public:
    Meeting(const char* name, const char* description, unsigned hours, bool isRepeatedMonthly);

    Meeting(const Meeting& other);
    Meeting& operator=(const Meeting& other);

    ~Meeting();

    //overriden methods
    Meeting* clone() const override;

    //methods
    void operator()(const Task& task);
    void AddGuest(const char* name);
    friend std::ostream& operator<<(std::ostream& out, const  Meeting& meeting);
    friend std::istream& operator>>(std::istream& in, Meeting& meeting);

    //getters
    //we wont be needing getters

private:
    Task* tasks;
    char** names;

    void free();
};
