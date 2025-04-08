// Q 4 => print this pattern.
/*
   1
  121
 12321
1234321
*/
#include <stdio.h>
void methodTwo();
int main (){
    int n;
    printf("etner the value of n\n");
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        int temp = 1;
        for(int j=n; j>=2; j--){
            if(i>=j){
                printf("%d",temp++);
            }else{
                printf(" ");
            }
        }
        // printf("\n");
        temp=i;
        for(int j=1; j<=n; j++){
            if(i>=j){
                printf("%d",temp--);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n\n method 2 \n\n");
    methodTwo();
    return 0;
}

// in method two we are dpending the j value to i means for each row we are printing the left half first then right half...
void methodTwo(){
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        // Print spaces first ..
        for (int space = 1; space <= n - i; space++)
        {
            printf("  ");
        }

        // left half
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }

        // right half
        for (int j = i - 1; j >= 1; j--)
        {
            printf("%d ", j);
        }

        printf("\n");
    }
}