// Q 2 => write a program to count the occurrence of a given character in a given string.

#include <stdio.h>
// calculate correct length
int stringLength(char *str)
{
    int count;
    // str[count] when it become '\0' null character then loop stopes becasue assci code of null character is 0 and 0 is a falsy value..
    for (count = 0; str[count]; count++)
        ;
    // this manual assignment is imp because fgets() takes the newline character when we press the enter. so length will be actuallength + 1 so to nullify it we manually assign the null character.
    str[count - 1] = '\0';
    for (count = 0; str[count]; count++)
        ;
    return count;
}
// reciving the array into array
int occurranceOfGivenCharacter(char str[], char ch)
{
    int occurrance = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == ch)
        {
            occurrance++;
        }
    }
    return occurrance;
}
// reciving the array into the pointer.
int occurranceOfGivenCharacter1(char *str, char ch)
{
    int occurrance = 0;
    for (int i = 0; str[i]; i++)
    {
        if (*(str + i) == ch)
        {
            occurrance++;
        }
    }
    return occurrance;
}
int main()
{
    char str[100];
    char ch;
    printf("enter the value of the character\n");
    scanf("%c", &ch);
    printf("enter the value of string \n");
    // imp to clear the sdin buffer.
    fflush(stdin);
    fgets(str, 100, stdin);
    int length = stringLength(str);
    int occurrance = occurranceOfGivenCharacter(str, ch);
    int occurrance1 = occurranceOfGivenCharacter1(str, ch);
    printf("the occurrance of %c character in %s string  is %d by first function\n", ch, str, occurrance);
    printf("the occurrance of %c character in %s string  is %d by the second function\n", ch, str, occurrance1);
    return 0;
}
