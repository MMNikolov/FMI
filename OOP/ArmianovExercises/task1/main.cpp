#include "task1.hpp"

int main(){
    //Initialization of the fruits, stream and size
    Fruits fruits;
    unsigned int size;
    std::cout << "How many fruits do you want: ";
    std::cin >> size;

    //file management
    //txt files
    std::ifstream is("fruits.txt", std::ios::in);
    if (!is)
    {
        std::cerr << "There is a problem with the file";
        return 0;
    }
    readFruitFromTxt(fruits, is, size);

    std::ofstream os("fruits_2.txt", std::ios::out);
    if (!os)
    {
        std::cerr << "There is a problem with the file";
        return 0;
    }
    writeFruitInTxt(fruits, os, size);

    //binary files
    std::ofstream outputBinary("fruits_bin.bin", std::ios::binary | std::ios::out);
    if (!outputBinary)
    {
        std::cerr << "There is a problem with the file";
        return 0;
    }
    writeFruitInBinary(fruits, outputBinary, size);
    

    is.close(); os.close();
    outputBinary.close();
    return 0;
}