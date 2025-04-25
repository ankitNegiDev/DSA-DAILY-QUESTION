// Q 4 => write a program to count spaces in a given string..

// its class c problem that character are written in ' ' single queotes if we write "a" then it is considred as string..
#include <stdio.h>
int length(char *str)
{
    int len;
    for (len = 0; str[len]; len++)
        ;
    str[len - 1] = '\0';
    return len;
}
int countSpace(char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
    {
        // printf("str[i] is : %c\n",str[i]);
        if (str[i] == ' ')
        {
            // printf("count is : %d",count);
            count++;
        }
    }
    return count;
}

int main()
{
    char str[100];
    printf("enter the value of string \n");
    fflush(stdin);
    fgets(str, 100, stdin);
    int len = length(str);
    printf("length of %s string is %d\n", str, len);
    int space = countSpace(str);
    printf("there are %d space in the %s stirng \n", space, str);
    return 0;
}