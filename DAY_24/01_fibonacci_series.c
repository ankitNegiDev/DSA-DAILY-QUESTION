// 1. Write a program to find the Nth term of the Fibonacci series.

/**
 * in fibonacci series first two terms are 0 and 1 and next term is the sum of pervious two term.
 * 0,1,1,2,3,5,8,13,21,34,55 ..... n
 */
// if we do 1 based counting then 5 term is 5 (n-2) and if we do 0 based then 5th term is 3 (n-1).
/*
#include <stdio.h>
int main (){
    int n, a = 0, b = 1, c;
    printf("enter the value of n\n");
    scanf("%d", &n);
    if(n==0){
        printf("please enter the positive integer\n");
    }else if(n==1){
        printf("the %d terms in fibonacci series is %d\n", n, a);
    }else if(n==2){
        printf("the %d terms in fibonacci series is %d\n", n, b);
    }else{
        for (int i = 0; i < n - 1; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        printf("the %d terms in the fibonacci series is %d\n", n, b);
    }
    
    return 0;
}
*/

// modifying the avobe solution.... to avoid the if else we can find the 1st and 0th term of fibonacci series..

// here if we do 0 based counting then 10th term is 55 (<=n) and if we do 1 based counting then 10th term is 34(n-1)
#include <stdio.h>
int main (){
    int n, a = -1, b = 1, c;
    printf("enter the value of n\n");
    scanf("%d", &n);
    for (int i = 0; i <= n ; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    printf("the %d terms in the fibonacci series is %d\n", n, c);
}
// first creating a program that will print the first N fibonacci number..
/*
#include <stdio.h>
int main (){
    int a=0, b=1, c, n;
    printf("enter the value number\n");
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}
*/
