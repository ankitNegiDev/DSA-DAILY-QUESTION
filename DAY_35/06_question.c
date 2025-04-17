// Q 6 => write a program to sort elements of an array of size 10 take array values fro mthe user..

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
void inputArrayData(int *arr, int size);
void displayArrayData(int *arr, int size);
void sortArrayDataAscending(int *arr, int size);
void sortArrayDataDescending(int *arr, int size);
bool isSortedAscending(int *arr, int size);
bool isSortedDescending(int *arr,int size);
int main()
{
    int size;
    printf("enter the size of array \n");
    scanf("%d", &size);
    int arr[size];
    inputArrayData(arr, size);
    displayArrayData(arr, size);
    sortArrayDataAscending(arr,size);
    printf("\nArray data after sorting in ascending order\n");
    displayArrayData(arr,size);
    sortArrayDataDescending(arr,size);
    printf("\nArray data after sorting in descening order\n");
    displayArrayData(arr,size);
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

bool isSortedAscending(int *arr, int size){
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            return 0; // not sorted in ascending order... because for sorted int the ascending order should be arr[i]<arr[i+1] assuming i stat with 0 and end at length-2.
        }
    }
    return 1;
}
bool isSortedDescending(int *arr, int size){
    for(int i=1; i<size; i++){
        if(arr[i]>arr[i-1]){
            return 0; // not sorted in descending order because sorted in the desceding order must be arr[i]<arr[i-1] assuming i is started with 1..
        }
    }
    return 1;
}

void sortArrayDataAscending(int *arr, int size){
    // using the brute force. by finding the min ..
    if(isSortedAscending(arr,size)){
        printf("the array is already sorted in ascening\n");
        return ;
    }else{
        for (int i = 0; i < size / 2; i++)
        {
            int min = INT_MAX;
            int minIndex = -1;
            for (int j = i; j < size; j++)
            {
                if (min > arr[j])
                {
                    min = arr[j];
                    minIndex = j;
                }
            }
            // now do swapping ...
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
    

}
// 10 9 8 7 6 5 4 3 2 1 // initial 
//  1 9 8 7 6 5 4 3 2 10 // i=0
//  1 2 8 7 6 5 4 3 9 10 // i = 1
//  1 2 3 7 6 5 4 8 9 10 // i = 2
//  1 2 3 4 6 5 7 8 9 10 // i = 3
//  1 2 3 4 5 6 7 8 9  10  // i=4
// in worst case it will take size/2-1 means arraylenght/2-1 time to sort the array compolety so why we are running loop to size.. it should be size/2-1 or i<size/2 or i<=size/2-1;
void sortArrayDataDescending(int *arr, int size){
    if(isSortedDescending(arr,size)){
        printf("\nthe array is already sorted in descending order\n");
        return ;
    }else{
        for (int i = 0; i < size / 2; i++)
        {
            int max = INT_MIN;
            int maxIndex = -1;
            for (int j = i; j < size; j++)
            {
                if (max < arr[j])
                {
                    max = arr[j];
                    maxIndex = j;
                }
            }
            // swapping..
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }

}

// 5 4 3 2 1
// 1 4 3 2 5
// 1 2 3 4 5

// 6 5 4 3 2 1
// 1 5 4 3 2 6
// 1 2 4 3 5 6
// 1 2 3 4 5 6
// in worst case it will take size/2-1 means arraylenght/2 -1 time to sort the array compolety so why we are running loop to size.. it should be size/2; or i<size/2 or i<=size/2-1

// what if array is already sorted..

// 1,2,3,4,5
// 