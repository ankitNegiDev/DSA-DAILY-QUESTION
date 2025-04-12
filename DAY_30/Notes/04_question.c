// 4. Write a program to check whether a given number is an even number or an odd number without using the % operator.

// method 1 => using * and / operator.
/*
#include <stdio.h>
int main (){
    int number;
    printf("enter the value of the number \n");
    scanf("%d", &number);
    // this method work fine without doing absolute number but if we want we can..
    if((number/2)*2==number){
        printf("the %d number is a even number\n", number);
    }else if ((number/2) *2 != number){
        printf("the %d number is a odd number\n", number);
    }
    return 0;
}
*/

// method 2 => using the subtraction operator (-)
// can we use + - operator . yes we can use the + - operator ... the approach is simple the even number reduced to 0 and odd number reduced to 1 on doing subtraction until value is greater then equal 2.
/*
#include <stdio.h>
int main (){
    int number;
    printf("enter the value of the number \n");
    scanf("%d", &number);

    int absNumber = number < 0 ? -number : number;
    // printf("the value of absNumber is %d\n", absNumber);
    while(absNumber>=2){
        absNumber = absNumber - 2;
    }
    if(absNumber==0){
        printf("the %d number is even number\n",number);
    }else if (absNumber == 1){
        printf("the %d number is odd number\n", number);
    }
    return 0;
}
*/

// method 3 => using addition operator (+)
// using the same approach but with the addition operator .. adding 2 upto we did not cross the original number and then doing the difference of that variable in which we add 2 and original number if their difference is 0 thet means it is even number and if it is 1 then it is odd number..

/*
#include <stdio.h>
int main(){
    int number;
    printf("enter the value of the number\n");
    scanf("%d", &number);
    int calculatingSum = 0, absNumber;
    absNumber = number < 0 ? -number : number;
    // printf("the value of the %d \n", absNumber);
    // running a loop to calculating the sum..
    while(calculatingSum<absNumber){
        // calculatingSum = calculatingSum + 2;
        calculatingSum += 2;
    }
    // if(calculatingSum-absNumber==0) we can also use this condition..
    if(calculatingSum==absNumber){
        printf("the %d number is even number\n", number);
    }else if (calculatingSum-absNumber==1){
        printf("the %d number is odd number \n", number);
    }
    return 0;
}
*/

// we can use bitwise operator to check the odd even number ..
//! keep in mind that we are using else if condition just for a beginer friendly approach to check weather the both condition satisfy or not but we can definitly remove the else if with else..

/**
 * it is imp to note that the precedence of the bitwise operator is lower then the comparision operator or equality operator ..
 * All bitwise operators (&, |, ^, <<, >>) have lower precedence than comparison (==, !=, <, >, etc.) in C
 */

// method 4 => using bitwise AND (&) operator.
/*
#include <stdio.h>
int main(){
    int number;
    printf("enter the value of the number \n");
    scanf("%d", &number);
    if((number&1)==0){
        printf("the %d number is a even number \n", number);
    }else if ((number&1)!=0){
        printf("the %d number is a odd number \n", number);
    }
    return 0;
}
*/


/**
 * explanation of & bitwise operator how it is helpful in the doing the divisibilty check...asm
 *      128 64 32 16 8 4 2 1 
 *   10  0   0  0  0 1 0 1 0
 *   1   0   0  0  0 0 0 0 1
 *  &    0   0  0  0 0 0 0 0    so for even number 10 & 1 == 0 that means even number & 1 == 0
 *   0   0   0  0  0 0 0 0 0 
 *   1   0   0  0  0 0 0 0 1  
 *   &   0   0  0  0 0 0 0 0  so for even number 0 & 1 == 0 that means even number &1 ==0


 **  128 64 32 16 8 4 2 1
    9 0  0   0  0 1 0 0 1
    1 0  0   0  0 0 0 0 1
    & 0  0   0  0 0 0 0 1    so for odd number 9 & 1 == 1 that means odd number & 1 == 1 or we can say odd number & 1 != 0

    1 0  0   0  0 0 0 0 1
    1 0  0   0  0 0 0 0 1 
    & 0  0   0  0 0 0 0 1   so for odd number it is 1 & 1 == 1 or we can say 1&1 != 0
 */

