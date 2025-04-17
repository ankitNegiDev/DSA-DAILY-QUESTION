// Q 8 => write a program to find the second smallest number in the array take values from the user...

#include <stdio.h>
#include <limits.h>
// Q 7 => write a program to find second largest elment in the array take array values from the user..

#include <stdio.h>
#include <limits.h>
int secondSmallestInArray(int *arr, int size);
int main()
{
    int size;
    printf("enter the value of size\n");
    scanf("%d", &size);
    int arr[size];
    printf("enter the data in the array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("the data of the array\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    int secondSmallest = secondSmallestInArray(arr, size);
    printf("the second smallest element in the array is %d\n", secondSmallest);
    return 0;
}
int secondSmallestInArray(int *arr, int size)
{
    int min = INT_MAX;
    int secondMin = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            // update to both max and second max..
            secondMin = min;
            min = arr[i];
        }
        else if (min < arr[i] && secondMin > arr[i])
        {
            // there can be a case where min is smaller then the current val but secondmin is greater.. so we need to update this also.
            secondMin = arr[i];
        }
    }
    // edge case for this when same elements..
    /*
    enter the value of size
    3
    enter the data in the array
    3
    3
    3
    the data of the array
    3 3 3
    the min number is 3
    the second smallest element in the array is -2147483648
    */
    printf("\nthe min number is %d\n", min);
    if (secondMin == INT_MAX)
    {
        printf("No second minimum found all elements are same.\n");
        return -1;
    }
    return secondMin;
}
