#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
    
    unsigned randomNum;
    unsigned ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0;
    for (unsigned i = 0; i < n; i++)
    {
        randomNum = (rand() % 6) + 1;
        if (randomNum == 1)
        {
            ones++;
        }
        else if (randomNum == 2)
        {
            twos++;
        }
        else if (randomNum == 3)
        {
            threes++;
        }
        else if (randomNum == 4)
        {
            fours++;
        }
        else if (randomNum == 5)
        {
            fives++;
        }
        else if (randomNum == 6)
        {
            sixes++;
        }
    }
    
    printf("Ones: %d\nTwos: %d\nThrees: %d\nFours: %d\nFives: %d\nSixes: %d\n", ones, twos, threes, fours, fives, sixes);

    return 0;
}