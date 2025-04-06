// 4. Write a program to calculate the HCF(Highest Common Factor) of two numbers.

// hcf by listing method.
/*
#include <stdio.h>
int main()
{
    int num1, num2;
    printf("enter the value of num1 and num2\n");
    scanf("%d %d", &num1, &num2);
    int hcf = 0;
    // we can find the factor of num1
    printf("\n\n");
    for (int i = 1; i <= num1; i++)
    {
        if (num1 % i == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n\n");
    // we can find the factor of num2
    for (int i = 1; i <= num2; i++)
    {
        if (num2 % i == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n\n");
    for (int i = 1; i <= num1 && i <= num2; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            hcf = i;
        }
    }
    printf("the hcf of %d and %d number is %d\n", num1, num2, hcf);
    return 0;
}
*/

// using the HCF by Prime Factorization
/*
#include <stdio.h>
int main (){
    int num1, num2, hcf = 1, originalNum1, originalNum2;
    printf("enter the value of num1 and num2\n");
    scanf("%d %d", &num1, &num2);
    int greaterNumber = num1 > num2 ? num1 : num2;
    originalNum1 = num1;
    originalNum2 = num2;
    for (int i = 2; (i <= greaterNumber) && (num1>1 &&num2>1); ){
        // printf("%d num1 and %d num2\n", num1, num2);
        if((num1%i==0) && (num2%i==0)){
            // printf("%d i \n", i);
            hcf = hcf * i;
            num1 = num1 / i;
            num2 = num2 / i;

        }else if ((num1%i==0) || (num2%i==0)){
            if(num1%i==0){
                num1 = num1 / i;
            }else{
                num2 = num2 / i;
            }
        }
        if(num1%i!=0 && num2%i!=0){
            i++;
        }

    }
    // printf("the vlaue of num1 is %d and the vlaue of num2 is %d \n", num1, num2);
    printf("the hcf of %d and %d number is %d\n", originalNum1, originalNum2, hcf);
}
*/

// updated version of this code where we only focus on the prime number that is of factor of both number. in above code we explicitly divide the number when i is not factor of both number...
/*
#include <stdio.h>
int main (){
    int num1, num2, hcf = 1, originalNum1, originalNum2;
    printf("enter the value of num1 and num2\n");
    scanf("%d %d", &num1, &num2);
    int greaterNumber = num1 > num2 ? num1 : num2;
    originalNum1 = num1;
    originalNum2 = num2;
    for (int i = 2; (num1 > 1 && num2 > 1) && (i <=greaterNumber);){
        if ((num1 % i == 0) && (num2 % i == 0)){
            hcf = hcf * i;
            num1 = num1 / i;
            num2 = num2 / i;
        }else
        {
            i++;
        }
    }
    printf("the hcf of %d and %d number is %d\n", originalNum1, originalNum2, hcf);
}
*/

// modifying the avobe solution here we will go from highest factor to lower and first highest factor that is factor of both then we will assign that to hcf and break the loop. and if not then loop will run until smaller no is greater then 1 ... the reason we take smaller no is because just think hcf of any two no will be less then the smaller number.. eg hcf of 8 and 12 will be always less then 8.
#include <stdio.h>
int main()
{
    int num1, num2, hcf;
    printf("etner two number num1, num2\n");
    scanf("%d %d", &num1, &num2);
    int smallerNum = num1 < num2 ? num1 : num2;
    for (int i = smallerNum; i >= 1; i--)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            hcf = i;
            break;
        }
        hcf = i;
    }
    printf("the hcf is %d ", hcf);
}

// HCF by Division Method (euclid theoram)
/*
#include <stdio.h>
int main (){
    int num1, num2, reminder,greaterNum,samllerNum;
    printf("enter the vlaue of num1 and num2\n");
    scanf("%d %d", &num1, &num2);
    if(num1>=num2){
        greaterNum = num1;
        samllerNum = num2;
    }else{
        greaterNum = num2;
        samllerNum = num1;
    }

    for (int i = 0; greaterNum % samllerNum != 0; i++){
        reminder = greaterNum % samllerNum;
        greaterNum = samllerNum;
        samllerNum = reminder;
    }
    printf("the hcf of %d and %d number is %d\n", num1, num2, samllerNum);
    return 0;
}
*/
// modifying the for loop with while ...
/*
#include <stdio.h>
int main()
{
    int num1, num2, reminder, greaterNum, samllerNum;
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
    while(greaterNum%samllerNum!=0){
        reminder = greaterNum % samllerNum;
        greaterNum = samllerNum;
        samllerNum = reminder;
    }
    printf("the hcf of %d and %d number is %d\n", num1, num2, samllerNum);
    return 0;
}
*/
