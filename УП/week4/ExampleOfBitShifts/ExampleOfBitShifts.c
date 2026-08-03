#include <stdio.h>

int main()
{
    unsigned int x = 1; // 0000000000000001
    
    // Example of bit-shifts and going over the powers of 2 and 
    for (int i = 0; i <=8; ++i)
    {
        printf("2^%d = %hu\n", i * 2, x);
        x <<= 2;
    }

    return 0;
}