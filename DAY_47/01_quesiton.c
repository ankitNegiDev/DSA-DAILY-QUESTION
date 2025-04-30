// Q 1 => write a function to find a character in a given string . return index of first occurrence of given character. Return -1 if character is not found.

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
int findFirstOccurrenceOfGivenCharacter(char *str, char ch)
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
    printf("enter the value of string \n");
    fgets(str, 100, stdin);
    char ch;
    printf("enter the value of character\n");
    scanf("%c", &ch);
    int len = calculateLength(str);
    printf("length : %d\n", len);
    int occurrance = findFirstOccurrenceOfGivenCharacter(str, ch);
    printf("occurance of %c character is %d\n", ch, occurrance);
    return 0;
}
