// Q 2 => write a function to calculate simple intrest

// simple intrest => si = principle amount * rate of intrest * time period /100

#include <stdio.h>
float simpleIntrest(float principleAmount,float rateOfIntrest,float timePeriod);

int main (){
    float si,p,r,t;
    printf("enter the value of principle amount , rate of intreset , and time period \n");
    scanf("%f %f %f",&p,&r,&t);

    si=simpleIntrest(p,r,t);
    printf("the simple intrest is : %f\n",si);
    return 0;
}

// the function is of takes something and return some thing 
float simpleIntrest(float principleAmount,float rateOfIntreset,float timePeriod){
    return (principleAmount*rateOfIntreset*timePeriod)/100;
}
/*
If we take a loan of ₹1200 at 14% interest per year for 2 years then interest is calculated using the simple interest method

Interest after 2 years = ₹336

Total amount to pay back = ₹1200 (principal) + ₹336 (interest) = ₹1536
*/
/*
output =>

    enter the value of principle amount , rate of intreset , and time period
    1200
    14
    2
    the simple intrest is : 336.000000
*/