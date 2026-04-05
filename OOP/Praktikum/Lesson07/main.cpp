#include <string.h>
#include <iostream>

// WHAT NOT TO DO

// class Book {
// public:
//     Book() : text(nullptr) {};
//     Book(const char* text)
//     {
//         if(!text) std::invalid_argument("Invalid data!");

//         this->text = new char[strlen(text) + 1];
//         strcpy(this->text, text);
//     };

//     ~Book()
//     {
//         delete[] text;
//         text = nullptr;
//     }

// private:
//     char* text;
// };

// int main(void){

//     try
//     {
//         Book bible("And there was light!");

//         {
//             // Извикване експлицитно на служебен копиращ конструктор
//             Book necronomicon(bible);
//         } // --> край на блока, извиква се деструктор на necronomicon

//         // Какво става тук??
//         // necronomicon изтри данните на bible...
//         // Това изобщо не е желан ефект
//     }
//     catch(const std::exception& e)
//     {
//         std::cout << e.what();
//     }
//     return 0;
// };

// EXAMPLE OF A DEEP COPY

class DynamicString
{
private:
    char *text;

public:
    // Standard constructor allocating dynamic memory
    DynamicString(const char *str)
    {
        text = new char[strlen(str) + 1];
        strcpy(text, str);
    }

    // Custom Copy Constructor (Deep Copy)
    DynamicString(const DynamicString &source)
    {
        // 1. Allocate brand new memory for this object
        text = new char[strlen(source.text) + 1];

        // 2. Copy the actual data into the new memory block
        strcpy(text, source.text);
    }

    // Destructor to clean up memory
    ~DynamicString()
    {
        delete[] text;
    }

    void display()
    {
        std::cout << text << std::endl;
    }
};

int main()
{
    DynamicString firstString("System Initialized");

    // The custom copy constructor is called here.
    // firstString and secondString now have completely separate memory blocks containing identical text.
    DynamicString secondString = firstString;

    firstString.display();
    secondString.display();

    return 0;
}