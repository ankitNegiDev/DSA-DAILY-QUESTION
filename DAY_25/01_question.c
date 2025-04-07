// print this pattern
/*
 *
 * *
 * * *
 * * * *
 * * * * *
 */

#include <stdio.h>
int main()
{
    int n;
    printf("enter a number\n");
    scanf("%d", &n);

    // method 1 => using i
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
    */

    // method 2 => printing space and star both..
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // method 3 =>
    for (int i = n; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (j >= i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}