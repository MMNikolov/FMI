#include <iostream>
#include <cstring>
#include <stdexcept>

// BASE_CLASS
class Person
{
public:
    // default
    Person()
        : name(nullptr), age(0) {};

    // parametrized
    Person(const char *name, unsigned age)
        : name(nullptr), age(0)
    {
        if (!name || age > 150)
        {
            throw std::invalid_argument("Invalid inoput");
        }

        this->name = new char[strlen(name) + 1];
        if (!this->name)
        {
            throw std::bad_alloc();
        }
        strcpy(this->name, name);

        this->age = age;
    }

    // destructor
    ~Person()
    {
        delete[] name;
        this->name = nullptr;
    };

    // getters
    const char *getName() const { return this->name; };
    unsigned getAge() const { return this->age; };

private:
    char *name;
    unsigned age;
};

// CONNECTION (HAS-A)
// class Student
// {
// public:
//     Student(const char* name, unsigned age, unsigned fn)
//         : self(name, age), fn(fn)
//     {};

//     //getters
//     const char* getName() const {this->self.getName(); };
//     unsigned getAge() const { return this->self.getAge(); };

// private:
//     Person self;
//     unsigned fn;
// };

void print()
{
}

// CONNECTION (IS-A)
class Student : public Person
{
public:
    Student(const char* name, unsigned age, unsigned fn)
        : Person(name, age), fn(fn)
    {};

    //getters
    unsigned getFN() const { return this->fn; }

private:
    unsigned fn;
};

void print(const Student& s)
{
    std::cout << "Name: " << s.getName() << '\n'
              << "Age: " << s.getAge() << '\n'
              << "FN: " << s.getFN() << '\n';
}

int main()
{
    try
    {
        Student s("Ivan", 10, 23746);
        Student st("Gosho", 11, 123);
        print(s);
        print(st);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}