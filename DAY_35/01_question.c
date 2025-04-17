// Q 1 => write a program to calculate the sum of numbers stored in an array of size 10 . takes array values from the user.

#include <stdio.h>
void inputData(int *arr,int size);
void displayData(int *arr,int size);
int sumOfArray(int *arr,int size);
int main (){
    int size;
    printf("enter the size of the array or data u wana store in the array\n");
    scanf("%d",&size);
    int arr[size];
    inputData(arr,size);
    displayData(arr,size);
    int sum=sumOfArray(arr,size);
    printf("\nthe sum of array elements is : %d\n",sum);
    return 0;
}
void inputData(int *arr,int size){
    printf("\nenter %d data in the array\n",size);
    for(int i=0; i<size; i++){
        scanf("%d",arr+i);
        // scanf("%d",&*arr+i);
        // scanf("%d",&arr[i]);
    }
}
void displayData(int *arr,int size){
    printf("\nthe %d data of the array is : \n",size);
    for(int i=0; i<size; i++){
        printf("%d ",*arr+i);
        // printf("%d ",arr[i]);
    }
}
int sumOfArray(int *arr,int size){
    int sum=0;
    for(int i=0; i<size; i++){
        sum=sum+*(arr+i);
    }
    return sum;
}