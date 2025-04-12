// Q 1 => write a function to calculate the area of circel.

// area of circle is : pi*r*r

#include <stdio.h>
#define PI 3.14159
// function decleration
float areaOfCircle(float radius);

int main (){
    float radius;
    printf("enter the value of radius \n");
    scanf("%f",&radius);

    float area=areaOfCircle(radius);
    printf("The area of circle is : %f\n",area);
    return 0;
}

// function is takes something and return something 
float areaOfCircle(float radius){
    return PI*radius*radius;
}

/*
output => 
    enter the value of radius
    2
    The area of circle is : 12.566360
*/