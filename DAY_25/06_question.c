// Q 6 => print this pattern

/*
1
21
321
4321
*/

#include <stdio.h>
int main(){
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            if(i>=j){
                printf("%d", (i-j + 1));
            }
        }
        printf("\n");
    }

    // method 2 ... take another variable and assign value of i into it for each row and decrease it once it is printed every time..
    for(int i=1; i<=4; i++){
        int k=i;
        for(int j=1; j<=4; j++){
            if(i>=j){
                printf("%d",k--);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
