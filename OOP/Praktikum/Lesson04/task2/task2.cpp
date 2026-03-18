#include "task2.h"

void initializeSomeValues()
{
    Product products[3];
    strcpy(products[0].description, "Banana");
    products[0].partitionNumber = 1;
    products[0].cost = 2.2;
    strcpy(products[1].description, "Apple");
    products[1].partitionNumber = 2;
    products[1].cost = 1.8;
    strcpy(products[2].description, "Vegetable");
    products[2].partitionNumber = 3;
    products[2].cost = 3.2;
};

void createFields(std::ofstream& os)
{
    if (!os.is_open())
    {
        std::cerr << "There was a problem with the initialization of the 100 free spaces";
        return;
    }
    
    Product emptyEntry;
    strcpy(emptyEntry.description, "Nothing");
    emptyEntry.partitionNumber = 0;
    emptyEntry.cost = 0.0;

    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
        os.write(reinterpret_cast<char*>(&emptyEntry), sizeof(emptyEntry));
    }
};

Product UpdatePrice(Product*& products, const int partitionNumber)
{
    Product p;
    return p;
};

void writeInTxt(std::ofstream& os){
    return;
};

void AddProduct(std::ofstream& os, Product& product){
    return;
};

void deleteProduct(std::ifstream& is, const int partitionNumber){
    return;
};