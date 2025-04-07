// Q 7 => print this pattern..
/*
ABCDE
 ABCD
  ABC
   AB
    A
*/

/*
#include <stdio.h>
int main(){
    int count = 0;
    for(int i='A'; i<='E'; i++){
        for(int j='A'; j<='E'; j++){
            if(i<=j){
                printf("%c",j-count);
            }else{
                printf(" ");
            }
        }
        printf("\n");
        count++;
    }
    return 0;
}
*/

// optimisize the above code.

#include <stdio.h>
int main (){
    for(int i=0; i<5; i++){

        for(int k=0; k<i; k++){
            printf(" ");
        }
        // print the character from A to E-i means if i=0 the print all from a to e and if i=1 then print a to d etc. but we need to explecitely print the space..
        for(int j='A'; j<='E'-i; j++){
            printf("%c",j);
        }
        printf("\n");
    }


    // method 2 -> we can take a variable and initialize it with 'A' for each row and do incriment every time when it is printed..
    for(int i=1; i<=5; i++){
        int k='A';
        for(int j=1; j<=5; j++){
            if(j>=i){
                printf("%c",k++);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}