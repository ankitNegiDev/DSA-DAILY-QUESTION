// Q 1 => write a recursive function to calculate sum of first N natural numbers.

#include <stdio.h>
int sumOfFirstNNaturalNumberRecursive(int n,int count,int sum);
int sumOfFirstNNaturalNumberRecursiveBacktrack(int n);
int main (){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    int sum=sumOfFirstNNaturalNumberRecursive(n,1,0);
    printf("the sum of first %d number sum is : %d\n",n,sum);
    printf("\n\n----------backtrack---------\n\n");
    sum = sumOfFirstNNaturalNumberRecursiveBacktrack(n);
    printf("the sum of first %d number sum is : %d\n", n, sum);
    return 0;
}
int sumOfFirstNNaturalNumberRecursive(int n,int count,int sum){
    if(count>n){
        return sum;
    }
    sum=sum+count;
    count++;
    return sumOfFirstNNaturalNumberRecursive(n,count,sum);
}
// count 1 -> sum = 1
// count 2 -> sum = 3
// count 3 -> sum = 6
// count 4 -> sum = 10
// count 5 -> sum = 15
// count 6 -> sum = 21
// count 7 -> sum = 28
// count 8 -> sum = 36
// count 9 -> sum = 45
// count 10 -> sum = 55
// count 11-> return sum and sum is 55 and then just return the sum in the backtrack...


// keep in mind that when we are doing task in the function call and just before the base case we got the result then always pass that result back from the base case and do nothing in backtrack just reutrn that result...

// but when we are dealing with backtrack then keep in mind that we need to do with the line in which we are doing function call.. just think.. if we think we can take the count = 0 initially and in backtrack we do count ++ and then add it sum and return the sum ... but in backtrack (or previous) call there will be value of count 0 and if we do count ++ it becaome 1 for each back track call.. eitherwe need to pass back count also but in reutrn we can pass only one value at a time but if we wana send more value then we can use object and array...

int sumOfFirstNNaturalNumberRecursiveBacktrack(int n){
    if(n==0){
        return 0;
    }

    return n+sumOfFirstNNaturalNumberRecursiveBacktrack(n-1);
}

// n=10 -> function call(1)... [n+45] -> 10 +45 -> 55 return 55 ot function call inside main function..
// n= 9 -> function call(2).. [n+36] -> 9+36 -> 45 return 45 yto function 1
// n=8 -> function call(3).. [n+28] -> 8+28 -> 36 return 36 yo function call 2
// n= 7 -> function call(4).. [n+21] -> 7+21 -> 28 return 28 to function call 3
// n=6 -> functio ncall(5) [n+15] -> 6+15 -> 21 return 21 to function call 4
// n=5 -> function call(6) [n+10] -> 5+10 -> 15 return 15 to function call 5
// n=4 -> function call(7) [n+6] -> 4+6 -> 10 return 10 to function call 6
// n=3 -> function call(8) [n+3] -> 3+3 -> 6 return 6 to function call 7
// n=2 -> function call(9) [ n+1] -> 2+1 -> 3 return 3 to function call 8
// n=1 -> function call(10) [ n+0] -> 1 return 1 to function call 9
// n=0 -> base case hit ... return 0 to function call 10.