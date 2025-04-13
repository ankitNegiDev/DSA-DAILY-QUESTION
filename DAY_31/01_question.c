// 7. Write a program to print the greater number between two numbers.Print one number if both are the same.

#include <stdio.h>
int main (){
    int num1, num2;
    printf("enter the two number num1 and num2 \n");
    scanf("%d %d", &num1, &num2);
    if(num1>num2){
        printf("the %d number is greater number\n", num1);
    }else if (num2>num1){
        printf("the %d number is greater number\n", num2);
    }else{
        printf("the %d both number are same \n", num1);
    }
    return 0;
}