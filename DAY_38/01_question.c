// Write a function to swap two elements of given array with specified indices.

#include <stdio.h>

void swapElements(int arr[], int index1, int index2);

int main()
{
    int arr[100], size, index1, index2;

    // Taking array input
    printf("Enter the size of array: \n");
    scanf("%d", &size);

    printf("Enter %d elements: \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter two indices to swap: \n");
    scanf("%d %d", &index1, &index2);

    // bound checking upper and lower so that given index are in range if not then error will come .
    if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size)
    {
        swapElements(arr, index1, index2);
        printf("Array after swapping: \n");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Invalid indices!\n");
    }

    return 0;
}

// Function to swap two elements
void swapElements(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
/*
Enter the size of array:
10
Enter 10 elements:
10
20
30 40 50 60 70 80 90 100
Enter two indices to swap:
0
9
Array after swapping:
100 20 30 40 50 60 70 80 90 10
*/
