#pragma once

#include <iostream>
#include <cstring>

enum GPU{
    UNKNOWN,

    NVIDIA,
    AMD,
    INTEL
};

static const char* GPUNames[] {"Unknown", "Nvidia", "AMD", "Intel"};

class computer
{
public:
    computer(GPU gpu, const char* cpu, bool hasCooling);
    ~computer()
    {
        delete[] cpu;
    };

    void printComputer();

private:
    GPU gpu;
    char* cpu;
    bool hasCooling;
    bool IsValid;
private:
    bool setString(char* where, const char* what);
    void free();
};
