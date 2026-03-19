#pragma once

#include <fstream>
#include <iostream>
#include <cstring>
#define ARR_SIZE 100
#define INITIALIZED_DATA 3

struct Product{
    char description[32];
    double cost;
    int partitionNumber;
};

//done
Product* initializeSomeValues(Product*& products);
//done
void createFields(std::ofstream& os, Product*& products);
//done
Product UpdatePrice(Product*& products, const int partitionNumber);
//done
void writeInTxt(std::ofstream& os, Product*& products);
//done
void AddProduct(Product*& products, const int partiotionNumber);
//done
void deleteProduct(Product*& products, const int partitionNumber);
