// Q 2 => print this pattern 
/*
            *
          * *
        * * * 
      * * * * 
    * * * * * 
*/


#include <stdio.h>
int main(){
    int num;
    printf("enter a number \n");
    scanf("%d",&num);
    for(int i=0; i<num; i++){
        for(int j=num-1; j>=0; j--){
            if(j<=i){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    // method 2 => 
    for(int i=num; i>0; i--){
        for(int j=1; j<=num; j++){
            if(i<=j){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    // method 3 => 
    for(int i=1; i<=num; i++){
        for(int j=1; j<=num; j++){
            if(j>=(num+1)-i){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}