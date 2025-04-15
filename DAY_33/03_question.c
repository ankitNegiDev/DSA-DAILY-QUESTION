// Q 3 => write a recursive function to print first N odd natural numbers ..

#include <stdio.h>
void printFirstNOddNaturalNumber(int n);
void printFirstNOddNaturalNumberMethod2(int n, int originalNum);
int main (){
    int n;
    printf("etner the valeu of n\n");
    scanf("%d",&n);
    printf("the first %d odd natural number are : \n");
    printFirstNOddNaturalNumber(n);
    printf("\n\n------------method 2 -------------\n");
    printFirstNOddNaturalNumberMethod2(n,n);
    return 0;
}
// step 1 => assume karo ki jo bana hae wo ban chuka hae.
void printFirstNOddNaturalNumber(int n){
    // step 2 => base case .
    if(n<1){
        return ;
    }

    // step 3 => recursive case ..
    printFirstNOddNaturalNumber(n-1);
    printf("%d ",n*2-1);
}

// step 1 => assume karo ki jo bana hae wo ban chukaa hae.
void printFirstNOddNaturalNumberMethod2(int n,int originalNum){

    // step 2 => base case .
    if(n<1){
        return ;
    }

    // step 3 => recursive case ...
    printf("%d ",(originalNum*2+1) - n*2 );
    printFirstNOddNaturalNumberMethod2(n-1,originalNum);
}