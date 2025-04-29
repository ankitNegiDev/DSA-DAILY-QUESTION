// Q 1 => Write a function to check whether a given string is palindrome or not.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[])
{
    int start = 0;
    // we can use inbuilt string length function..
    int end = strlen(str) - 1;

    while (start < end)
    {
        if (str[start] != str[end]){
            return 0;
        }
        // else part..
        start++;
        end--;
    }
    return 1;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str,100,stdin);

    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
