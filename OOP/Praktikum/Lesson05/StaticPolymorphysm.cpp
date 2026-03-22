#include <iostream>

//in the struct we define a FUNCTION (a pointer to the function)
struct Food{
    void (*eat)(void);
};

//here we can assing it so that we can use a function as a VARIABLE
void munch(){
    std::cout << "crunch\n";
}
//same here. We can assigne the value to a different holder of the struct
void slimey(){
    std::cout << "slime\n";
}

int main(){
    //here we initialize the celery.
    Food celery;
    //we set the eat function of the celery to munch
    celery.eat = munch;

    //here we initialize the jelly
    Food jelly;
    //we set the eat function to the slime function
    //therefore after using the same command on different entities
    //they do the totally opposite thing from the other
    jelly.eat = slimey;

    //here is an example  celery.eat() has crunch
    celery.eat();
    //jelly.eat() has slime
    jelly.eat();

    //even doe they are both .eat()
    //one has the crunch
    //the other has the slime
    return 0;
}