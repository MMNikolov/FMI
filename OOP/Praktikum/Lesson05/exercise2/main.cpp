#include "functions.hpp"

int main(){
    //Memory allocation mastermind
    srand(time(NULL));
    MyArray<int>* set1 = new (std::nothrow) MyArray<int>;
    MyArray<int>* set2 = new (std::nothrow) MyArray<int>;
    if (!set1 || !set2)
    {
        std::cerr << "Problem with the memory allocation";
        return 0;
    }
    
    //Determening the size of the sets
    std::cout << "Enter the number of elements that you want in the first set: ";
    std::cin >> set1->currentSize;
    std::cout << "Enter the number of elements that you want in the second set: ";
    std::cin >> set2->currentSize;

    //cool little bullshit
    std::cout << std::boolalpha;
    
    //I am going to use the first set for the testing of the functionality
    //Initializization and the printing of the array
    init(set1);
    init(set2);
    print(set1);

    //contains functionality
    std::cout << "Does the set contain 1: " <<  contains(set1, 1) << "\n";

    //addition to the array functionality
    std::cout << "Adding the element 81\n";
    bool flagAdd = add(set1, 81);
    if (flagAdd)
    {
        print(set1);
    }

    //remove functionality
    std::cout << "Removing the element 81\n";
    bool flagRemove = remove(set1, 81);
    if (flagRemove)
    {
        print(set1);
    }
    
    //getAt functionality
    int elem = getAt(set1, 2);
    std::cout << "The element at index 2 is: ";
    std::cout << elem << "\n";

    //okay all the basic functions that I am going to need are implemented
    //starting the second part of the exercise
    MyArraysss<int>* collection = new (std::nothrow) MyArraysss<int>;
    if (!collection)
    {
        std::cerr << "there was an error with the memory allocation of the collections";
        return 0;
    }
    
    for (unsigned i = 0; i < MAX_ARRS_IN_ARR; i++)
    {
        collection->arrays[i].currentSize = 0;
    }
    
    collection->arrays[0] = *set1;
    collection->arrays[1] = *set2;

    std::cout << "Testing Union...\n";
    MyArray<int>* unionResult = Union(*collection);
    print(unionResult);

    std::cout << "Testing Intersect...\n";
    MyArray<int>* intersectResult = Intersect(*collection);
    print(intersectResult);

    delete set1; delete set2;
    delete collection;
    delete unionResult; delete intersectResult;
    return 0;
}