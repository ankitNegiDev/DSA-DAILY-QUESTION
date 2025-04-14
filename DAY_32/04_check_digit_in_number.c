// Q 9 => write a function to check wether a given number contains a given digit or not.

#include <stdio.h>
#include <stdbool.h>
bool checkDigitInNum(int num,int digit);
int main (){
    int num,digit;
    printf("enter the vlaue of num\n");
    scanf("%d",&num);
    printf("enter the value of digit\n");
    scanf("%d",&digit);

    bool ans=checkDigitInNum(num,digit);
    if(ans==1){
        printf("the digit %d is present in number %d\n",digit,num);
    }else{
        printf("the digit %d is NOT present in number %d\n", digit, num);
    }
    return 0;
}
bool checkDigitInNum(int num, int digit){
    while(num!=0){
        int currentDigit=num%10;
        if(currentDigit==digit){
            return 1;
        }
        num=num/10;
    }
    return 0;
}