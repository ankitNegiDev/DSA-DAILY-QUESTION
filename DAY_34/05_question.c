// Q 5 => write a recursive function to calculate sum of digits of a given number..

// 123456 -> 1+2+3+4+5+6 ->21

#include <stdio.h>
int sumOfDigitsRecursive(int n,int sum);
int sumOfDigitRecursiveBacktrack(int n);
int main (){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    int sumOfDigits=sumOfDigitsRecursive(n,0);
    printf("the sum of %d digits is %d\n",n,sumOfDigits);
    sumOfDigits=sumOfDigitRecursiveBacktrack(n);
    printf("the sum of %d digits is %d\n", n, sumOfDigits);
    return 0;
}
int sumOfDigitsRecursive(int n,int sum){
    if(n==0){
        return sum;
    }
    int lastDigit=n%10;
    sum=sum+lastDigit;
    // n=n/10;
    return sumOfDigitsRecursive(n/10,sum);
}

int sumOfDigitRecursiveBacktrack(int n){
    if(n==0){
        return 0;
    }
    int lastDigit=n%10;
    int ans = sumOfDigitRecursiveBacktrack(n/10)+lastDigit;
    return ans;
}