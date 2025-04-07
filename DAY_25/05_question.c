// Q 5 => print this pattern
/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/

#include <stdio.h>
int main(){
    int n;
    printf("enter a number\n");
    scanf("%d",&n);
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            if(i>=j){
                printf("%d ",j);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    // method 2 => 
    for(int i=n; i>0; i--){
        for(int j=n; j>0; j--){
            if(i<=j){
                printf("%d ",n+1-j);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}