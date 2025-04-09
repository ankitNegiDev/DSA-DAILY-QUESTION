// 7. Write a program to print all prime numbers between two given numbers.

/*
#include <stdio.h>
int main (){
    int num1, num2;
    printf("enter the value of num1 and num2\n");
    scanf("%d %d", &num1, &num2);
    if(num1>=num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    for (int i = num1; i <= num2; i++){
        int j = 2;
        while(i>j){
            if(i%j==0){
                break;
            }
            j++;
        }
        if(i==j){
            printf("%d ", i);
        }
    }
    return 0;
}
*/

#include <stdio.h>
int main()
{
    int lowerLimit, upperLimit;
    printf("enter the lower limit and upper limit value\n");
    scanf("%d %d", &lowerLimit, &upperLimit);
    for (int i = lowerLimit; i <= upperLimit; i++)
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