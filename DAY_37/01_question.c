// Write a function to rotate an array by n position in d direction. The d is an indicative value for left or right.
// (For example, if array of size 5 is[32, 29, 40, 12, 70]; n is 2 and d is left, then the resulting array after left rotation 2 times is[40, 12, 70, 32, 29])

#include <stdio.h>
void rotateLeft(int arr[], int size, int n);
void rotateRight(int arr[], int size, int n);
void printArray(int arr[], int size);

int main()
{
    int arr[] = {32, 29, 40, 12, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 2;
    char direction;

    printf("Enter direction (L for left / R for right): ");
    scanf(" %c", &direction);

    if (direction == 'L' || direction == 'l')
    {
        rotateLeft(arr, size, n);
    }
    else if (direction == 'R' || direction == 'r')
    {
        rotateRight(arr, size, n);
    }
    else
    {
        printf("Invalid direction!\n");
        return 1;
    }

    printf("Rotated array: ");
    printArray(arr, size);

    return 0;
}

void rotateLeft(int arr[], int size, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = arr[0];
        for (int j = 0; j < size - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }
}

void rotateRight(int arr[], int size, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = arr[size - 1];
        for (int j = size - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}