#include <stdio.h>

int isPrime(int n);

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }
    
    printf("%d", isPrime(n));

    return 0;
}

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    // Check for factors from 5 to sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}   
