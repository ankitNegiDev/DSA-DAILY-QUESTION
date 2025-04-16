// Q 9 => write a program in c to count the digits of a given numbr using recursion...


#include <stdio.h>
int countDigitsRecursive(int n,int count);
int countDigitsRecursiveBacktrack(int n, int count);
int main (){
    int n;
    printf("etner the value of n\n");
    scanf("%d",&n);
    int digitsCount=countDigitsRecursive(n,0);
    printf("the no of digits in %d number are %d \n",n,digitsCount);
    printf("\n\n--------backtrack--------\n\n");
    digitsCount = countDigitsRecursiveBacktrack(n, 0);
    printf("the no of digits in %d number are %d \n", n, digitsCount);
    return 0;
}
int countDigitsRecursive(int n, int count){
    if(n==0){
        return count;
    }
    count++;
    return countDigitsRecursive(n/10,count);
}
int countDigitsRecursiveBacktrack(int n, int count){
    if(n==0){
        return count;
    }
    int ans=countDigitsRecursiveBacktrack(n/10,count);
    ans++;
    return ans;
}