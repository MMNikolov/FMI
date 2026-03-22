#include <iostream>

//standart way of using templates
template <typename T>
inline T Add(const T &a, const T &b)
{
    return a + b;
}

//declaring the type before using it (useless)
template <typename A = int, typename B = int>
inline void Add(const A& a, const B& b)
{
    a += b;
}

// Another useless template
template<typename T = int>
struct point
{
    T x, t;
};

//The most useful I have seen so far
template<typename T1, typename T2>
struct tuple
{
    T1 value1;
    T2 value2;
};

int main()
{

    return 0;
}