// Q 2 => right rotation... 

#include <stdio.h>
void printArray(int arr[], int size);
void rotateRight(int arr[], int size, int n);
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    // int n = 3;
    int n;
    printf("etner the vlaue of no of ration we want \n");
    scanf("%d",&n);

    printf("Original Array: ");
    printArray(arr, size);

    rotateRight(arr, size, n);

    printf("Array after rotating right by %d times: ", n);
    printArray(arr, size);

    return 0;
}

void rotateRight(int arr[], int size, int n)
{
    n = n % size;

    int temp[size];

    // left haflo.
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[size - n + i];
    }

    // right haflo.
    for (int i = 0; i < size - n; i++)
    {
        temp[n + i] = arr[i];
    }

    // storing in roginal arrau..
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