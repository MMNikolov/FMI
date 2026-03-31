#include "ForestProtector.hpp"

int main(){
    ForestProtector protector("Diablo", 20, 20);
    std::ofstream outputStream("treesProtector.bin", std::ios::binary | std::ios::out);
    if (!outputStream)
    {
        std::cerr << "There was a problem with the binary output stream file";
        return 0;
    }

    std::ifstream inputStream("treesProtector.bin", std::ios::binary | std::ios::in);
    if (!inputStream)
    {
        std::cerr << "There was a problem with the binary input stream file";
        return 0;
    }
    
    protector.PrintCharacteristics();
    writeBinaryFile(outputStream, protector);
    readBinaryFile(inputStream, protector);

    return 0;
}