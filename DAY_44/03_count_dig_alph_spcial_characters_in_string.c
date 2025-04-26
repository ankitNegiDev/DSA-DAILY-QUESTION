// Q 3 => write a program in c to count the total number of alphabets , digits and special characters in a string..

#include <stdio.h>
struct Count
{
    int totalAlphabets;
    int totalDigits;
    int specialCharacters;
};
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

struct Count calculateStringCharacters(char *str)
{
    struct Count c1;
    c1.totalAlphabets = 0;
    c1.specialCharacters = 0;
    c1.totalDigits = 0;
    for (int i = 0; str[i]; i++)
    {
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 97))
        {
            c1.totalAlphabets++;
        }
        else if (str[i] >= 48 && str[i] <= 57)
        {
            c1.totalDigits++;
        }
        else
        {
            c1.specialCharacters++;
        }
    }
    return c1;
}

int main()
{
    char str[100];
    printf("enter the value of string \n");
    fgets(str, 100, stdin);
    int length = calculateLength(str);
    printf("the length of %s string is %d\n", str, length);
    struct Count c1 = calculateStringCharacters(str);
    printf("there are %d alphabets in %s string\n", c1.totalAlphabets, str);
    printf("there are %d digits in %s string\n", c1.totalDigits, str);
    printf("there are %d special character in %s string\n", c1.specialCharacters, str);
    return 0;
}

/*
enter the value of string
ankit9104@gamil.com
the length of ankit9104@gamil.com string is 19
there are 13 alphabets in ankit9104@gamil.com string
there are 4 digits in ankit9104@gamil.com string
there are 2 special character in ankit9104@gamil.com string
*/