#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#define MAX_TUPLES 20

template<typename T1, typename T2>
struct Tuple
{
    T1 x;
    T2 y;
};

template<typename T1, typename T2>
struct Tuples
{
    Tuple<T1, T2> arrTuples[MAX_TUPLES];
};

template<typename T1, typename T2>
Tuple<T1, T2> init(Tuple<T1, T2>& tuple1);

//First task
//---------------------------------------

template<typename T1, typename T2, typename Res>
Tuple<T1, T2> add(Tuple<T1, T2>& tuple1, Tuple<T1, T2>& tuple2);

template<typename T1, typename T2, typename Res>
Tuple<T1, T2> mult(Tuple<T1, T2>& tuple1, Tuple<T1, T2>& tuple2);

template<typename T1, typename T2, typename Res>
Tuple<T1, T2> sub(Tuple<T1, T2>& tuple1, Tuple<T1, T2>& tuple2);

//Second task
//-------------------------------------------
template<typename T1, typename T2>
bool operator==(const Tuple<T1, T2> tuple1, const Tuple<T1, T2> tuple2);

template<typename T1, typename T2>
bool operator>(const Tuple<T1, T2> tuple1, const Tuple<T1, T2> tuple2);

template<typename T1, typename T2>
bool operator<(const Tuple<T1, T2> tuple1, const Tuple<T1, T2> tuple2);

template<typename T1, typename T2>
bool operator<=(const Tuple<T1, T2> tuple1, const Tuple<T1, T2> tuple2);

template<typename T1, typename T2>
bool operator>=(const Tuple<T1, T2> tuple1, const Tuple<T1, T2> tuple2);

//Third task
//------------------------------------------
template<typename T1, typename T2>
void display(const Tuple<T1, T2>& tuple1);

//Fourth task
//----------------------------------------
template<>
void display<char*, char*>(const Tuple<char*, char*>& tuple);

#include "task3.inl"
