// 8. Write a program to check whether the roots of a given quadratic equation are real &distinct, real &equal, or imaginary roots.
#include <stdio.h>
#include <math.h>
int main(){
    double a, b, c;
    double discriminant, root1, root2, realPart, imagPart;
    printf("enter the value of the cofficient\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    discriminant = b * b - 4 * a * c;

    // checking the nature of the roots
    // (1) if roots are distinct and real
    if(discriminant>0){
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("the roots are real and distinct\n");
        printf("root1 = %lf\n", root1);
        printf("root2 = %lf\n", root2);
    }else if (discriminant==0){
        // real and equal roots
        root1 = -b / (2 * a);
        printf("The roots are real and equal.\n");
        printf("Root 1 = Root 2 = %.2lf\n", root1);
    }else{
        // imaganiry roots
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("The roots are imaginary.\n");
        printf("Root 1 = %.2lf + %.2lfi\n", realPart, imagPart);
        printf("Root 2 = %.2lf - %.2lfi\n", realPart, imagPart);
    }
    return 0;
}