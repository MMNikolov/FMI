#include <iostream>
#include <fstream>

/*
1.Template function
*/

template<typename T>
T min(T a, T b){
    return (a < b ? a : b);
}

int main(){
    std::cout << min(5, 3) << "\n";
    std::cout << min<int>(2.2, 3) << "\n";

    return 0;
}