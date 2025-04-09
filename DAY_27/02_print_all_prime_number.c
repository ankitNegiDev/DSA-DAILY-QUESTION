// 6. Write a program to print all prime numbers under 100.

// method 1..
/*
#include <stdio.h>
int main()
{
    for (int i = 2; i <= 100; i++)
    {
        int j;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (i == j)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
*/

// other way...
/*
#include <stdio.h>
#include <stdbool.h>
int main (){
    for (int i = 2; i <= 100; i++){
        int j = 2;
        bool isPrime = 1;
        while(j<i){
            if(i%j==0){
                isPrime = 0;
                break;
            }
            j++;
        }
        if(isPrime){
            printf("%d ", i);
        }
    }
    return 0;
}
*/

// more concise and valid acc to question.
#include <stdio.h>
int main (){
    int lowerLimit, upperLimit;
    printf("enter the lower limit and upper limit value\n");
    scanf("%d %d", &lowerLimit, &upperLimit);
    for (int i = lowerLimit; i <= upperLimit; i++){
        int j;
        for (j = 2; j < i; j++){
            if(i%j==0){
                break;
            }
        }
        if(i==j){
            printf("%d ", i);
        }
    }
    return 0;
}