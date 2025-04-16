// Q 4 => write a recursive function to calculate sum of square of first n natural numbers.

// 1, 4, 9...n
// 1, 5, 14 ...n

#include <stdio.h>
int sumOfSquareRecursive(int n,int count,int sum);
int sumOfSquareRecursiveBacktrack(int n);
int main (){
    int n;
    printf("enter the valeu of n\n");
    scanf("%d",&n);
    int sumOfSquare=sumOfSquareRecursive(n,1,0);
    printf("the sum of square of first %d natural number is %d\n",n,sumOfSquare);
    printf("\n\n---------backtrack ----------\n\n");
    sumOfSquare= sumOfSquareRecursiveBacktrack(n);

    printf("the sum of square of first %d natural number is %d\n", n, sumOfSquare);

    return 0;
}
int sumOfSquareRecursive(int n ,int count, int sum){
    if(count>n){
        return sum;
    }
    sum=sum+count*count;
    printf("for %d value of count sum of square is %d\n", count, sum);

    int ans = sumOfSquareRecursive(n,++count,sum);
    return ans;
}
int sumOfSquareRecursiveBacktrack(int n){
    if(n==0){
        return 0;
    }
    printf("----hello backtrack----\n");
    int ans = n*n+sumOfSquareRecursiveBacktrack(--n);
    printf("for the %d value of n the sum of square is %d\n",n,ans);
    return ans;
}