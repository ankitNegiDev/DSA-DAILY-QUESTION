// Q 2 => write a program in c to copy one string to another char array.

// char str[]={"bingolive"}, char str1[100] -> we need to store it inside the str1.

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

// using pointer approach
void copyStringIntoAnotherCharArray(char *str1, char *str2)
{
    for (int i = 0; str1[i]; i++)
    {
        // str2[i]=str1[i];
        // str2[i] subscript operator evaluates internally like this.. --> *(str2+i)
        *(str2 + i) = *(str1 + i);
    }
}

int main()
{
    char str1[100];
    char str2[100];
    printf("enter the value of string 1\n");
    fgets(str1, 100, stdin);
    fflush(stdin);
    printf("enter the value of string 2\n");
    fgets(str2, 100, stdin);
    int len1 = calculateLength(str1);
    int len2 = calculateLength(str2);
    printf("the length of %s string is %d\n", str1, len1);
    printf("the length of %s string is %d\n", str2, len2);
    copyStringIntoAnotherCharArray(str1, str2);
    printf("the value of string 2 is now replaced by string 1\n");
    printf("str 1 : %s\n", str1);
    printf("str 2 : %s\n", str2);
    return 0;
}