// Q 11 => write a recursive function to print octal of a given decimal number

#include <stdio.h>
void printOctalOfDecimalNumberRecursive(int n);
void printOctalOfDecimalNumberLoop(int n);
int main(){
    int num;
    printf("enter the value of num\n");
    scanf("%d",&num);
    printOctalOfDecimalNumberRecursive(num);
    printf("\n\n--------loop--------\n\n");
    printOctalOfDecimalNumberLoop(num);
    return 0;
}
void printOctalOfDecimalNumberRecursive(int n){
    if(n==0){
        return ;
    }

    int reminder=n%8;
    n=n/8;
    printOctalOfDecimalNumberRecursive(n);
    printf("%d ",reminder);
}
void printOctalOfDecimalNumberLoop(int n){
    int octal[20];
    int i = 0;

    while (n > 0)
    {
        octal[i++] = n % 8;
        n /= 8;
    }

    // print in reverse
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d ", octal[j]);
    }
}