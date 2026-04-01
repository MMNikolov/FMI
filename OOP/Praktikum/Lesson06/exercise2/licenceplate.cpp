#include "licencePlate.hpp"

licencePlate::licencePlate(const char* front, unsigned int num, const char* back)
: front(nullptr), num(0), back(nullptr), isValid(true){

    if (!setString(this->front, front) || strlen(front) > 2)
    {
        std::cerr << "Problem with setting the string on the front of the licence plate!";
        this->isValid = false;
        freeMemory();
        return;
    }
    
    if (num < 1 || num > 9999)
    {
        std::cerr << "The number must be between 0-9999";
        this->isValid = false;
        return;
    }
    
    if (!setString(this->back, back) || strlen(back) > 2)
    {
        std::cerr << "Problem with setting the string on the back of the licence plate!";
        this->isValid = false;
        freeMemory();
        return;
    }


    this->num = num;
};

licencePlate::licencePlate() : front(nullptr), num(0), back(nullptr), isValid(false) {}

bool licencePlate::setString(char*& where, const char* what){
    if (!what || *what == '\0')
    {
        return false;
    }

    char* temp = new (std::nothrow) char[strlen(what) + 1];
    if (!temp)
    {
        std::cerr << "Cant allocate memory properly in SetString";        
        return false;
    }
    
    strcpy(temp, what);

    delete[] where;
    where = temp;

    return true;
}

void licencePlate::freeMemory(){
    delete[] front;
    delete[] back;

    front = nullptr;
    back = nullptr;
}

void licencePlate::readFromTxt(std::ifstream& is){
    char tempFront[256];
    char tempBack[256];
    unsigned int tempNum;

    if (is >> tempFront >> tempNum >> tempBack) {
        // Corrected: Validate data BEFORE applying it to the object
        if (strlen(tempFront) > 2 || strlen(tempBack) > 2 || tempNum < 1 || tempNum > 9999) {
            std::cerr << "Error: File contained invalid plate format.\n";
            this->isValid = false;
            return;
        }

        setString(this->front, tempFront);
        this->num = tempNum;
        setString(this->back, tempBack);
        this->isValid = true;
    } else {
        this->isValid = false;
    } 
}

void licencePlate::printCharacteristics(){
    std::cout << this->front << " " << this->num << " " << this->back << '\n';
}