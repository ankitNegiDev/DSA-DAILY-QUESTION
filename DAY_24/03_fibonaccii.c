// 3. Write a program to check whether a given number is there in the Fibonacci series or not.
/*
#include <stdio.h>
int main (){
    int number,first=0,second=1,next;
    printf("enter the vlaue of the number\n");
    scanf("%d", &number);
    for (int i = 0; first <= number-1; i++){
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n\n%d value of first \n",first);
    if(first>number){
        printf("the %d number is not in the fibonacci series\n", number);
    }else{
        printf("the %d number is in the fibonacci series\n", number);
    }
    printf("\n");
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdbool.h>
int main()
{
    int number, first = 0, second = 1, next;
    printf("enter the value of number\n");
    scanf("%d", &number);
    bool isFibonacci = false;
    if (number == 0)
    {
        printf("the %d number is in the fibonacci series\n", number);
    }
    else
    {
        while (second <= number)
        {
            if (number == second)
            {
                isFibonacci = true;
                break;
            }
            next = first + second;
            first = second;
            second = next;
        }
        if (isFibonacci)
        {
            printf("the %d number is in the fibonacci series\n", number);
        }
        else
        {
            printf("the %d number is not in the fibonacci series\n", number);
        }
    }

    return 0;
}
*/

#include <stdio.h>
int main()
{
    int number, first = -1, second = 1, next;
    printf("enter the value of number\n");
    scanf("%d", &number);
    int i = 0;
    while (1)
    {
        next = first + second;
        if (next == number)
        {
            printf("the %d number is present in the fibonacci series at %d position\n", number, i);
            break;
        }
        if (next > number)
        {
            printf("the %d number is not in the fibonacci series\n", number);
            break;
        }
        i++;
        first = second;
        second = next;
    }
    return 0;
}