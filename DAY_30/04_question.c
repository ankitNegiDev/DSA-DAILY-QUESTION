// Q 4 => write a function to print first N natural number 


#include <stdio.h>
void printFirstNNaturalNumber(int n);
int main (){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);

    printFirstNNaturalNumber(n);
    return 0;
}
void printFirstNNaturalNumber(int n){
    for(int i=1; i<=n; i++){
        printf("%d ",i);
    }
}