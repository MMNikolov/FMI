#include "task3.hpp"

// for the sake of the exercise I am going to work with ints
template <typename T1, typename T2>
Tuple<T1, T2> init(Tuple<T1, T2> &tuple)
{
    Tuple<T1, T2> res;
    res.x = rand() % 100;
    res.y = rand() % 100;
    return res;
};

// Exercise 1
// First task
//----------------------------------------

template <typename T1, typename T2>
Tuple<T1, T2> add(Tuple<T1, T2> &tuple1, Tuple<T1, T2> &tuple2)
{
    Tuple<T1, T2> res;
    res.x = tuple1.x + tuple2.x;
    res.y = tuple1.y + tuple2.y;
    return res;
};

template <typename T1, typename T2, typename Res>
Tuple<T1, T2> mult(Tuple<T1, T2> &tuple1, Tuple<T1, T2> &tuple2)
{
    Tuple<T1, T2> res;
    res.x = tuple1.x * tuple2.x;
    res.y = tuple1.y * tuple2.y;
    return res;
};

template <typename T1, typename T2, typename Res>
Tuple<T1, T2> sub(Tuple<T1, T2> &tuple1, Tuple<T1, T2> &tuple2)
{
    Tuple<T1, T2> res;
    res.x = tuple1.x - tuple2.x;
    res.y = tuple1.y - tuple2.y;
    return res;
};

// Second task
//----------------------------------------
template <typename T1, typename T2>
bool operator==(const Tuple<T1, T2> tuple1, const Tuple<T1, T2> tuple2)
{
    return (tuple1.x == tuple2.x && tuple1.y == tuple2.y);
};

template <typename T1, typename T2>
bool operator>(const Tuple<T1, T2> tuple1, const Tuple<T1, T2> tuple2)
{
    return (tuple1.x > tuple2.x && tuple1.y > tuple2.y);
};

template <typename T1, typename T2>
bool operator<(const Tuple<T1, T2> tuple1, const Tuple<T1, T2> tuple2)
{
    return (tuple1.x < tuple2.x && tuple1.y < tuple2.y);
};

template <typename T1, typename T2>
bool operator<=(const Tuple<T1, T2> tuple1, const Tuple<T1, T2> tuple2)
{
    return (tuple1.x <= tuple2.x && tuple1.y <= tuple2.y);
};

template <typename T1, typename T2>
bool operator>=(const Tuple<T1, T2> tuple1, const Tuple<T1, T2> tuple2)
{
    return (tuple1.x >= tuple2.x && tuple1.y >= tuple2.y);
};

// Third task
//---------------------------------------
template <typename T1, typename T2>
void display(const Tuple<T1, T2> &tuple1)
{
    std::cout << '(' << tuple1.x << ", " << tuple1.y << ')' << "\n";
};

// Fourth task
//------------------------------------------
template <>
void display<char *, char *>(const Tuple<char *, char *> &tuple)
{
    size_t len1 = strlen(tuple.x);
    size_t len2 = strlen(tuple.y);

    bool isPrefix = (len1 <= len2) && (strncmp(tuple.x, tuple.y, len1) == 0);
    bool isSuffix = (len2 <= len1) && (strcmp(tuple.x + len1 - len2, tuple.y) == 0);

    if (isPrefix)
    {
        std::cout << tuple.y << std::endl;
    }
    else if (isSuffix)
    {
        std::cout << tuple.x << std::endl;
    }
    else
    {
        std::cout << "(" << tuple.x << ", " << tuple.y << ")" << std::endl;
    }

    //Exercise 2
    //Task 1
    
}
