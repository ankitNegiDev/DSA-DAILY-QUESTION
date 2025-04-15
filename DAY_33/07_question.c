// Q 7 => write a recursive function to print the square s of firsst n natural number..

#include <stdio.h>
void printSquareOfFirstNNaturalNumber(int n);
void printSquareOfFirstNNaturalNumberMethod2(int n, int originalNum);
int main (){
    int n;
    printf("etner the vlaue of n\n");
    scanf("%d",&n);

    printf("the square of first %d natural number are \n");
    printSquareOfFirstNNaturalNumber(n);
    printf("\n\n-------- method 2 ----------\n");
    printSquareOfFirstNNaturalNumberMethod2(n,n);

    return 0;
}

// step 1 => jo banaha hase assuem karo ki ban chuka ahes .
void printSquareOfFirstNNaturalNumber(int n){
    // stpe 2 => base case ..
    if(n<1){
        return;
    }

    // recursive case .
    printSquareOfFirstNNaturalNumber(n-1);
    printf("%d ",n*n);
}

// step 1 => jo banana hase assume karo ki ban chuka hae.
void printSquareOfFirstNNaturalNumberMethod2(int n, int originalNum){
    // stpe 2 => base case ..
    if(n<1){
        return;
    }
    // recursive case ..
    printf("%d ",(originalNum+1-n)*(originalNum+1-n));
    printSquareOfFirstNNaturalNumberMethod2(n-1,originalNum);
}
