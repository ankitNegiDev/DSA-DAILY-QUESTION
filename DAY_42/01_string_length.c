// Q 1 => write a program to calculate the length of the string (with using builtin methods)

#include <stdio.h>
int stringLength(char *ptr);
int improvedStringLength(char *str)
{
    int count;
    // str[count] or str[count] != '\0' means str[count] != null or str[count] != 0 since ascii code of null character is 0
    for (count = 0; str[count]; count++)
        ;
    str[count - 1] = '\0';
    for (count = 0; str[count]; count++)
        ;
    return count;
}
int main()
{
    char str[100];
    printf("enter the value of string\n");
    fgets(str, 100, stdin);
    int length = stringLength(str);
    printf("the length of %s string is %d\n", str, length);
    // int len = improvedStringLength(str);
    // printf("length of string using improved is %d\n", len);
    return 0;
}
int stringLength(char *ptr)
{
    int len = 0;
    for (int i = 0; ptr[i]; i++)
    {
        len++;
    }
    printf("the length with newline character is %d \n", len);
    ptr[len - 1] = '\0';
    len = 0;
    for (int i = 0; i < ptr[i]; i++)
    {
        len++;
    }
    printf("the length without newline character is %d\n", len);
    return len;
}