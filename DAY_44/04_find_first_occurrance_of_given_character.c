// Q 4 => write a program to find the first occurrence of a given character in a given string.

#include <stdio.h>

int calculateLength(char *str)
{
    int len;
    for (len = 0; str[len]; len++)
        ;
    str[len - 1] = '\0';
    for (len = 0; str[len]; len++)
        ;
    return len;
}
int firstOccurrence(char *str, char ch)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char str[100];
    char ch;
    printf("enter the value of string \n");
    fgets(str, 100, stdin);
    printf("enter the value of character \n");
    scanf("%c", &ch);
    int len = calculateLength(str);
    printf("the length of %s string is %d\n", str, len);
    int firstOcc = firstOccurrence(str, ch);
    printf("the first occurrance of %c character is %d\n", ch, firstOcc);
    return 0;
}

/*
enter the value of string
aknikt
enter the value of character
k
the length of aknikt string is 6
the first occurrance of k character is 1
*/