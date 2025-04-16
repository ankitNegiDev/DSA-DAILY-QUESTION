// Q 12 => write a recursive function to print reverese of a give number..

// 123456789 -> store the last digit(n%10) then get rid off last digit (n/10) and repeat process until n is not 0.

#include <stdio.h>
int reverseOfGivenNumber(int n,int reverseNum);
void reverseOfGivenNumberPrint(int n);
int main (){
    int num;
    printf("enter the vlaue of num\n");
    scanf("%d",&num);
    int reverse=0;
    int reverseNum=reverseOfGivenNumber(num,reverse);
    printf("the reverse of given number %d is : %d\n",num,reverseNum);
    printf("\n\n--------method 2 --------\n\n");
    reverseOfGivenNumberPrint(num);
    return 0;
}

int reverseOfGivenNumber(int n,int reverseNum){
    if(n==0){
        return reverseNum;
    }
    int lastDigit = n % 10;
    n = n / 10;
    reverseNum = reverseNum * 10 + lastDigit;
    return reverseOfGivenNumber(n,reverseNum);
}
// if we wana return some value that we got during the function call not while backtracking then always return that value from the base case and make sure when that value goes to function call from where it is called directly return that value..



// 123%10 -> 3
// n= 12

// 12%10 -> 2
// n=1

// 1%10 -> 1
// n=0

void reverseOfGivenNumberPrint(int n){
    if(n==0){
        return ;
    }

    int lastDigit=n%10;
    printf("%d ",lastDigit);
    n=n/10;
    reverseOfGivenNumberPrint(n);
}