#include "task2.h"

/*
1.Create an array with random values - done
2.Update the product price with the partition number - done
3.Write a file named "result.txt" with every single WRITTEN product - done
4.Add a product in the txt file
5.Delete product by partiotion number
*/
static int k = 1;

Product* initializeSomeValues(Product*& products)
{
    products[0].partitionNumber = k++;
    strcpy(products[0].description, "Apple");
    products[0].cost = 2.2;
    products[1].partitionNumber = k++;
    strcpy(products[1].description, "Banana");
    products[1].cost = 1.8;
    products[2].partitionNumber = k;
    strcpy(products[2].description, "Vegetable");
    products[2].cost = 1.2;

    return products;
};

void createFields(std::ofstream& os, Product*& products)
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

    for (unsigned int i = 0; i < INITIALIZED_DATA; i++)
    {
        os.write(reinterpret_cast<char*>(&products[i]), sizeof(Product));
    }

    for (unsigned int i = INITIALIZED_DATA; i < ARR_SIZE; i++)
    {
        os.write(reinterpret_cast<char*>(&emptyEntry), sizeof(emptyEntry));
    }
};

Product UpdatePrice(Product*& products, const int partitionNumber)
{
    if (!products)
    {
        return {};
    }

    double newCost;

    for (unsigned int i = 0; i < INITIALIZED_DATA; i++)
    {
        if (products[i].partitionNumber == partitionNumber)
        {
            std::cout << "Enter the new cost for the product: ";
            std::cin >> newCost;

            products[i].cost = newCost;
            return products[i];
        }
    }
    
    std::cerr << "There is no such partiotion number!\n";
    return {};
};

void writeInTxt(std::ofstream& os, Product*& products){
    if (!os.is_open())
    {
        std::cerr << "there was a problem with the output stream in the txt file!";
        return;
    }
    
    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
        os << products[i].partitionNumber << ' ' 
           << products[i].description << ' '
           << products[i].cost << "\n";
    }
};

void AddProduct(Product*& products, const int partitionNumber){
    if (partitionNumber < 0 || partitionNumber >= ARR_SIZE) {
        std::cerr << "Invalid partition number. Must be 0-99.\n";
        return;
    }

    if (products[partitionNumber - 1].partitionNumber != -1 && products[partitionNumber - 1].partitionNumber != 0) {
        std::cerr << "Slot already taken. Delete first or update price.\n";
        return;
    }

    std::cout << "Enter description: ";
    std::cin >> products[partitionNumber - 1].description;
    std::cout << "Enter cost: ";
    std::cin >> products[partitionNumber - 1].cost;
    products[partitionNumber - 1].partitionNumber = partitionNumber;
    
    std::cout << "Product added.\n";
};

void deleteProduct(Product*& products, const int partitionNumber){
    if (partitionNumber < 0 || partitionNumber >= ARR_SIZE)
    {
        std::cerr << "Invalid partiotion Number! \n";
        return;
    }
    
    if (products[partitionNumber - 1].partitionNumber == -1)
    {
        std::cerr << "Product is already deleted";
        return;
    }
  
    products[partitionNumber - 1].cost = 0;
    strcpy(products[partitionNumber - 1].description, "Deleted");
    products[partitionNumber - 1].partitionNumber = -1;
};