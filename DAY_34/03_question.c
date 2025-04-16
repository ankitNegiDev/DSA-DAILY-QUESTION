// Q 3 => write a recursive function to calculate sum of first N even natural number...

// 2,4,6,8...n
// 2,6,12,20...n

#include <stdio.h>
int sumOfFirstNEvenNaturalNumberRecursive(int n,int sum,int count);
int sumOfFirstNEvenNaturalNumberRecursiveBacktrack(int n);

int main (){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    int sumOfEven= sumOfFirstNEvenNaturalNumberRecursive(n,0,1);
    printf("the sum of first %d even naturla number is %d : \n",n,sumOfEven);
    printf("\n\n----------backtrack---------\n\n");
    sumOfEven= sumOfFirstNEvenNaturalNumberRecursiveBacktrack(n);
    printf("the sum of first %d even naturla number is %d : \n", n, sumOfEven);
    return 0;
}
int sumOfFirstNEvenNaturalNumberRecursive(int n, int sum, int count){
    if(count>n){
        return sum;
    }

    sum=sum+count*2;
    return sumOfFirstNEvenNaturalNumberRecursive(n,sum,++count);
}

int sumOfFirstNEvenNaturalNumberRecursiveBacktrack(int n){
    if(n==0){
        return 0;
    }
    // int ans =  n*2+sumOfFirstNEvenNaturalNumberRecursiveBacktrack(n--);
    int ans = n * 2 + sumOfFirstNEvenNaturalNumberRecursiveBacktrack(--n);

    printf("for %d value of n sum is %d\n",n,ans);
    return ans;
}

// when we pass n-- in function like post incriment or post decriment then ... keep in mind first the value will be used then it will be either incrimented or decrimentd... so what happens here is every time the function call... the value of n which is 10 is passed in every function call and it became the infinit recursion.
