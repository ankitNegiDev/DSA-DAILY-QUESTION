// Q 7 => write a function to calculate the number of combinations one can make from the n items and r selected at a time.

#include <stdio.h>
int factorial(int num);
int combination(int n,int r);
int main()
{
    int n,r;
    printf("enter the value of n,r\n");
    scanf("%d %d",&n,&r);

    int result = combination(n, r);

    printf("Number of combinations (C(%d, %d)) = %d\n", n, r, result);

    return 0;
}

int factorial(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}

int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}