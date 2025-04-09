// 10. Write a program to print all Armstrong numbers under 1000.
#include <stdio.h>
int main()
{
    printf("the aramstrong number from 0 to 1000 number are : \n\n");
    for (int i = 0; i <= 1000000; i++)
    {
        int tempNumber = i;
        int count = 0;
        while (tempNumber)
        {
            int digit = tempNumber % 10;
            // printf("the digit is %d \n", digit);
            tempNumber = tempNumber / 10;
            // printf("the tempnumber is %d \n", tempNumber);
            count++;
        }
        // printf("\n\n");
        // printf("the value of count is %d \n", count);
        int armstrongNumberCheck = i;
        int sum = 0;
        while (armstrongNumberCheck)
        {
            int digit = armstrongNumberCheck % 10;
            int digitSum = 1;
            int j = count;
            while (j)
            {
                digitSum = digitSum * digit;
                j--;
            }
            // printf("\n\n the value of digitsum is %d\n", digitSum);
            sum = sum + digitSum;
            // printf("the value of sum is %d \n", sum);
            armstrongNumberCheck = armstrongNumberCheck / 10;
        }
        if (i == sum)
        {
            printf("%d ", i);
        }
    }
}