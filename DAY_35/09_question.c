// Q 10 => write a program in c to copy the elemnts of one array into another array take array values from the user..
// Q 6 => write a program to sort elements of an array of size 10 take array values fro mthe user..

// Q 5 => write a program to find the smallest number stored in an array of size 10 takes array values fro mthe suer..

// Q 4 => write a program to find the greatest number stored in the an array of size 10 take array values from the user..
#include <stdio.h>
void inputArrayData(int *arr, int size);
void displayArrayData(int *arr, int size);
void copyData(int *arr,int *arr2, int size);
int main()
{
    int size;
    printf("enter the size of array \n");
    scanf("%d", &size);
    int arr[size];
    int arr2[size];
    inputArrayData(arr, size);
    displayArrayData(arr, size);
    copyData(arr,arr2,size);
    printf("\n--------- data of arr2 is -----------\n");
    displayArrayData(arr2,size);
    return 0;
}
void inputArrayData(int *arr, int size)
{
    printf("enter the data in the %d size array \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void displayArrayData(int *arr, int size)
{
    printf("the data of %d size array is \n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void copyData(int *arr, int *arr2, int size){
    // copying data of arr to arr2.
    for(int i=0; i<size; i++){
        arr2[i]=arr[i];
    }
}