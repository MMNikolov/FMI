#include "tree.hpp"

int main(){
    std::ifstream is("trees.txt");
    if (!is.is_open())
    {
        std::cerr << "There was a problem with the file management!";
        return 0;
    }
    
    //tree 1
    tree tree1;
    tree1.readFile(is);

    tree1.printCharacteristics();

    //tree 2
    //I literally have no idea why it goes immediatly to the next line when reading the file, but I aint complaining
    tree tree2;
    tree2.readFile(is);

    tree2.printCharacteristics();

    return 0;
}