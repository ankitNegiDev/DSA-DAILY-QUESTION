// Q 5 => write a function to print first N odd natural number..

#include <stdio.h>
void printNOddNaturalNumber(int n);
int main (){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);

    printNOddNaturalNumber(n);
    return 0;
}

void printNOddNaturalNumber(int n){
    
    for(int i=1; i<=n*2; i++){
        printf("%d ",i);
        i++;
    }
    printf("\n\n");
    
    int i=1;
    while(i<=n*2){
        printf("%d ",i);
        i=i+2;
    }
    printf("\n\n");

    for(int i=1; i<=n; i++){
        printf("%d ",2*i-1);
    }
}
