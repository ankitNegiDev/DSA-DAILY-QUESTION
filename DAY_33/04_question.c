// Q 4 => write a recursive function to print first N odd natural number in reverse order..

#include <stdio.h>
void printFirstNOddNaturalNumberInReverse(int n);
void printFirstNOddNaturalNumberInReverseMethod2(int n, int originalNum);

int main(){
    int n;
    printf("etner the value of n\n");
    scanf("%d",&n);
    printf("odd number in reverse order are : \n");
    printFirstNOddNaturalNumberInReverse(n);
    printf("\n\n--------method 2 ----------\n");
    printFirstNOddNaturalNumberInReverseMethod2(n,n);
    return 0;
}
// step 1 => assume karo ki jo banana hae wo ban chuka hae..
void printFirstNOddNaturalNumberInReverse(int n){
    // step 2 => base case ..
    if(n<1){
        return;
    }

    // step 3 => recursive case ...
    printf("%d ",n*2-1);
    printFirstNOddNaturalNumberInReverse(n-1);
}


// step 1 => assume karo ki jo banan hae wo ban chuka ahae..
void printFirstNOddNaturalNumberInReverseMethod2(int n , int originalNum){
    // step 2 => base case 
    if(n<1){
        return;
    }

    // step 3 => recursie case ..
    printFirstNOddNaturalNumberInReverseMethod2(n-1,originalNum);
    printf("%d ",originalNum*2+1-n*2);
}