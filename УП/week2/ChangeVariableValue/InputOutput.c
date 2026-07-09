#include <stdio.h>

int main()
{
    int number1;
    unsigned number2;
    double number3;
    char character;

    scanf("%d %u %lf %c", &number1, &number2, &number3, &character);

    printf("The first number is %d\n", number1);
    printf("The second number is %u\n", number2);
    printf("The third number is %lf\n", number3);
    printf("The the character is %c\n", character);

    number1 = 1;
    number2 = 1132;
    number3 = 312312.31231;
    character = ';';

    printf("The first number is %d\n", number1);
    printf("The second number is %u\n", number2);
    printf("The third number is %lf\n", number3);
    printf("The the character is %c\n", character);

    return 0;
}