// checking other bitwise operator ..
/**
 ** (1) | or bitwise operator ...

        128 64 32 16 8 4 2 1 
    10  0    0  0  0 1 0 1 0
    1   0    0  0  0 0 0 0 1 
    |   0    0  0  0 1 0 1 1   the output is coming 11.

    12  0    0  0  0 1 1 0 0
    1   0    0  0  0 0 0 0 1
    |   0    0  0  0 1 1 0 1  the output is coming 12 

    0   0    0   0 0 0 0 0 0
    1   0    0   0 0 0 0 0 1 
    |    0    0   0 0 0 0 0 1  the output is coming 1 

    that means doing even number | 1 is number + 1

 ** doing for odd number 

        128 64 32 16 8 4 2 1 
    9    0  0  0  0  1 0 0 1
    1    0  0  0  0  0 0 0 1 
    |    0  0  0  0  1 0 0 1   the output is coming number or 9.
    
    25   0  0  0  1  1 0  0 1
    1    0  0  0  0  0 0  0 0
    |    0  0  0  1  1 0  0 1    the output is coming 25

    1    0  0  0  0  0 0  0 1
    1    0  0  0  0  0 0  0 1 
    |    0  0  0  0  0 0  0 1   so the output is coming 1 that means number | 1 == number means it is odd number..
 */

// method 5 => using bitwise OR (|) operator.
// checking odd even using the bitwise OR (|) erator ..
/*
#include <stdio.h>
int main(){
    int number;
    printf("enter the value of the number \n");
    scanf("%d", &number);
    if((number | 1) == number + 1){
        printf("the %d number is a even number \n", number);
    }else if ((number | 1) == number){
        printf("the %d number is a odd number \n", number);
    }
    return 0;
}
*/

// alternative approach using bitwise or operator ..
/*
#include <stdio.h>
int main (){
    int number;
    printf("enter the value of the number \n");
    scanf("%d", &number);
    if((number | 1)>number){
        printf("the %d number is a even number \n", number);
    }else if ((number | 1) == number){
        printf("the %d number is odd number \n", number);
    }
    return 0;
}
*/


// checking ^ xor bitwise operator .
/**
 *      128 64 32 16 8 4 2 1 
 *  5    0   0  0  0 0 1 0 1
 *  1    0   0  0  0 0 0 0 1 
 *  ^    0   0  0  0 0 1 0 0   so the output is number-1 or 4 for odd number
 *  
 *  11   0   0  0  0 1 0 1 1
 *  1    0   0  0  0 0 0 0 1 
 *  ^    0   0  0  0 1 0 1 0   so the output is number -1 or 10 for odd number ..

 *  1    0   0  0  0 0 0 0 1
    1    0   0  0  0 0 0 0 1 
    ^    0   0  0  0 0 0 0 0   so the output is number - 1 or 1 ^ 1 is 0 which satisfy the condition of number ^ 1 == number -1.


 ** for even number ..
        128 64 32 16 8 4 2 1 
    12   0   0  0  0 1 1 0 0 
    1    0   0  0  0 0 0 0 1 
    ^    0   0  0  0 1 1 0 1      so the output is number + 1 or 13 for even number 

    22  0    0  0  1 0 1 1 0
    1   0    0  0  0 0 0 0 1
    ^   0    0  0  1 0 1 1 1   so the output is the number + 1 or 23 for even number..

    0   0    0  0  0 0 0 0 0 
    1   0    0  0  0 0 0 0 1
    ^   0    0  0  0 0 0 0 1  so the output is number + 1 which 0+1 == number +1.
 */


// method 6 => using bitwise XOR (^) operator 
// checking the odd even number using the ^ xor bitwise operator 
/*
#include <stdio.h>
int main (){
    int number;
    printf("enter the value of the number \n");
    scanf("%d", &number);
    if((number ^1) == number + 1){
        printf("the %d number is a even number \n", number);
    }else if ((number ^ 1) == number - 1){
        printf("the %d number is a odd number \n", number);
    }
    return 0;
}
*/

// checking left and right shift operator to check bitwise operator ..
/**
 *      128 64 32 16 8 4 2 1 
 *  0   0   0  0   0 0 0 0 0
 *  1 >> 0  0  0   0 0 0 0 0    0  so for doing 0 >> 1 will be 0 
 * 
 *  4   0   0  0  0  0 1 0 0 
 *  1>> 0   0  0  0  0 0 1 0   4 >> 1 gives 2 .
 *  
 *  6   0   0  0  0  0 1 1 0
 *  >> 1 0  0  0  0  0 0 1 1  6 >> 1 gives 3 
 *
 ** odd 
    5  0   0  0   0  0 1 0 1
    >>1 0  0  0   0  0 0 1 0   so it gives 4 
 */

// using right shift only or left shift only we can not find the weather a number is odd or even..

// using the right and left shift operator both..

// method 7 => using left and right shift operator (>>) (<<).
/*
#include <stdio.h>
int main(){
    int number;
    printf("enter the value of the number \n");
    scanf("%d", &number);
    // checking the even number..
    if(((number>>1)<<1)==number){
        printf("the %d number is the even number \n", number);
    }else if (((number >> 1)<<1)==number-1){
        printf("the %d number is a odd number \n", number);
    }
    return 0;
}
*/
