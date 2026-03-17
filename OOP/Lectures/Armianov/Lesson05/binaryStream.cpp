#include <iostream>
#include <fstream>
#include <cstring>
#define BUFFER_SIZE 1024
/*
3 problems with this code:
- the standart for different OS is different
- the padding is a problem (the computer reads form top to bottom) (the padding reads the biggest bit variable and devides by it)
*/

enum Spec{
    Inf,
    Is,
    Cs
};

struct Student {
    int age;
    Spec s;
    char name[18]; //if we want to remove the padding we put name[18]
} arr[20];

int main(){
    arr[0].age = 10;
    strcpy(arr[0].name, "a");
    arr[0].s = Cs;
    
    arr[1].age = 8273;
    strcpy(arr[1].name, "abort");
    arr[1].s = Is;
    std::ofstream os{"something.bin", std::ios::binary};
    os.write((char*)arr, 20 * sizeof(Student));

    if (!os.is_open())
    {
        std::cerr << "There was a problem with the output stream";
        return -1;
    }

    std::ifstream is("something.bin", std::ios::binary);
    is.read((char*)arr, 20 * sizeof(Student));

    if (!is.is_open())
    {
        std::cerr << "There was a problem with the input stream";
        return -1;
    }

    for (int i = 0; i < 20; i++)
    {   
        if (arr[i].age == 0)
        {
            break;
        }
        std::cout << "Student Number " << i + 1 << "\n";
        std::cout << arr[i].age << "\n" << arr[i].s << "\n" << arr[i].name << "\n";
    }
    
    os.close();
    is.close();
    return 0;
}

struct Point
{
    float x, y, z;
};

void printPoint(const Point& point, std::ostream& os){
    os << '(' << point.x << ';' << point.y << ';' << point.z << ')';
}

bool readPointCorrect(std::istream& is, Point& pt){
    Point p;
    char o, c1, c2, c;
    is >> o >> p.x >> c1 >> p.y >> c2 >> p.z >> c;

    if (is && o == '(' && c1 == ',' && c2 == ',' && c == ')')
    {
        pt.x = p.x;
        pt.y = p.y;
        pt.z = p.z;
        return true;
    }
    return false;
}

bool copy(const char* str, const char* dest){
    std::ifstream is(str, std::ios::binary | std::ios::in);
    if (!is.is_open())
    {
        std::cerr << "There was an error with the copy function (is)";
        return false;
    }
    
    std::ofstream os(dest, std::ios::binary | std::ios::out);
    if (!os.is_open())
    {
        std::cerr << "there was an error with the copy function (os)";
        return false;
    }
    char buffer[BUFFER_SIZE];

    while (!is.eof() && !is.bad())
    {
        is.read(buffer, BUFFER_SIZE);
        os.write(buffer, is.gcount());
    }
    
    os.flush();
    return os && is.eof();
};

//how do we delete stuff in a text file
//(1, 2, 3) (7, 6, 12.3) (-1, -2, 0) {<-- we want to delete this one} (5, 3, 9)
bool clearPoint(const char* filename){
    std::ifstream is(filename, std::ios::in);

    if (!is.is_open())
    {
        std::cerr << "There was an error with the clear function (is)";
        return false;
    }

    std::ofstream temp("temp.txt", std::ios::out);

    if (!temp.is_open())
    {
        std::cerr << "There was an error with the clear function (os)";
        return false;
    }
    
    Point p;
    while (readPointCorrect(is, p))
    {
        if (p.x >= 0 && p.y >= 0 && p.z >= 0)
        {
            printPoint(p, temp);

            if (!temp.is_open())
            {
                std::cerr << "there was an error with the temp file";
            }
        }
        temp.flush();
        if (temp)
        {
            temp.close();
            is.close();
            //....
        }
        //...

    }
    return true;
}
