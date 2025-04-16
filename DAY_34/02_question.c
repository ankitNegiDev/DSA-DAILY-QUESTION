// Q 2 => write a recursive function to calculate sum of frist N odd natural number.

// 1 ,3  ,5,   7,    9  ,11,  13 ...n
// 1 -> 4 -> 9 -> 16 ->25 -> 36 ....n

#include <stdio.h>
int sumOfFirstNOddNaturalNumberRecursive(int n,int sum,int count);
int sumOfFirstNOddNaturalNumberRecursiveBacktrack(int n);

int main (){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    int sumOfOdd=sumOfFirstNOddNaturalNumberRecursive(n,0,1);
    printf("the sum of first %d odd natural number is : %d \n",n,sumOfOdd);
    printf("\n\n--------backtrack-------\n\n");
    sumOfOdd= sumOfFirstNOddNaturalNumberRecursiveBacktrack(n);
    printf("the sum of first %d odd natural number is : %d \n", n, sumOfOdd);
    return 0;
}
int sumOfFirstNOddNaturalNumberRecursive(int n, int sum,int count){
    if(count>n){
        return sum;
    }
    sum=sum+2*count-1;
    printf("for %d count sum is  : %d\n",count,sum);
    count++;
    return sumOfFirstNOddNaturalNumberRecursive(n,sum,count);
}

int sumOfFirstNOddNaturalNumberRecursiveBacktrack(int n){
    if(n==0){
        return 0;
    }
    printf("---hello backtrack\n");
    int ans = n*2-1+sumOfFirstNOddNaturalNumberRecursiveBacktrack(n-1);
    printf("for n %d value sum is %d\n",n,ans);
    return ans;
}