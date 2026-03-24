#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Preobrazuvaniq:
    - (double) - basic casting
    - static_cast<T1>()
    - const_cast<T1>() - podavash constantnost
        - x = 3 + 5, no
        - 3 + 5 != x      lvalue and rvalue
    - reinterpret_cast<T1>() - smenqme interpretaciqta na dannite (kak komputera da go chete)
        - nai-chesto se izpolzva za preobrazuvane na pointeri
    - dynamic_cast<T*>()
Class
    -encapsulation
        - protection from the outside world
        - dava ni vuzmojnost da razdelim obekta ot vunshniq klas
    -abstraction
        - privtae field in a class
        - work only with the data in the class
    
*/

class Rational
{
    private:
        int num;
        unsigned denum;

    public:
        Rational(int num = 0, unsigned denum = 1)
        {
            this->num = num;
            this->denum = denum;

            if (!checkOK())
            {
                //fixstate
            }
        }
        
        void printRat()
        {
            std::cout << num << '/' << denum << "\n";
        };
        
        double toDouble()
        {
            return static_cast<double>(num) / denum;
        };
        
        bool checkOK()
        {
            return denum > 0;
        };
};

template<typename T>
T randomNum()
{
    T num = rand() % 100;
    return num;
}


int main(){
    srand(time(NULL));
    Rational rat1(randomNum<int>(), randomNum<unsigned>());

    rat1.printRat();
    std::cout << rat1.toDouble();
    return 0;
}