#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER 1024

char* readLine()
{
    int capacity = 32;
    int length = 0;
    char* str = malloc(capacity);

    if (str == NULL)
    {
        return NULL;
    }
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if ((length + 1) >= capacity)
        {
            capacity *= 2;
            char* tmp = realloc(str, capacity);

            if (tmp == NULL)
            {
                free(str);
                return NULL;
            }
            str = tmp;
        }
        
        str[length++] = (char)c;
    }
    
    str[length] = '\0';
    return str;
}

int main()
{
    printf("Enter a string: ");
    char* str = readLine();

    if (str != NULL)
    {
        printf("Read it!");
        free(str);
    }
    
    return 0;
}