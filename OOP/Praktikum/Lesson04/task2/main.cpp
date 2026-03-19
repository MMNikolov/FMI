#include "task2.h"

int main(){
    //1 Initialize the values and create empty fields
    Product* products = new (std::nothrow) Product[ARR_SIZE]();
    if (!products)
    {
        std::cerr << "There is a problem with the memory allocation!";
        return 0;
    }
    initializeSomeValues(products);

    std::ofstream os("products.bin", std::ios::binary | std::ios::out);
    createFields(os, products);

    //2 Update cost of a product by partiotion number
    UpdatePrice(products, 1);

    //3 Delete a product by its partition number
    deleteProduct(products, 3);

    //4 Add a product by partiotion number
    AddProduct(products, 3);

    //5 Write in a txt file the Initialized values
    std::ofstream out("result.txt");
    writeInTxt(out, products);
    

    os.close(); out.close();
    delete[] products;
    std::cout << "Success!";
    return 0;
}