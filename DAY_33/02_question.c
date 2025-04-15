// Q 2 => write a recursive function to print frist N natural number in reverse order..

#include <stdio.h>
void printNNaturalNumberReverseOrder(int n);
void printNNaturalNumberReverseOrderMethod2(int n,int originalNum);

int main (){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    printf("the first %d natural number are \n",n);
    printNNaturalNumberReverseOrder(n);
    printf("\n\n----------- method 2 ------------\n");
    printNNaturalNumberReverseOrderMethod2(n,n);
    return 0;
}

// step 1 => jo bana hae assume karo ki wo ban chuka hae.
void printNNaturalNumberReverseOrder(int n){
    // step 2 => think of base case .
    if(n<1){
        return ;
    }
    printf("%d ",n); // 10 ->  9 -> 8 .... -> 2 -> 1
    // step 3 => recursive case ..
    printNNaturalNumberReverseOrder(n-1);
}


// step 1 -> jo banana hae assume karo kii ban chuckaaa hae.
void printNNaturalNumberReverseOrderMethod2(int n, int originalNum){
    // step 2 => base case 
    if(n==0){
        return ;
    }

    // stpe 3 => recursive case ..
    printNNaturalNumberReverseOrderMethod2(n-1,originalNum);
    printf("%d ",originalNum+1-n);
}