/*
Дадено е цяло положително число a. Разглеждаме редицата a1, a2, a3, ..., където a1 = a и за i>1, ai е 
равно на сумата от квадратите на цифрите на ai−1.

а) Напишете функция sequence, която за дадени цяли положителни числа a, k и n, пресмята колко пъти 
k се среща измежду първите n члена на разглежданата редица.

б) За дадено a казваме, че редицата е k-балансирана, ако сумата на първите ѝ k елемента е по-малка от 
дадено число A, а сумата на първите (k + 1) елемента е по-голяма или равна на A. Напишете програма, 
която прочита от стандартния вход стойност за a, след което прочита последователно стойности за A, 
до прочитането на отрицателно число, и за всяка прочетена стойност, извежда за кое k редицата е k-балансирана. 
Ако няма такава стойност на k по-малка или равна на 1000 да се изведе текста "MAX". Помислете 
как да реализирате програмата си максимално ефективна.

Пример:

Вход за a = 12 следващите елементи на редицата са 5, 25, 29, 85, 89, …

При:
A = 5,   k = 0 (тук имаше грешка май, защото това не е правилен отговор)
А = 20, k = 2, защото сумата на първите два члена е 17, а на първите три е 42.
*/

#include <stdio.h>
#define MAX_ITTERATIONS 1000

unsigned sequence(unsigned a, unsigned k, unsigned n);
int get_balance(unsigned a, int A);

int main()
{
    unsigned a;
    puts("Choose a number: ");
    if (scanf("%d", &a) != 1)
    {
        puts("There should only be one entry!");
        return 0;
    }
    
    int A;
    do
    {
        printf("Select A: ");
        if(scanf("%d", &A) != 1) return -1;

        int k = get_balance(a, A);
        k > MAX_ITTERATIONS  && puts("MAX");
        k <= MAX_ITTERATIONS && printf("The seqence is k balanced for: %d\n", k);
    } 
    while (a >= 0);
    

    return 0;
}

unsigned sequence(unsigned a, unsigned k, unsigned n)
{
    unsigned result = 0;
    unsigned to_calculate = a;

    for (unsigned i = 0; i < n; i++)
    {
        unsigned curr = 0;
        do
        {
            unsigned digit = to_calculate % 10;

            curr += digit * digit;
        } 
        while (to_calculate /= 10);
        
        if (curr == k)
        {
            result++;
        }
        to_calculate = curr;
    }
    
    return result;
}

int get_balance(unsigned a, int A)
{
    unsigned to_calculate = a;
    unsigned sum = a;

    for (unsigned i = 0; i < MAX_ITTERATIONS; i++)
    {
        unsigned curr = 0;

        do
        {
            unsigned digit = to_calculate % 10;
            curr += digit * digit;
        } 
        while (to_calculate /= 10);
        
        if(sum < A && sum + curr >= A) return i;

        sum += curr;
        to_calculate = curr;
    }
    
    return MAX_ITTERATIONS;
}
