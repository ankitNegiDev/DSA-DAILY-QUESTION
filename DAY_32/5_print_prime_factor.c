// Q 10 => write a function to print all prime factors of a given number for example if the number is 36 then your result should be 2,2,3,3

#include <stdio.h>
void printPrimeFactor(int num);
int main (){
    int num;
    printf("enter the vlaue of the num\n");
    scanf("%d",&num);

    printPrimeFactor(num);
    return 0;
}

void printPrimeFactor(int num){
    for(int i=2; num!=1;){
        if(num%i==0){
            printf("%d ",i);
            printf("num -> %d\n", num);
            num=num/i;
        }else{
            i++;
        }
        
    }
}
