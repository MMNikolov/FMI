#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#define ARR_SIZE 128

template<typename T>
struct MyArray
{
    T arr[ARR_SIZE];
};

inline int n;

template<typename T>
void init(MyArray<T>& arr);
template<typename T>
void copy(MyArray<T>& arr, const MyArray<T>& other);
template<typename T>
void add(MyArray<T>& arr, const T& elemt);
template<typename T>
void remove(MyArray<T>& arr, int index);
template<typename T>
void reverse(MyArray<T>& arr);
template<typename T>
void print(const MyArray<T>& arr);
template<typename T>
void swap(T& a, T& b);

#include "funcs.inl"