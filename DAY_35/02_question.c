// Q 2 => write a program to calculte the average of numbers stored in an array of size 10 take array values from the user..

#include <stdio.h>
void inputArrayData(int *arr,int size);
void displayArrayData(int *arr,int size);
float averageOfArray(int *arr,int size);
int main (){
    int size;
    printf("enter the value of size \n");
    scanf("%d",&size);
    int arr[size];
    inputArrayData(arr,size);
    displayArrayData(arr,size);
    float avg=averageOfArray(arr,size);
    printf("\nthe average of %d number of array is %0.2f\n",size,avg);
    return 0;
}
void inputArrayData(int *arr,int size){
    printf("enter the data in the %d size array\n",size);
    for(int i=0; i<size; i++){
        // scanf("%d",&arr[i]);
        // scanf("%d",&*arr+i);
        scanf("%d",arr+i);
    }
}
void displayArrayData(int *arr, int size){
    printf("the %d data of array is : \n",size);
    for(int i=0; i<size; i++){
        // printf("%d ",arr[i]);
        printf("%d ",*arr+i);
    }
}
float averageOfArray(int *arr,int size){
    float avg=0;
    int sum=0;
    for(int i=0; i<size; i++){
        sum=sum+*arr+i;
    }
    printf("the sum of %d array elements is %d\n",size,sum);
    // avg=sum/size;
    float size1=size+0.0;
    avg=sum/size1;
    printf("avg is %0.2f \n",avg);
    // the reason why we are getting 5.00 instead of 5.5 is because avg is a float data type which means it can store the point number .. but the result of int / int in the c langauge is always a int type so to get correct ans we need to make either one of the operand of / divid operator to float.
    return avg;
}
