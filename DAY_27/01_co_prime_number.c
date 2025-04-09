// 5. Write a program to check whether two given numbers are co - prime numbers or not.
/**
 * Co-prime numbers can be identified easily with the help of some properties that are explained below:

 * The Highest Common Factor (HCF) of two coprime numbers is always 1. For example, 5 and 9 are coprime numbers, there, HCF (5, 9) = 1.
 * The Least Common Multiple (LCM) of two co-primes is always their product. For example, 5 and 9 are co-prime numbers. Hence, LCM (5, 9) = 45.
 * 1 forms a co-prime number pair with every number.
 * Two even numbers cannot be co-prime numbers as they always have 2 as the common factor.
 * The sum of two co-prime numbers is always co-prime with their product. For example, 5 and 9 are co-prime numbers. Here, 5 + 9 = 14 is co-prime with 5 × 9 = 45.
 * Two prime numbers are always co-prime. They have only 1 as their common factor. Consider 29 and 31. 29 has 2 prime factors, 1 and 29 only. 31 has 2 prime factors, 1 and 31 only. 29 and 31 are prime numbers. They have only one common factor 1. Thus they are co-prime. We can check any two prime numbers and get them as co-prime. For example, 2 and 3, 5 and 7, 11 and 13, and so on.
 * All pairs of two consecutive numbers are co-prime numbers. Any two consecutive numbers have 1 as their common factor
 */

// finding the two number are co-prime or not using the hcf method.
/*
#include <stdio.h>
int main()
{
    int num1, num2, hcf = 1, originalNum1, originalNum2;
    printf("enter the value of num1 and num2\n");
    scanf("%d %d", &num1, &num2);
    int greaterNumber = num1 > num2 ? num1 : num2;
    originalNum1 = num1;
    originalNum2 = num2;
    for (int i = 2; (num1 > 1 && num2 > 1) && (i <= greaterNumber);)
    {
        if ((num1 % i == 0) && (num2 % i == 0))
        {
            hcf = hcf * i;
            num1 = num1 / i;
            num2 = num2 / i;
        }
        else
        {
            i++;
        }
    }
    printf("the hcf of %d and %d number is %d\n", originalNum1, originalNum2, hcf);
    if(hcf==1){
        printf("the %d and %d are the co-prime number\n", originalNum1, originalNum2);
    }else{
        printf("the %d and %d are not the co-prime number\n", originalNum1, originalNum2);
    }
    return 0;
}
*/

// optimized ...
/*
#include <stdio.h>
int main()
{
    int num1, num2, reminder, greaterNum, samllerNum,hcf;
    printf("enter the vlaue of num1 and num2\n");
    scanf("%d %d", &num1, &num2);
    if (num1 >= num2)
    {
        greaterNum = num1;
        samllerNum = num2;
    }
    else
    {
        greaterNum = num2;
        samllerNum = num1;
    }
    while (greaterNum % samllerNum != 0)
    {
        reminder = greaterNum % samllerNum;
        greaterNum = samllerNum;
        samllerNum = reminder;
    }
    hcf = samllerNum;
    printf("the hcf of %d and %d number is %d\n", num1, num2, hcf);
    if(hcf==1){
        printf("the %d and %d are the co-prime number\n", num1, num2, hcf);
    }else{
        printf("the %d and %d  are not the co-prime number\n", num2, num2, hcf);
    }
    return 0;
}
*/

// using lcm to find the co-prime number
#include <stdio.h>
int main()
{
    int num1, num2;
    printf("enter the value of num1 and num2\n");
    scanf("%d %d", &num1, &num2);
    int preservedNum1 = num1, preservedNum2 = num2, i = 2, lcm = 1;
    while (num1 > 1 || num2 > 1)
    {
        if (num1 % i == 0 || num2 % i == 0)
        {
            lcm = lcm * i;
            if (num1 % i == 0)
            {
                num1 = num1 / i;
            }
            if (num2 % i == 0)
            {
                num2 = num2 / i;
            }
        }
        else
        {
            i++;
        }
    }
    printf("the lcm of %d and %d number is %d\n", preservedNum1, preservedNum2, lcm);
    if(lcm==preservedNum1*preservedNum2){
        printf("the %d and %d number are the co-prime number\n", preservedNum1, preservedNum2);
    }else{
        printf("the %d and %d number are not the co-prime number\n", preservedNum1, preservedNum2);
    }
    return 0;
}