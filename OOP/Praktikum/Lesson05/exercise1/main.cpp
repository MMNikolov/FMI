#include "funcs.hpp"

int main(){
    MyArray<int> arr;
    std::cout << "how many elements do you want the array to have: ";
    std::cin >> n;

    std::cout << "Initialization of the array: ";
    init(arr);
    print(arr);
    std::cout << "Adding an element: ";
    add(arr, 2835);
    print(arr);
    std::cout << "Removing an entry: ";
    remove(arr, 2);
    print(arr);
    std:: cout << "Reversing the array: ";
    reverse(arr);
    print(arr);

    return 0;
}

