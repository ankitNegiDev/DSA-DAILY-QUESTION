// Q 10 => print this pattern..
/*
*****
*   *
*   *
*   *
*****
*/

#include <stdio.h>
int main (){
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            /*
            if(i==1 || i==5){
                printf("*");
            }else if(j==1 || j==5){
                printf("*");
            }else{
                printf(" ");
            }
            */
            if(i==1 || i==5 || j==1 || j==5){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}