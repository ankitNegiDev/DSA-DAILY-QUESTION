// Q 1 => print this pattern.
/*
         *  // 1
       * * *    // 1+2
     * * * * *  // 3+2
   * * * * * * *    // 5+2 
do +2 each time..
 */

/**
            *   *
          * *   * *
        * * *   * * *
      * * * *   * * * *
    * * * * *   * * * * *

 * the only thing we have to do is merge the middle column..
 */
#include <stdio.h>
void methodTwo(int num);
int main (){
    int num;
    printf("enter the value of num\n");
    scanf("%d",&num);

    // method 1 -> step 1 take the count and increae it 2 times after the row end..
    // step 2 => first print the space num-i times if row is 1 and num is 4 then it means there are 3 space and at 4th position * is present.
    int count=1;
    for(int i=1; i<=num;i++){
        for(int space=1; space<=num-i; space++){
            printf(" ");
        }
        for(int j=1; j<=count; j++){
            printf("*");
        }
        count=count+2;
        printf("\n");
    }


    // method 2 => 
    methodTwo(num);

    return 0;

}

void methodTwo(int num){
    for(int i=1; i<=num; i++){
        // left half..
        for(int j=num; j>0; j--){
            if(i>=j){
                printf("*");
            }else{
                printf(" ");
            }
        }
        // now right half but we will run loop from 2 not from 1 because we want to skip the middle row..
        for(int k=2; k<=num; k++){
            if(i>=k){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}