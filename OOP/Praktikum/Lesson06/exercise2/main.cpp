#include "licencePlate.hpp"

int main()
{
    licencePlate plate1;
    licencePlate plate2;
    // licencePlate plate3;
    std::ifstream is("licencePlates.txt");
    if (!is)
    {
        std::cerr << "Cant open the file";
        return 0;
    }

    plate1.readFromTxt(is);
    plate2.readFromTxt(is);
    // plate3.readFromTxt(is);
    plate1.printCharacteristics();
    plate2.printCharacteristics();
    // plate3.printCharacteristics();

    if (plate1.GetValidity() == true)
    {
        plate1.AssignCity();
    }

    is.close();
    return 0;
}