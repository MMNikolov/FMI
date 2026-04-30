#include "Smartphone.hpp"

class Store
{
public:
    // parametrized ctor
    Store(double budget);

    //copy ctor
    Store(const Store& other);
    Store& operator=(const Store& other);

    //destructor
    ~Store();

    //methods
    void addTelephone(const Smartphone& phone);
    void removeTelephone(const char* model, const char* maker);

    //getters
    double getBudget() const;

private:

    Telephone** t;


    Smartphone* phones;
    unsigned phonesCount;
    double budget;

    void free();
    void copyFrom(const Store& other);
};


