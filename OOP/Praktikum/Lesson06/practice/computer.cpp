#include "computer.hpp"

computer::computer(GPU gpu, const char* cpu, bool hasCooling)
    : gpu((GPU)0)
    , cpu(nullptr)
    , hasCooling(false)
{
    if (gpu == GPU::UNKNOWN)
    {
        this->IsValid = false;
        return;
    }
    
    if (!setString(this->cpu, cpu))
    {
        this->IsValid = false;
        free();
        return;
    }
    
    this->gpu = gpu;
    this->hasCooling = hasCooling;
};

bool computer::setString(char* where, const char* what)
{
    if (!what || *what == '\0')
    {
        return false;
    }
    
    char* temp = new (std::nothrow) char[strlen(what) + 1];
    if (!temp)
    {
        return false;
    }
    
    strcpy(temp, what);
    delete where;
    where = temp;

    return 0;
};

void computer::free()
{
    delete[] cpu;
}

void computer::printComputer()
{
    std::cout << std::boolalpha;
    std::cout << "This computers GPU is: " << GPUNames[gpu] << "\n";
    std::cout << "This computers CPU is: " << cpu << "\n";
    std::cout << "Does this computer has cooling: " << hasCooling << "\n";
}