// Q 9 => print this pattern..
/*
ABCDE
 BCDE
  CDE
   DE
    E
*/
#include <stdio.h>
int main (){
    for(int i='A'; i<='E'; i++){
        for(int j='A'; j<='E'; j++){
            if(i<=j){
                printf("%c",j);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    // method 2 => 
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            if(i<=j){
                printf("%c",64+j);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}