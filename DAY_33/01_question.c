// Q 1 => write a recursive function to print first n natural numbers...

#include <stdio.h>

void printNNaturalNumber(int n);
void printNNaturalNumberMethod2(int n,int originalNum);
int main (){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    printNNaturalNumber(n);
    printf("\n\n-------method 2 --------- \n");
    printNNaturalNumberMethod2(n,n);
    return 0;
}

// step 1 => assumsing that what we have to make it is done..
void printNNaturalNumber(int n){
    // step 2 => base case ..
    if(n<1){
        return;
    }

    // step 3 => recursive case .
    printNNaturalNumber(n-1);

    // in ascending or increaing order...
    printf("%d ", n);
}

// step 1 => jo banan hae assume karo ki ban chuka hae..
void printNNaturalNumberMethod2(int n, int originalNum){
    // step 2 -> base case 
    if(n==0){
        return ;
    }

    printf("%d ",originalNum+1-n);
    // step 3 => recursive case ..

    printNNaturalNumberMethod2(n-1,originalNum);
}

