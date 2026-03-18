#pragma once

#include <fstream>
#include <iostream>
#include <cstring>
#define ARR_SIZE 100

struct Product{
    char description[32];
    int partitionNumber;
    double cost;
};

void initializeSomeValues();
void createFields(std::ofstream& os);
Product UpdatePrice(Product*& products, const int partitionNumber);
void writeInTxt(std::ofstream& os);
void AddProduct(std::ofstream& os, Product& product);
void deleteProduct(std::ifstream& is, const int partitionNumber);
