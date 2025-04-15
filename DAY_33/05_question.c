// Q 5 => write a recursive function to print first n even natural number...


#include <stdio.h>
void printFirstNEvenNaturalNumber(int n);
void printFirstNEvenNaturalNumberMethod2(int n, int originalNum);
int main(){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);

    printf("the first %d even natural number are \n",n);
    printFirstNEvenNaturalNumber(n);
    printf("\n\n---------method 2 --------\n");
    printFirstNEvenNaturalNumberMethod2(n,n);
    return 0;
}

// stpe 1 => assume karo kii jo banana hase wo ban chuka ahe ..
void printFirstNEvenNaturalNumber(int n){
    // ste p2 => base case ..
    if(n<1){
        return;
    }
    // step 3 => recursive case ...
    printFirstNEvenNaturalNumber(n-1);
    printf("%d ",n*2);
}

// step1 => assuem jo banana hase wo ban chuka hae ..
void printFirstNEvenNaturalNumberMethod2 (int n, int originalNum)
{
    // stpe 2 => base case 
    if(n<1){
        return;
    }
    // step 3 => recursive case .
    printf("%d ",originalNum*2+2-n*2);
    printFirstNEvenNaturalNumberMethod2(n - 1, originalNum);
}