#include <iostream>
#include <fstream>
#define ARR_SIZE 10
/*
1.Save an array of numbers in a binary file
2.Read the elements from the file (terminal work)
3.Write the corresponding numbers in a text file
    3.1.In the text file u need to write average of those numbers    
    3.2.In the text file u need to write and the most common number
*/

bool write_array(const int* arr, std::ofstream& os);
int* read_array(std::ifstream& is);
void writeStats(int*& arr, std::ofstream& os);
int mostFrequentNumber(int* arr);

int main(){
    int arr[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::ofstream os("numbers.bin", std::ios::binary | std::ios::out);
    if (!os.is_open())
    {
        std::cerr << "There was a problem with the opening of the output binary file";
        return 0;
    }
    
    bool flagWrite = write_array(arr, os);
    if (!flagWrite)
    {
        std::cerr << "The initialization of the array didnt come through!";
        return 0;
    }

    os.close();

    std::ifstream is("numbers.bin", std::ios::binary | std::ios::in);
    if (!is.is_open())
    {
        std::cerr << "There was a problem with the opening of the input binary file";
        return 0;
    }

    int* newArr = read_array(is);
    
    std::ofstream out("statistics.txt");
    if (!out.is_open())
    {
        std::cerr << "There was a problem with the opening of the output text file";
        return 0;
    }
    
    writeStats(newArr, out);

    is.close(); out.close();;
    delete[] newArr;
    return 0;
}


bool write_array(const int* arr, std::ofstream& os){
    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
        os.write(reinterpret_cast<const char*>(arr), ARR_SIZE * sizeof(int));
    }

    return true;
}

int* read_array(std::ifstream& is){
    int* arr = new (std::nothrow) int[ARR_SIZE];
    if (!arr)
    {
        std::cerr << "Problem with the initialization of the array in the read_array function!";
        return {};
    }
    
    int i = 0;

    is.read(reinterpret_cast<char*>(arr), ARR_SIZE * sizeof(int));
    
    return arr;
}

void writeStats(int*& arr, std::ofstream& os){
    int sum = 0;

    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
        sum += arr[i];
    }
    os << "The size of the array: " << ARR_SIZE << "\n";

    os << "The array: ";
    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
        os << arr[i] << ' ';
    }
    os << "\n";

    double avg = (double)sum / ARR_SIZE;
    os << "The sum avg is: " << avg << "\n";

    int mostFrequent = mostFrequentNumber(arr);
    os << "The most frequent number in the array is: " << mostFrequent << "\n";
}

int mostFrequentNumber(int* arr){
    int maxCount = 0;
    int res = 0;

    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
        int count = 0;
        for (unsigned int j = 0; j < ARR_SIZE; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        
        if (count > maxCount || count == maxCount && arr[i] > res)
        {
            maxCount = count;
            res = arr[i];
        }
    }
    
    return res;
}