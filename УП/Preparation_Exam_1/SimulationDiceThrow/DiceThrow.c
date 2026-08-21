#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* печата: етикет, брой, процент, и '*' лента пропорционална на процента */
void printBar(const char *label, unsigned count, unsigned total)
{
    double percent = (total == 0) ? 0.0 : (100.0 * count) / total;
    int barLen = (int)(percent / 2.0); /* 1 звезда на всеки 2% -> лента до 50 символа */

    printf("%-8s: %6u  (%5.2f%%)  ", label, count, percent);
    for (int i = 0; i < barLen; i++)
    {
        putchar('*');
        putchar('*');
    }
    putchar('\n');
}

int main()
{
    srand(time(NULL));
    unsigned n;
    printf("Tell me the number of times u want to row the dice: ");
    if (scanf("%u", &n) != 1)
    {
        printf("Not a valid enterence!");
        return 0;
    }

    unsigned randomNum1;
    unsigned randomNum2;
    unsigned twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0;
    unsigned sevens = 0, eights = 0, nines = 0, tens = 0, elevens = 0, twelves = 0;
    for (unsigned i = 0; i < n; i++)
    {
        randomNum1 = (rand() % 6) + 1;
        randomNum2 = (rand() % 6) + 1;

        if (randomNum1 + randomNum2 == 2)
        {
            twos++;
        }
        else if (randomNum1 + randomNum2 == 3)
        {
            threes++;
        }
        else if (randomNum1 + randomNum2 == 4)
        {
            fours++;
        }
        else if (randomNum1 + randomNum2 == 5)
        {
            fives++;
        }
        else if (randomNum1 + randomNum2 == 6)
        {
            sixes++;
        }
        else if (randomNum1 + randomNum2 == 7)
        {
            sevens++;
        }
        else if (randomNum1 + randomNum2 == 8)
        {
            eights++;
        }
        else if (randomNum1 + randomNum2 == 9)
        {
            nines++;
        }
        else if (randomNum1 + randomNum2 == 10)
        {
            tens++;
        }
        else if (randomNum1 + randomNum2 == 11)
        {
            elevens++;
        }
        else if (randomNum1 + randomNum2 == 12)
        {
            twelves++;
        }
    }

    printBar("Two   ", twos, n);
    printBar("Three ", threes, n);
    printBar("Four  ", fours, n);
    printBar("Five  ", fives, n);
    printBar("Six   ", sixes, n);
    printBar("Seven ", sevens, n);
    printBar("Eight ", eights, n);
    printBar("Nine  ", nines, n);
    printBar("Ten   ", tens, n);
    printBar("Eleven", elevens, n);
    printBar("Twelve", twelves, n);

    return 0;
}