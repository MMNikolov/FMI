#include "functions.hpp"

int main(){
    MyArray<int>* set1 = new (std::nothrow) MyArray<int>;
    
    std::cout << std::boolalpha;
    //I am going to use the first set for the testing of the functionality
    init(set1);
    print(set1);
    std::cout << "Does the set contain 1: " <<  contains<int>(set1, 1) << "\n";

    bool flagAdd = add<int>(set1, 81);
    if (flagAdd)
    {
        print(set1);
    }
    
    delete[] set1;
    return 0;
}