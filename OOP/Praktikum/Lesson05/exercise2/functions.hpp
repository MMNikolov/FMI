#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#define ARR_SIZE 100

inline int n1;
inline int n2;

template<typename T>
struct MyArray
{
    T set[ARR_SIZE];
};

template<typename T>
void init(MyArray<T>& arr);

template<typename T>
bool contains(MyArray<T>& arr, T element);

template<typename T>
bool add(MyArray<T>& arr, T& element);

template<typename T>
bool remove(MyArray<T>& arr, T& element);

template<typename T>
bool count(MyArray<T>& arr);

template<typename T>
T getAt(const unsigned int index);

template<typename T>
void print(const MyArray<T>& arr);

#include "functions.inl"