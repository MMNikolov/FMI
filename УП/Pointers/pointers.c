#include <stdio.h>

int main()
{
    int x = 10;
    int* px = &x;

    printf("Value of x: %d\n", x);
    printf("Value of px: %d\n", px);
    printf("Value of x: %p\n", x);
    printf("Value of x: %p\n", px);

    printf("size of pointer: %dB\n", sizeof(int*));

    return 0;
}