// 10. Write a program to find the greatest among three given numbers.Print the number once if the greatest number appears two or three times.

/*
#include <stdio.h>
int main (){
    int num1, num2, num3;
    printf("enter the value of the num1,num2,num3\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    if((num1>num2) && (num1>num3)){
        printf("the greatest number is %d\n", num1);
    }else if ((num2>num1) && (num2>num3)){
        printf("the greatest number is %d\n", num2);
    }else if ((num3>num1) && (num3>num2)){
        printf("the greates number is %d\n", num3);
    }else if((num1==num2) &&(num2==num3)){
        printf("the number is same so %d \n", num1);
    }else{
        printf("some error occured\n");
    }
    return 0;
}
*/

// another approch is 
#include <stdio.h>
int main (){
    int a, b, c;
    printf("enter the value of a,b,c\n");
    scanf("%d %d %d", &a, &b, &c);
    if(a>b){
        if(a>c){
            printf("the %d a is the greatest among all \n", a);
        }else{
            printf("the %d c is the greatest among all\n", c);
        }
    }else{
        if(b>c){
            printf("the %d b is the greatest among all \n", b);
        }else{
            printf("the %d c is the greatest among all \n", c);
        }
    }
    return 0;
}