// Q 8 => print this pattern..
/*
*******
*** ***
**   **
*     *
*/

#include <stdio.h>
int main (){
    int num;
    printf("enter the value of num\n");
    scanf("%d", &num);
    for (int i = num; i >= 0; i--)
    {
        for (int j = 1; j <= num-1; j++)
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
        for (int j = num; j > 0; j--)
        {
            if (j <= i)
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