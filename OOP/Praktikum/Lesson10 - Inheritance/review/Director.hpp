#pragma once

#include "Secretery.hpp"
#include "Manager.hpp"

// Не е баш мениджър, самостоятелна единица си е. Хубаво е преизползваш логиката ама той няма департамент
// който ръководи. Може да направиш клас, който контролира хора и той да е контейнер
// така мениджъра и директора ще го наследяват, но самите те ще се различават
class Director : public Manager
{
public:
    //default ctor
    Director();

    //parametrized ctor
    Director(const char* name, const char* address, long EGN, const char* department, double salary, const char* description, const char* departmentHeManages, Secretery* secretery);

    //copy ctor
    Director(const Director& other);
    Director& operator=(const Director& other);

    //destructor
    ~Director();

    //methods
    double calculateTotalSalary() const;

private:

    // Другите класове направи да не правят копия на служителите, но тук генетично клонираме леля гинка за 
    // всеки директор, според мен е ненужно. Този клас може да мине и без жизнен цикъл с плитки копия 
    // на секретарката 
    Secretery* secretery;
    
    void free();
};
