#include "ForestProtector.hpp"

ForestProtector::ForestProtector(const char* name, unsigned age, unsigned yearsWorking)
: name(nullptr), age(0), yearsWorking(0)
{
    if (age < 18)
    {
        std::cerr << "Not old enough to be a forest protector";
        this->isValid = false;
        return;
    }

    if (yearsWorking < 0)
    {
        std::cerr << "Impossible to have worked for minus years";
        this->isValid = false;
        return;
    }
    
    if (!SetString(this->name, name))
    {
        std::cerr << "There was a problem with the string of characters in constructor";
        this->isValid = false;
        return;
    }
    
    this->age = age;
    this->yearsWorking = yearsWorking;
}

bool ForestProtector::SetString(char*& where, const char* what)
{
    if (!what || *what == '\0')
    {
        std::cerr << "There was a problem with the string setting";
        return 0;
    }
    
    char* temp = new (std::nothrow) char[strlen(what) + 1];
    if (!temp)
    {
        std::cerr << "Temp was not allocated correctly";
        freeMemory();
        return false;
    }
    
    strcpy(temp, what);
    delete[] where;
    where = temp;

    return true;
}

void ForestProtector::freeMemory()
{
    delete [] name;
}

void writeBinaryFile(std::ofstream& os, ForestProtector& protector)
{
    os.write(reinterpret_cast<char*>(&protector), sizeof(ForestProtector));   
}

void readBinaryFile(std::ifstream& is, ForestProtector& protector)
{
    is.read(reinterpret_cast<char*>(&protector), sizeof(ForestProtector));
};

void ForestProtector::PrintCharacteristics()
{
    std::cout << "The name of the protector is: " << this->name << '\n'
              << "He is: " << this->age << " years old\n"
              << "He has: " << this->yearsWorking << " years in the field\n";
}