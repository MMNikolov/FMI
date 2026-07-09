#include <stdio.h>
#define PI 3.141
#define RADIAN PI/180

int main()
{
    int degrees;
    scanf("%d", &degrees);

    double result = degrees * RADIAN;
    printf("The result is: %lf", result);

    return 0;
}