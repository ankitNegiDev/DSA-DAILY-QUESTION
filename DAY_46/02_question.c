// Q 2 => Write a function to trim a string (removing leading spaces from both the ends). write the c code of these two function

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim(char *str)
{
    int start = 0, end = strlen(str) - 1;

    while (isspace(str[start]))
        start++;
    while (end > start && isspace(str[end]))
        end--;

    int i = 0;
    while (start <= end)
    {
        str[i++] = str[start++];
    }
    str[i] = '\0';
}

int main()
{
    char str[100];
    printf("Enter a string with spaces: ");
    fgets(str,100,stdin);

    trim(str);
    printf("Trimmed string: '%s'\n", str);

    return 0;
}
/**
Function	              Description
isspace(int c) 	 ======>  Checks if character is a whitespace (space, tab, newline, etc.)
isalnum(int c)	 ======>  Checks if character is alphanumeric (A–Z, a–z, 0–9)
isalpha(int c)	 ======>  Checks if character is a letter
isdigit(int c)	 ======>  Checks if character is a digit
tolower(int c)	 ======>  Converts character to lowercase
toupper(int c)
 */
