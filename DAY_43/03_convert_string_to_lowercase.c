// Q 6 => write a program to covert a string into lowercse .
// Q 5 => write a program to convert a given string into uppercase..

// 'A' = 65, 'Z' = 90, 'a'= 97, 'z' = 122
// A -> 65 -> a= 97 diff is 32
// B -> 66 -> b=98 diff is 32

#include <stdio.h>
int countLen(char *str)
{
    int len;
    for (len = 0; str[len]; len++)
        ;
    str[len - 1] = '\0';
    for (len = 0; str[len]; len++)
        ;
    return len;
}
void convertStringToLowerCase(char *str)
{
    // to convert string into upper case we need to iterate.
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            printf("the %c character is already in lowercase \n", str[i]);
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            printf("befor changing character is %c\n", str[i]);
            str[i] = str[i] + 32;
            printf("the changed charcter is %c\n", str[i]);
        }
    }
}
int main()
{
    char str[100];
    printf("enter the value of string\n");
    fflush(stdin);
    fgets(str, 100, stdin);
    int len = countLen(str);
    printf("length of %s string is %d\n", str, len);
    convertStringToLowerCase(str);
    printf("lowerCase string is : %s\n", str);
    return 0;
}
