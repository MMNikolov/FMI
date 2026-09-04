#ifndef ARCHITECTURE_HPP
#define ARCHITECTURE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>

enum Architecture
{
    UNKNOWN = -1,

    X86_64 = 0,
    ARM, 
    RISC_V,
    MIPS, 
    OTHER_RISC,
    OTHER_CISC,

    COUNT = 6
};

#endif // ARCHITECTURE_HPP