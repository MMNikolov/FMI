#ifndef ISBN_HPP
#define ISBN_HPP

#include <iostream>

class ISBN
{
public:
    ISBN(int d1, int d2, int d3, int d4, int d5, int d6, int d7,
         int d8, int d9, int d10, int d11, int d12, int d13);

    void print(std::ostream &os) const;
    static ISBN read(std::istream& is);

private:
    static const int LENGTH = 14;
    char digits[LENGTH];

    static bool isValidDigit(int d);

    friend bool operator==(const ISBN& isbn1, const ISBN& isbn2);
};

std::ostream &operator<<(std::ostream &os, const ISBN &isbn);
bool operator==(const ISBN& isbn1, const ISBN& isbn2);

#endif