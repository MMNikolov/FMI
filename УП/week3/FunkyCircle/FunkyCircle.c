#include <stdio.h>

int IsInsideTheCircle(int x, int y);

int main()
{
    int x, y, result;
    
    // Read input safely
    if (scanf("%d %d", &x, &y) == 2) 
    {
        result = IsInsideTheCircle(x, y);
        printf("%d\n", result);
    }

    return 0;
}

int IsInsideTheCircle(int x, int y)
{
    // 1. Inside outer boundary
    int in_outer = ((x + 4) * (x + 4) + (y + 1) * (y + 1) <= 37);

    // 2. Outside the small hole
    int outside_hole = ((x + 3) * (x + 3) + (y + 5) * (y + 5) >= 1);

    // 3. Outside the unshaded angular bounds
    int outside_wedge = ((4 * x + y + 15 <= 0) || (x + 6 * y - 2 <= 0));

    if (in_outer && outside_hole && outside_wedge)
    {
        return 1;
    }
    
    return 0;
}