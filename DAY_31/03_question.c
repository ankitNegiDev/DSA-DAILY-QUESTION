// 9. Write a program to check whether a given year is a leap year or not.
// we will not check check divisibility of centeuary year by 4 because every centuary year is divisible by 4 so to get leap year we will check divisibility by 400.
#include <stdio.h>
int main(){
    int year;
    printf("enter the value of the year\n");
    scanf("%d", &year);
    // first checking the given year is centery year or not .
    if(year%100==0){
        printf("the %d year is a centuary year\n", year);
        // now checking is this centuary year is a leap year or not ..
        if(year%400==0){
            printf("the %d centuary year is a leap year\n", year);
        }else{
            printf("the %d centuary year is not a leap year\n", year);
        }
    }else{
        printf("the %d year is not the centuary year\n", year);
        if(year%4==0){
            printf("the %d non-centuary year is a leap year\n", year);
        }else{
            printf("the %d non-centuary year is not a leap year\n", year);
        }
    }
    return 0;
}