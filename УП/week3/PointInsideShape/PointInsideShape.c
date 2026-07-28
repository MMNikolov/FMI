#include <stdio.h>

int IsInsideFigure1(int x, int y);
int IsInsideFigure2(int x, int y);
int IsInsideFigure3(int x, int y);
int IsInsideFigure4(int x, int y);

int main()
{
    int x, y, result;
    scanf("%d %d", &x, &y);

    printf("Is it in the first Figure?\n");
    result = IsInsideFigure1(x, y);
    printf("%d\n", result);

    printf("Is it in the second Figure?\n");
    result = IsInsideFigure2(x, y);
    printf("%d\n", result);

    printf("Is it in the third Figure?\n");
    result = IsInsideFigure3(x, y);
    printf("%d\n", result);

    printf("Is it in the fourth Figure?\n");
    result = IsInsideFigure4(x, y);
    printf("%d\n", result);

    return 0;
}

int IsInsideFigure1(int x, int y)
{
    if (x >= -1 && x <= 1 && y >= -1 && y <= 1)
    {
        return 1;
    }
    
    return 0;
}

int IsInsideFigure2(int x, int y)
{
    if (x >= 1 && x <= 2 && y >= 1 && y <= 2)
    {
        return 1;
    }

    return 0;
}

int IsInsideFigure3(int x, int y)
{
    if ((x - 1) * (x - 1) + (y - 1) * (y - 1) <= 1)
    {
        return 1;
    }

    return 0;
}

int IsInsideFigure4(int x, int y)
{
    if (y >= 0)
    {
        if ((x * x + y * y <= 4) && ((x - 1) * (x - 1) + y * y >= 1))
        {
            return 1;
        }
    }
    else
    {
        if ((x + 1) * (x + 1) + y * y <= 1)
        {
            return 1;
        }
    }

    return 0;
}