#include <stdio.h>
#include <stdlib.h>
#define OP_MIN '*'
#define OP_SPAN 6

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int dvd(int a, int b);
int calculate(char op, int a, int b);

int main()
{
    int res = calculate('/', 3, 4);
    printf("%d", res);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int dvd(int a, int b)
{
    //lets say that b is the denominator
    if (b == 0)
    {
        puts("Cannot devide by zero");
        return 0;
    }
    
    return a / b;
}

int calculate(char op, int a, int b)
{
    int (*ops[OP_SPAN])(int, int) = { NULL, NULL, NULL, NULL, NULL, NULL };
    ops['*' - OP_MIN] = mul;   
    ops['+' - OP_MIN] = add;   
    ops['-' - OP_MIN] = sub;   
    ops['/' - OP_MIN] = dvd;  

    int index = op - OP_MIN;

    if (index < 0 || index >= OP_SPAN || ops[index] == NULL)
    {
        puts("No such operator");
        return 0;
    }

    return ops[index](a, b);
}
