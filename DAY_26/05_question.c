// Q 5 => print this pattern..
/*
ABCDEFG
 ABCDE
  ABC
   A
*/
#include <stdio.h>
void methodTwo();
void methodThree();
int main (){
    for(int i=1; i<=4; i++){
        int temp='A';
        for(int j=1; j<=4; j++){
            if(j>=i){
                printf("%c",temp++);
            }else{
                printf(" ");
            }
        }
        for(int k=1; k<=4-i; k++){
            printf("%c",temp++);
        }
        printf("\n");
    }

    printf("\n\n method 2 \n\n");
    methodTwo();

    printf("\n\n method 3 \n\n");
    methodThree();
    return 0;
}

void methodTwo(){
    int count = 4 * 2 - 1;
    for (int i = 1; i <= 4; i++)
    {
        int temp='A';
        for (int space = 1; space <= i - 1; space++)
        {
            printf(" ");
        }
        for (int j = 1; j <= count; j++)
        {
            printf("%c",temp++);
        }
        count = count - 2;
        printf("\n");
    }
}

void methodThree(){
    for (int i = 1; i <= 4; i++)
    {
        // left half...
        int temp='A';
        for (int j = 1; j <= 4; j++)
        {
            if (j >= i)
            {
                printf("%c",temp++);
            }
            else
            {
                printf(" ");
            }
        }

        // right half but with one less
        for (int k = 4 - 1; k >= 1; k--)
        {
            if (k >= i)
            {
                printf("%c",temp++);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}