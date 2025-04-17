// Q 4 => write a program to find the greatest number stored in the an array of size 10 take array values from the user..

#include <stdio.h>
#include <limits.h>
void inputArrayData(int *arr, int size);
void displayArrayData(int *arr, int size);
int greatestNumber(int *arr, int size); // max num
int main (){
    int size;
    printf("enter the size of array \n");
    scanf("%d",&size);
    int arr[size];
    inputArrayData(arr,size);
    displayArrayData(arr,size);
    int max=greatestNumber(arr,size);
    printf("\nin the %d array elements greatest number is %d\n",size,max);
    return 0;
}
void inputArrayData(int *arr, int size){
    printf("enter the data in the %d size array \n",size);
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
}
void displayArrayData(int *arr, int size){
    printf("the data of %d size array is \n",size);
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
}
int greatestNumber(int *arr, int size){
    int max = INT_MIN; // Smallest possible int
    for(int i=0; i<size; i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
