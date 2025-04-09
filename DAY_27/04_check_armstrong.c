// 9. Write a program to check whether a given number is an Armstrong number or not.




// method 1  only for three digit number.....
// Armstrong number is a number that is equal to the sum of cubes of its digits. For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.

/*
#include<stdio.h>
int main (){
    int number;
    printf("enter the value of number\n");
    scanf("%d", &number);
    for (int i = 0; i <= number; i++){
        int num = i;
        int sum = 0;
        while(num){
            int digit = num % 10;
            num = num / 10;
            sum = sum + digit * digit * digit;
        }
        if(i==sum){
            printf("%d ", i);
        }
    }
}*/


// So an Armstrong number is a number whose each digit is multipled as many times as the number of digits of that number and then added to get the number.


/*
#include<stdio.h>
int main(){
    int number;
    printf("etner the value of number\n");
    scanf("%d", &number);
    printf("the aramstrong number from 0 to %d number are : \n\n", number);
    int preservedNumber = number;
    for (int i = 0; i <= number; i++){
        int tempNumber = i;
        int count = 0;
        while(tempNumber){
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
        while(armstrongNumberCheck){
            int digit = armstrongNumberCheck % 10;
            int digitSum = 1;
            int j = count;
            while(j){
                digitSum = digitSum * digit;
                j--;
            }
            // printf("\n\n the value of digitsum is %d\n", digitSum);
            sum = sum + digitSum;
            // printf("the value of sum is %d \n", sum);
            armstrongNumberCheck = armstrongNumberCheck / 10;
        }
        if(i==sum){
            printf("%d ", i);
        }
    }
}
*/

/*
#include <stdio.h>

int main() {
    int n;
    printf("Enter the upper limit (n): ");
    scanf("%d", &n);

    printf("Armstrong numbers from 0 to %d are:\n", n);

    // Loop through numbers from 0 to n
    for (int i = 0; i <= n; i++) {
        int tempNumber = i, sum = 0, count = 0;

        // Count the number of digits
        int digitCount = tempNumber;
        while (digitCount != 0) {
            digitCount /= 10;
            count++;
        }

        // Special case for 0 (since it has 1 digit)
        if (count == 0) {
            count = 1;
        }

        // Calculate Armstrong sum manually
        tempNumber = i;
        while (tempNumber != 0) {
            int digit = tempNumber % 10;
            int digitPower = 1;

            // Manually calculate digit^count
            for (int j = 0; j < count; j++) {
                digitPower *= digit;
            }

            sum += digitPower;
            tempNumber /= 10;
        }

        // Check if it's an Armstrong number
        if (sum == i) {
            printf("%d\n", i);
        }
    }

    return 0;
}*/


// checking weather a given number is aramstrong number or not
#include <stdio.h>
int main()
{
    int number;
    printf("etner the value of number\n");
    scanf("%d", &number);
    // printf("the aramstrong number from 0 to %d number are : \n\n", number);
    int preservedNumber = number;
    for (int i = number; i <= number; i++)
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
            printf("%d number is a aramstrong number ", i);
        }else{
            printf("%d number is not a aramstrong number ", i);
        }
    }
}