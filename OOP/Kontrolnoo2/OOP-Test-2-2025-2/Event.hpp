#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <fstream>

class Event
{
public:
    Event(const char* name, const char* description, unsigned hours, bool isRepeatedMonthly);

    Event(const Event& other);
    Event& operator=(const Event& other);
    
    virtual ~Event();

    //methods
    friend std::ostream& operator<<(std::ostream& out, const Event& event);
    friend std::istream& operator>>(std::istream& in, Event& event);

    //virtual methods
    virtual Event* clone() const;

    //getters
    const char* GetName() const { return this->name; };
    const char* GetDescr() const { return this->description; };
    unsigned GetHours() const { return this->hours; };
    bool GetIsRepeatedMonthly() const { return this->isRepeatedMonthly; };

protected:
    char* name;
    char* description;
    unsigned hours;
    bool isRepeatedMonthly;

private:
    void copyFrom(const Event& other);
    void free();
};

bool operator==(const Event& one, const Event& two);