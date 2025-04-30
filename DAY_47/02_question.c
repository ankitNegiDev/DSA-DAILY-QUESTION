// Q 2 => write a function to compare two strings..
/*
(1) equality comparision..
Returns 0 → strings are equal

Returns < 0 → str1 comes before str2

Returns > 0 → str1 comes after str2

(2)  Lexicographical Comparison means which comes first in dictonary..
so for both we create a sing function...
*/

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
int equalityComparision(char *str1, char *str2, int len1, int len2)
{
    // (condition) ? if code : else code;
    int equalCount = 0;
    int greaterLen = len1 > len2 ? len1 : len2;
    for (int i = 0; i < greaterLen; i++)
    {
        if (str1[i] == str2[i])
        {
            equalCount++;
        }
        else if (str1[i] < str2[i])
        {
            return -1; // return < 0 str1 comes before str2
        }
        else if (str1[i] > str2[i])
        {
            return +1; // return > 0 str1 comes after str2
        }
    }
    if (equalCount == len1 && equalCount == len2)
    {
        return 0; // str1 and str2 are equal.
    }
}
int main()
{
    char str1[100];
    printf("enter the value of string 1\n");
    fgets(str1, 100, stdin);
    fflush(stdin);
    char str2[100];
    printf("enter the value of string 2\n");
    fgets(str2, 100, stdin);
    int len1 = calculateLength(str1);
    printf("length of string 1 is %d \n", len1);
    int len2 = calculateLength(str2);
    printf("length of string 2 is %d\n", len2);

    int ans = equalityComparision(str1, str2, len1, len2);
    if (ans == 0)
    {
        printf("both string are equal\n");
    }
    else if (ans < 0)
    {
        printf("the string str1 comes before str2 in dictonary\n");
    }
    else if (ans > 0)
    {
        printf("the string str2 comes before str1 in dictonary\n");
    }
    return 0;
}
