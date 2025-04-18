// Q 1 => rotate array in left
#include <stdio.h>
void rotateLeft(int arr[], int size, int n);

void printArray(int arr[], int size);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]); // total size of array / size of a single block..
    // int n = 3;
    int n;
    printf("etner the vlaue of no of ration we want \n");
    scanf("%d", &n);

    printf("Original Array: ");
    printArray(arr, size);

    rotateLeft(arr, size, n);

    printf("Array after rotating left by %d times: ", n);
    printArray(arr, size);

    return 0;
}

void rotateLeft(int arr[], int size, int n)
{
    // Normalize n to be within the bounds of the array size
    n = n % size; // its like if n === size of array then there is no need to do rotation that much of time we can skip that since we know that after n rotation it will come to same position that's why % using moduloo.

    // Temporary array to store the rotated result
    int temp[size];

    // storing the right part..
    for (int i = 0; i < size - n; i++)
    {
        temp[i] = arr[i + n];
    }

    // storing the left half...
    for (int i = 0; i < n; i++)
    {
        temp[size - n + i] = arr[i];
    }

    // storing the result back to original one..
    for (int i = 0; i < size; i++)
    {
        arr[i] = temp[i];
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
