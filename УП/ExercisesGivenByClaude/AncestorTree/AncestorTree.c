#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findPerson(char ***relations, size_t n, const char *target);
int isAncestor(char ***relations, size_t n, const char *ancestorName, const char *descendantName);

int main()
{
    char *elena[3] = {"Elena", "", ""};
    char *georgi[3] = {"Georgi", "", ""};
    char *ivan[3] = {"Ivan", "Maria", "Petar"};
    char *maria[3] = {"Maria", "Elena", "Georgi"};
    char *petar[3] = {"Petar", "", ""};

    char **table[5] = {elena, georgi, ivan, maria, petar};

    int result = isAncestor(table, 5, "Georgi", "Ivan");
    printf("Georgi ancestor of Ivan? %d\n", result);
    return 0;

    return 0;
}

int findPerson(char ***relations, size_t n, const char *target)
{
    int low = 0;
    int high = (int)n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(relations[mid][0], target);

        if (cmp == 0)
        {
            return mid;
        }
        else if (cmp < 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int isAncestor(char ***relations, size_t n, const char *ancestorName, const char *descendantName)
{
    int idx = findPerson(relations, n, descendantName);
    if (idx == -1)
    {
        return 0;
    }

    char *mother = relations[idx][1];
    char *father = relations[idx][2];

    if (strcmp(mother, ancestorName) == 0 || strcmp(father, ancestorName) == 0)
    {
        return 1;
    }

    int throughMother = 0, throughFather = 0;

    if (strlen(mother) > 0)
    {
        throughMother = isAncestor(relations, n, ancestorName, mother);
    }
    if (strlen(father) > 0)
    {
        throughFather = isAncestor(relations, n, ancestorName, father);
    }

    return throughMother || throughFather;
}