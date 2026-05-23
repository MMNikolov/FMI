#pragma once

#define MAX_NAME_LENGTH 100
#define MAX_BULSTAT_LENGTH 9

struct Company
{
    char name[MAX_NAME_LENGTH + 1];
    char BULSTAT[MAX_BULSTAT_LENGTH + 1];

    Company()
    {
        name[0] = '\0';
        BULSTAT[0] = '\0';
    }
};
