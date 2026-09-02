#include <stdio.h>
#include <stdlib.h>

int sumOfSquares(size_t a);
int sequence(size_t a, size_t k, size_t n);
int kBalanced(size_t a, size_t A, size_t n);

int main()
{
    size_t a, k, n;
    if (scanf("%zu %zu %zu", &a, &k, &n) != 3)
    {
        return 1;
    }

    int sequenceCount = sequence(a, k, n);
    printf("%d\n", sequenceCount);

    int itterations = kBalanced(a, 20, n);
    if (itterations == -1)
    {
        puts("didnt reach");
    }
    printf("%d\n", itterations);

    return 0;
}

int sumOfSquares(size_t a)
{
    int sum = 0, digit = 0;

    while (a)
    {
        digit = a % 10;
        sum += digit * digit;
        a /= 10;
    }

    return sum;
}

int sequence(size_t a, size_t k, size_t n)
{
    int res = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a == k)
        {
            res++;
        }
        a = sumOfSquares(a);
    }

    return res;
}

int kBalanced(size_t a, size_t A, size_t n)
{
    int sumOfSequenceOfA = 0;
    int k = 0;
    
    for (size_t i = 0; i < n; i++)
    {
        sumOfSequenceOfA += a;
        a = sumOfSquares(a);
        if (sumOfSequenceOfA > A)
        {
            return k;
        }
        
        k++;
    }
    
    return -1;
}
