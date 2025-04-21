// Q 8 => write a function to print all unique elements in an array..

#include <stdio.h>
#include <stdbool.h>
void inputArrayData(int *arr, int size)
{
    printf("enter the data in the array of %d size\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void displayArrayData(int *arr, int size)
{
    printf("the data of the array of %d size is \n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void printUnique(int *ptr, int size)
{
    printf("\n unique data is \n");

    for (int i = 0; i < size; i++)
    {
        bool alreadyChecked = false;

        // Check if ptr[i] was already printed
        for (int k = 0; k < i; k++)
        {
            if (ptr[k] == ptr[i])
            {
                alreadyChecked = true;
                break;
            }
        }

        if (alreadyChecked)
            continue;
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (ptr[i] == ptr[j])
            {
                count++;
            }
        }
        if (count <= 1)
        {
            printf("%d ", ptr[i]);
        }
    }
}

int main()
{
    int n;
    printf("enter the size of the array \n");
    scanf("%d", &n);
    int arr[n];
    inputArrayData(arr, n);
    displayArrayData(arr, n);
    printUnique(arr, n);
    return 0;
}
