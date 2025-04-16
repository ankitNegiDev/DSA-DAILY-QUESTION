// Q 7 => write a recursive function to calculate hcf of two numbers..

#include <stdio.h>

int hcf(int a, int b);

int main()
{
    int num1, num2;
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    int result = hcf(num1, num2);
    printf("HCF of %d and %d is: %d\n", num1, num2, result);

    return 0;
}

int hcf(int a, int b)
{
    if (b == 0)
        return a;
    return hcf(b, a % b);
}

// hcf(4, 6) or hcf(a,b)
/*
(1) function call (a=4, b=6)
b != 0  so ->  call hcf(6, 4 % 6)  -> 4 % 6 = 4, so -> hcf(6, 4)

(2) function call (a=6, b=4)
hcf(6, 4)
b != 0 so -->  call hcf(4, 6 % 4) -> 6 % 4 = 2, so -> hcf(4, 2)

(3) function call (a= 4 , b=2)
hcf(4, 2)
b != 0 so -> call hcf(2, 4 % 2) -> 4 % 2 = 0, so -> hcf(2, 0)

(4) function call.. (a=2 , b=0)
hcf(2, 0) 
now b == 0  return a = 2
Final Answer will be  2
*/

// do it on rev-time....