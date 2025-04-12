// Q 3 => write a function to check weather a given number is even or odd , return 1 if number is even else return 0.

// we can check even odd using following methods ..
/**
 * (1) using module %
 * (2) using * and / operator
 * (3) using - operaotr
 * (4) using + operator
    * approach is simple take a extra variable and initialize it with 0 and incriment 2 in it until it is less then original number or absulte number once it is greater then do difference with original if result is 0 that emans it is even else it is odd. ex -> 12 and mynum is 0 so incrime my num by 2 until myNum is < 12 so on last step myNum will be 14 so 14-12 or 12-14 (absolute diff) is 0 so it is evn and same for odd there we get 1.

 * (5) using bitwise & (AND) operator
 * (6) using bitwise | (OR) operator
 * (7) using bitwise ^ (XOR) operator
 * (8) using left and right shift operator both. using individual left << and right >> shift operator we can find even and odd number.
 */

//  so for all these we will create function that takes somethign and return something ..

#include <stdio.h>
#include <stdbool.h>
bool isEvenOddUsingModulo(int num);
bool isEvenOddUsingMultiplyAndDivision(int num);
bool isEvenOddUsingSubtractionApproach(int num);
bool isEvenOddUsingAdditionApproach(int num);
bool isEvenOddUsingBitwiseANDOperator(int num);
bool isEvenOddUsingBitwiseOROperator(int num);
bool isEvenOddUsingBitwiseXOROperator(int num);
bool isEvenOddUsingBitwiseLeftAndRightShiftOperator(int num);
char * printTrueOrFalse(bool para){
    if(para==1){
        return "True";
    }else{
        return "False";
    }
}
int main (){
    int num;
    printf("enter the value of number\n");
    scanf("%d",&num);

    printf("(1) Using module operator\n\n");
    int result=isEvenOddUsingModulo(num);
    printf("    the number %d is Even Number : %s\n",num, printTrueOrFalse(result));

    printf("\n\n(2) Using multiply and division operator\n\n");
    result=isEvenOddUsingMultiplyAndDivision(num);
    printf("    the number %d is Even Number : %s\n",num,printTrueOrFalse(result));

    printf("\n\n(3) Using Subtraction operator\n\n");
    result=isEvenOddUsingSubtractionApproach(num);
    printf("    the number %d is Even Number : %s\n",num,printTrueOrFalse(result));

    printf("\n\n(4) Using Addition operator\n\n");
    result=isEvenOddUsingAdditionApproach(num);
    printf("    the number %d is Even Number : %s\n",num,printTrueOrFalse(result));

    printf("\n\n(5) Using bitwise AND (&) operator\n\n");
    result = isEvenOddUsingBitwiseANDOperator(num);
    printf("    the number %d is Even Number : %s\n", num, printTrueOrFalse(result));

    printf("\n\n(6) Using bitwise OR (|) operator\n\n");
    result = isEvenOddUsingBitwiseOROperator(num);
    printf("    the number %d is Even Number : %s\n", num, printTrueOrFalse(result));

    printf("\n\n(7) Using bitwise XOR (^) operator\n\n");
    result = isEvenOddUsingBitwiseXOROperator(num);
    printf("    the number %d is Even Number : %s\n", num, printTrueOrFalse(result));

    printf("\n\n(8) Using bitwise Left and right Shift (<< >>) operator\n\n");
    result = isEvenOddUsingBitwiseLeftAndRightShiftOperator(num);
    printf("    the number %d is Even Number : %s\n", num, printTrueOrFalse(result));
    return 0;
}

bool isEvenOddUsingModulo(int num){
    if(num%2==0){
        return 1;
    }else{
        return 0;
    }
}

bool isEvenOddUsingMultiplyAndDivision(int num){
    if((num/2)*2==num){
        return 1;
    }else if ((num/2)*2 !=num){
        return 0;
    }
}

bool isEvenOddUsingSubtractionApproach(int num){
    int absNumber=num < 0 ? -num : num;
    while(absNumber>=2){
        absNumber=absNumber-2;
    }
    if(absNumber==0){
        // even
        return 1;
    }else if(absNumber==1){
        // odd
        return 0;
    }
}

bool isEvenOddUsingAdditionApproach(int num){
    int absNum= num<0 ? -num : num;
    int calculatingSum=0;
    while(calculatingSum<absNum){
        calculatingSum+=2;
    }
    if(calculatingSum==absNum){
        // even
        return 1;
    }else if(calculatingSum!=absNum){
        //odd
        return 0;
    }
}

// All bitwise operators (&, |, ^, <<, >>) have lower precedence than comparison (==, !=, <, >, etc.) in C

bool isEvenOddUsingBitwiseANDOperator(int num){
    if((num&1)==0){
        // even
        return 1;
    }else if((num&1)!=0){
        // odd
        return 0;
    }
}

bool isEvenOddUsingBitwiseOROperator(int num){
    // if((num|1)>num) // even same..
    if((num | 1)==num+1){
        // even
        return 1;
    }else if((num | 1) == num){
        // odd
        return 0;
    }
}

bool isEvenOddUsingBitwiseXOROperator(int num){
    if((num ^ 1) == num + 1){
        // evn
        return 1;
    }else if((num ^ 1) == num -1){
        return 0;
    }
}

bool isEvenOddUsingBitwiseLeftAndRightShiftOperator(int num){
    if(((num >> 1) <<1 ) == num){
        // even
        return 1;
    }else if (((num >> 1) << 1) == num -1 ){
        // odd 
        return 0;
    }
}