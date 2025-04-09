// 8. Write a program to find the next prime number of a given number.

#include <stdio.h>
int main (){
    int number;
    printf("enter the value of number\n");
    scanf("%d", &number);
    // int i = 2;  
    /**
     * if we write i=2 then for no 23 it will start checking from 2 is 2 is a prime or not .. but to improve the logic we will prefer to check from number + 1 because we need to find the next prime number.
     */
    int i = number+1;
    while(1){
        // printf("%d i is \n", i); 
        int j = 2;
        while(i>j){
            if(i%j==0){
                break;
            }
            j++;
        }
        // if(i==j && i>number){
        //     printf("%d ", i);
        //     break;
        // }
        // the above if is valid if we start from the i=2 .. then we need to check is the prime no is greater then current number or not but now since we know prime no will be always greater then number so no need to put that condition i>number.
        if(i==j){
            printf("%d ", i);
            break;
        }
        i++;
    }
}

