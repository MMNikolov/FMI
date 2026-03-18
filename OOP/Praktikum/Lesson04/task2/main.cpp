#include "task2.h"

int main(){
    initializeSomeValues();
    std::ofstream os("products.bin", std::ios::binary | std::ios::out);
    createFields(os);

    os.close();
    return 0;
}