// Q 6 => write a recursive function calculate factorial of a given number..

#include<stdio.h>
long long int factRecursive(int n,int count,long long int fact);
long long int factRecursiveBacktrack(int n);
int main (){
    int n;
    printf("enter the vlaue of n\n");
    scanf("%d",&n);
    long long int fact = factRecursive(n,1,1);
    printf("the factorail of %d number is : %lld\n",n,fact);
    printf("\n\n---------method 2 backtrack ---------\n\n");
    fact=factRecursiveBacktrack(n);
    printf("the factorail of %d number is : %lld\n", n, fact);

    printf("\n\n------------\n\n");
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long int: %zu bytes\n", sizeof(long int));
    printf("Size of long long int: %zu bytes\n", sizeof(long long int));

    return 0;
}
long long int factRecursive(int n,int count,long long int fact){
    if(count>n){
        return fact;
    }
    fact=fact*count;
    printf("for %d value of count value of fact is %lld\n",count,fact);
    return factRecursive(n,++count,fact);
}

long long int factRecursiveBacktrack(int n){
    if(n==0){
        return 1;
    }
    return n*factRecursiveBacktrack(n-1);
}

// int takes 4 bytes... format specifier for it is %d
// long int takes 4 bytes(64bit windows) 8bytes on linkux and mac .. format specifier is %ld
// long long int takes 8 bytes format specifiesr is %lld

// Size of int : 4 bytes
    // Size of long int : 4 bytes
        // Size of long long int : 8 bytes