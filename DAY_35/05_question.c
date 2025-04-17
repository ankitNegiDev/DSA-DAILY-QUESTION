// Q 5 => write a program to find the smallest number stored in an array of size 10 takes array values fro mthe suer..

#include <stdio.h>
#include <limits.h>
void inputArrayData(int *arr, int size);
void displayArrayData(int *arr, int size);
int smallestNumber(int *arr, int size); // max num
int main()
{
    int size;
    printf("enter the size of array \n");
    scanf("%d", &size);
    int arr[size];
    inputArrayData(arr, size);
    displayArrayData(arr, size);
    int min = smallestNumber(arr, size);
    printf("\nin the %d array elements smallest number is %d\n", size, min);
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
int smallestNumber(int *arr, int size)
{
    int min = INT_MAX; // Smallest possible int
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}
