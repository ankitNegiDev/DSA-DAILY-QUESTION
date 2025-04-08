// Q 3 => print this pattern..

/*
   * 
  * *
 * * *
* * * *

*/
#include <stdio.h>
int main (){
    int n;
    printf("enter the value of num\n");
    scanf("%d",&n);

    // so the approach is simple .. print the n-1 space first and print 1 star second print n-2 space and print 2 start..
    for(int i=1; i<=n; i++){
        // printing space..
        for(int space=1; space<=n-i; space++){
            printf(" ");
        }

        // printing start.
        for(int j=1; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}