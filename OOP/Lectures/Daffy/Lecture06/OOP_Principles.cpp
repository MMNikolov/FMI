#include <iostream>
#include <cstring>

/*
0.Philosophy
    - not so much for the synthax than the usage of these functions and principles
1.The 4 Pillars of OPP
    - Encapsulation
        - The idea of hiding something
        - Close the object in a capsule (private classes)
    - Abstraction
        - Using something with minimal knowledge
        - Minimal knowledge ensures clean code
        - The example of the car (we know how to drive it but we dont know EVERYTHING under the hood)
    - Inheritance
        - something that is already done and therefore use it many of times
        - parent - children relationship
    - Polymorphism
        - The idea of having identity which can have different behaviour based on outside characteristics
        - an example is: function overloading
2.Solid principles (5)
    - Single responsibility
        - One thing has a single responsobility (it does ONE thing)
    - Open-Closed Principle
        - open for extension, bur closed for modification
        - You can easily extend the code, with the accent on not chaging the existing code
    - Liskovs Substitution
        - Every single class u should be able to add children to the parent
        - (Inheritance and Polymorphism - basically)
    - Interface segregation
        - always use interfaces to announce ur functions
        - Seperation (you know how the functions work, just seperate them :D)
    - Dependency Inversion
        - Abstraction
3.Classes and Objects
    - Class
        - Connects datas and their functionality 
        - Methods of classes
    - Object
        - 
*/

// Overloading (polymorphism)
    typedef int (*func)(int, int);

    template <typename T>
    T min(T a, T b)
    {
        return (a < b ? a : b);
    }

    int sum(int a, int b){
        return a + b;
    }

    const char *min(const char *str1, const char *str2)
    {
        return strcmp(str1, str2) <= 0 ? str1 : str2;
    }

    int acc(int *arr, size_t size, func f){
        int p = arr[0];

        for (unsigned i = 0; i < size; i++)
        {
            p = f(5, 6);
        }

        return p;
    }
//


int main()
{

    return 0;
}