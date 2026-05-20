#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

class Question
{
public:
    Question();
    Question(const char* description, unsigned points);
    Question(const Question& other);
    Question& operator=(const Question& other);
    virtual ~Question();

    //methods
    virtual void ask() const = 0;
    virtual unsigned grade() const = 0;

    //getters
    const char* getDesc() const { return this->description; };

protected:
    char* description;
    unsigned points;

private:
    void free();
    void copyFrom(const Question& other);
};
