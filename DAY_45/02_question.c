// Q 2  Write a function to swap two characters of a given string with specified indics.

#include <stdio.h>

void swapCharacters(char *str, int index1, int index2)
{
    
    if (str[index1] == '\0' || str[index2] == '\0')
    {
        printf("Invalid indices!\n");
        return;
    }

    char temp = str[index1];
    str[index1] = str[index2];
    str[index2] = temp;
}

int main()
{
    char str[] = "abcdef";
    int index1 = 1, index2 = 4;

    printf("Original string: %s\n", str);
    swapCharacters(str, index1, index2);
    printf("String after swapping: %s\n", str);

    return 0;
}
