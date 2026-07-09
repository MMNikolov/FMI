#include <stdio.h>

int main()
{
    int number, sum, digit;
    scanf("%d", &number);

    while (number > 0)
    {
        digit = number % 10;
        printf("%d\n", digit);
        number /= 10;
        sum += digit;
    }
    
    printf("Sum: %d", sum);

    return 0;
}