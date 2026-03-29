#include "ForestProtector.hpp"

int main(){
    std::ifstream outputStream("treesProtector.bin", std::ios::binary | std::ios::out);
    if (!outputStream)
    {
        std::cerr << "There was a problem with the binary output stream file";
        return 0;
    }
    
    

    return 0;
}