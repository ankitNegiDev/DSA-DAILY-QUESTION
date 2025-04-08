// Q 9 => print this pattern..

/*
1234321
123 321
12   21
1     1
*/

#include <stdio.h>
int main()
{
    int num;
    printf("enter the value of num\n");
    scanf("%d", &num);
    for (int i = num; i >= 0; i--)
    {
        for (int j = 1; j <= num - 1; j++)
        {
            if (i >= j)
            {
                printf("%d",j);
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
                printf("%d",j);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}