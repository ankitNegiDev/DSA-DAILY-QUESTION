// 2. Write a program to print the first N terms of the Fibonacci series.

// we do 0 based counting ..
#include <stdio.h>
int main()
{
    int n, first = -1, second = 1, next;
    printf("enter the value of n\n");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
    return 0;
}