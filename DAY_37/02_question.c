// Write a function to find the first occurrence of adjacent duplicate values in the array.
// Function has to return the value of the element.

// adjacent menas . bagal wala.. so if a is at 0 index and again a is at 1 index then we have to return a of 0 index... (since a at 0 index is first occurance)
#include <stdio.h>

    int
    findFirstAdjacentDuplicate(int arr[], int size);

int main()
{
    int arr[] = {5, 3, 8, 8, 2, 4, 4, 4, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = findFirstAdjacentDuplicate(arr, size);

    if (result != -1)
    {
        printf("First adjacent duplicate value: %d\n", result);
    }
    else
    {
        printf("No adjacent duplicate values found.\n");
    }

    return 0;
}

int findFirstAdjacentDuplicate(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i]; 
        }
    }
    return -1;
}