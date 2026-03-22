#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#define ARR_SIZE 100
#define MAX_ARRS_IN_ARR 10

template<typename T>
struct MyArray
{
    T set[ARR_SIZE];
    unsigned int currentSize = 0;
};

template<typename T>
struct MyArraysss
{
    MyArray<T> arrays[MAX_ARRS_IN_ARR];
};


template<typename T>
void init(MyArray<T>*& arr);

template<typename T>
bool contains(const MyArray<T>* arr, T element);

template<typename T>
bool add(MyArray<T>*& arr, T element);

template<typename T>
bool remove(MyArray<T>* arr, T element);

template<typename T>
bool count(MyArray<T>*& arr);

template<typename T>
T getAt(MyArray<T>*& arr, unsigned int index);

template<typename T>
void print(const MyArray<T>* arr);

// ----------------------------------

template<typename T>
MyArray<T>* Intersect(MyArraysss<T>& sets);

template<typename T>
MyArray<T>* Union(MyArraysss<T>& sets);

#include "functions.inl"