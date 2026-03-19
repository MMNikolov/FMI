#include <iostream>
#include <fstream>

/*
1.Template function
    - The place for the template functions is in the header files
*/

template<typename T>
T min(T a, T b){
    return (a < b ? a : b);
}

int main(){
    std::cout << min(5, 3) << "\n";
    //casting
    std::cout << min<int>(2.2, 3) << "\n";

    return 0;
}