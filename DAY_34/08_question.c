// Q 8 => write a recursive function to print the first N terms of fibonacci series..

#include <stdio.h>

void printFiboRecursive(int n);
int calculateFibo(int n);


int main (){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    printFiboRecursive(n);
    return 0;
}
int calculateFibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return calculateFibo(n-1)+calculateFibo(n-2);
}
void printFiboRecursive(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", calculateFibo(i));
    }
    printf("\n");
}

