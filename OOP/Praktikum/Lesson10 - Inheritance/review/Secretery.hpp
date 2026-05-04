#pragma once

#include "Specialist.hpp"

// Ппц за секретарката нищо относно наследяване не е казано
class Secretery : public Specialist
{
public:
    //default ctor
    Secretery();

    //parametrized ctor
    Secretery(const char* name, const char* address, long EGN, const char* department, double salary, const char* description, const char* languages);

    //copy ctor
    Secretery(const Secretery& other);
    Secretery& operator=(const Secretery& other);

    //destructor
    ~Secretery();

    //getters
    const char* getLanguages() const { return this->languages; };

protected:
    char* languages;

private:
    void free();
};
