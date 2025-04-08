// Q 2 => print this pattern..

/*
    * * * * *   * * * * *
      * * * *   * * * *
        * * *   * * *
          * *   * *
            *   *
*/

/*
*********
 *******
  *****
   ***
    *
*/
#include <stdio.h>
void methodOne(int num);
void methodTwo(int num);
int main (){
    int num;
    printf("enter the value of number \n");
    scanf("%d",&num);

    methodOne(num);
    methodTwo(num);
    return 0;
}
void methodOne(int num){
    // method 1 -> step 1 take the count and decrease  it 2 times after the row end..
    // step 2 => first print the space i-1 times if row is 1 then i is 1 so space need to be printed are 0.. and num*2-1 is the formula to calculate how many star wil lbe printed on the each row.. so once we have num do this and then decrease -2 simple.
    int count = num*2-1;
    for (int i = 1; i <= num; i++){
        for (int space = 1; space <=i-1; space++){
            printf(" ");
        }
        for (int j = 1; j <= count; j++)
        {
            printf("*");
        }
        count = count -2;
        printf("\n");
    }
}

// method 2...
void methodTwo(int num){
    for(int i=1; i<=num; i++){
        // left half...
        for(int j=1; j<=num; j++){
            if(j>=i){
                printf("*");
            }else{
                printf(" ");
            }
        }

        // right half but with one less
        for(int k=num-1; k>=1; k--){
            if(k>=i){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}