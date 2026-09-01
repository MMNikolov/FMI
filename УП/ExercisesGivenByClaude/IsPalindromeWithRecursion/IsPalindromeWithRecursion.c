#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STARTING_CAPACITY 8

int isPalindrome(const char* str);
int isPallindromeHelper(const char* str, int start, int end);
char* readLine();

int main()
{
    char* str = readLine();

    int palindrome = isPalindrome(str);
    if (palindrome)
    {
        puts("Yes! the string is palindrome");
    } 
    else
    {
        puts("No! the string isnt palindrome");
    }

    free(str);
    return 0;
}

int isPalindrome(const char *str)
{
    if (str == NULL)
    {
        puts("There is no string to check if it is pallindrome");
        return 0;
    }
    return isPallindromeHelper(str, 0, strlen(str) - 1);
}

int isPallindromeHelper(const char *str, int start, int end)
{
    //this is our base case
    if (start >= end)
    {
        return 1;
    }
    
    if (str[start] != str[end])
    {
        return 0;
    }
    
    return isPallindromeHelper(str, start + 1, end - 1);
}

char *readLine()
{
    int capacity = STARTING_CAPACITY;
    int length = 0;

    char* str = (char*)malloc(sizeof(char) * capacity);
    if (str == NULL)
    {
        puts("string didnt allocate correctly");
        return NULL;
    }

    int c;
    while ((c = getchar()) != '\0' && c != '\n' && c != EOF)
    {
        if (length + 1 >= capacity)
        {
            char* temp = (char*)realloc(str, sizeof(char) * capacity * 2);
            if (temp == NULL)
            {
                puts("Didnt reallocate correctly");
                return NULL;
            }

            str = temp;
            capacity *= 2;
        }
        
        str[length++] = c;
    }
    
    str[length] = '\0';
    return str;
}
