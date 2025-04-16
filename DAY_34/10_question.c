// Q 10 => write a program to calculate the power of any number using recursion..

#include <stdio.h>
int powerRecursive(int n, int p,int power);
int powerRecursiveBacktrack(int n,int p);
int main (){
    int n,p;
    printf("etner the value of number and raise to power\n");
    scanf("%d %d",&n,&p);
    int result=powerRecursive(n,p,1);
    printf("%d raise to %d power is %d\n",n,p,result);
    printf("\n\n---------backtrack--------\n\n");
    result=powerRecursiveBacktrack(n,p);
    printf("%d raise to %d power is %d\n", n, p, result);

    return 0;
}
int powerRecursive(int n, int p,int power){
    if(p==0){
        return power;
    }
    power=power*n;
    return powerRecursive(n,--p,power);
}

int powerRecursiveBacktrack(int n, int p){
    if(p==0){
        return 1;
    }
    return n*powerRecursiveBacktrack(n,--p);
}