#include "task3.hpp"

int main(){
    //Initialization of the Tuples
    srand(time(NULL));
    Tuple<int, int> tuple1;
    Tuple<int, int> tuple2;
    tuple1 = init(tuple1);
    tuple2 = init(tuple2);

    //Displaying the tuples
    display(tuple1);
    display(tuple2);

    return 0;
}