// Q 6 => write a recursive function to print first N even natural number in reverse order..

#include <stdio.h>
void printFirstNEvenNaturalNumberInReverse(int n);
void printFirstNEvenNaturalNumberInReverseMethod2(int n, int originalNum);
int main(){
    int n;
    printf("etner the vlaue of n\n");
    scanf("%d",&n);

    printf("the first %d even number in reverse order are :\n",n);
    printFirstNEvenNaturalNumberInReverse(n);
    printf("\n\n-------method 2 -----------\n\n");
    printFirstNEvenNaturalNumberInReverseMethod2(n,n);
    return 0;
}

// step 1 => assume karo kii jo bnana hae wo ban chuka hae..
void printFirstNEvenNaturalNumberInReverse(int n){
    // step 2 => base case 
    if(n<1){
        return ;
    }
    // step 3 => recursive case ..
    printf("%d ",n*2);
    printFirstNEvenNaturalNumberInReverse(n-1);
}

// stpe 1 => jo bnana hae assuem karo ki wo bna chucka hae ..
void printFirstNEvenNaturalNumberInReverseMethod2(int n, int originalNum){
    // stpe 2 => base case .
    if(n<1){
        return ;
    }
    // stpe 3 => recursive case ..
    printFirstNEvenNaturalNumberInReverseMethod2(n-1,originalNum);
    printf("%d ",originalNum*2+2-n*2);
}