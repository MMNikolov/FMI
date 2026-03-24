#include "task3.hpp"

//for the sake of the exercise I am going to work with ints
template<typename T1, typename T2>
Tuple<T1, T2> init(Tuple<T1, T2>& tuple)
{
    Tuple<T1, T2> res;
    res.x = rand() % 100;
    res.y = rand() % 100;
    return res;
};

//First task
//----------------------------------------

template<typename T1, typename T2>
Tuple<T1, T2> add(Tuple<T1, T2>& tuple1, Tuple<T1, T2>& tuple2)
{
    Tuple<T1, T2> res;
    res.x = tuple1.x + tuple2.x;
    res.y = tuple1.y + tuple2.y;
    return res;
};

template<typename T1, typename T2, typename Res>
Tuple<T1, T2> mult(Tuple<T1, T2>& tuple1, Tuple<T1, T2>& tuple2)
{
    Tuple<T1, T2> res;
    res.x = tuple1.x * tuple2.x;
    res.y = tuple1.y * tuple2.y;
    return res;
};

template<typename T1, typename T2, typename Res>
Tuple<T1, T2> sub(Tuple<T1, T2>& tuple1, Tuple<T1, T2>& tuple2)
{
    Tuple<T1, T2> res;
    res.x = tuple1.x - tuple2.x;
    res.y = tuple1.y - tuple2.y;
    return res;
};

//Second task
//----------------------------------------
//I dont know what they are asking of me

//Third task
//---------------------------------------
template<typename T1, typename T2>
void display(Tuple<T1, T2>& tuple1)
{
    std::cout << '(' << tuple1.x << ", " << tuple1.y << ')' << "\n";
};

//Fourth task
//------------------------------------------
//I dont know what they are asking of me

