#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>

class Control
{
public:
    Control(const char* name, const char* helpMessage);

    Control(const Control& other);
    Control& operator=(const Control& other);

    ~Control();

    //methods
    virtual void print() const = 0;
    virtual void store(const char* filename) const = 0;
    virtual void load(const char* filename) = 0;
    virtual const char* settings() = 0;

    //setters
    const char* setName(const char* newName);
    const char* setHelpMessage(const char* newHelpMessage);
    bool setEnabled(bool newEnabled);

protected:
    const unsigned id;
    char* name;
    char* helpMessage;
    bool enabled;

private:
    static unsigned GlobalId;
    static unsigned Incrementer() { return ++GlobalId; };

    void free();
};

#endif // CONTROL_HPP
