// Q 3 => write a program to count vowels in a given string.

// vowels are : aeiou

#include <stdio.h>
int stringLength(char *str)
{
    int count;
    for (count = 0; str[count]; count++)
        ;
    printf("length is %d\n", count);
    str[count - 1] = '\0';
    for (count = 0; str[count]; count++)
        ;
    printf("length is %d\n", count);
    return count;

    // Remove newline safely
    /*
    int count =0;
    while (str[count] != '\0')
    {
        if (str[count] == '\n')
        {
            str[count] = '\0';
            break;
        }
        count++;
    }

    printf("length is %d\n", count);
    printf("heloooo\n");
    return count;
    */
}
int countVowels(char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            count++;
        }
    }
    return count;
}
int main()
{
    char str[100];
    printf("enter the vlaue of string \n");
    fgets(str, 100, stdin);
    int length = stringLength(str);
    printf("length of string is %d\n", length);
    int vowels = countVowels(str);
    printf("there are %d vowels in %s string\n", vowels, str);
    return 0;
}
