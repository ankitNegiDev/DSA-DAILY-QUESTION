// Q 9 => write a function to merge two arrays of the same size sorted in descending order..

// 5,4,3,2,1   // size -> 6
// 10,9,8,7,6 // size -> 5

// just merging the array ... if the question ask for in specific order then we can apply any sorting algo after merging or we can use binary search ....
#include <stdio.h>
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

void mergeTwoArray(int *ptr1, int *ptr2, int size, int *result)
{
    // merging..
    int i = 0;
    while (i < size * 2)
    {
        for (int j = 0; j < size; j++)
        {
            result[i] = ptr1[j];
            i++;
        }
        printf("value of i is %d\n", i);
        for (int k = 0; k < size; k++)
        {
            result[i] = ptr2[k];
            i++;
        }
    }
}

int main()
{
    int size;
    printf("enter the value of size\n");
    scanf("%d", &size);
    int arr1[size];
    int arr2[size];
    int result[size * 2];
    inputArrayData(arr1, size);
    inputArrayData(arr2, size);
    displayArrayData(arr1, size);
    displayArrayData(arr2, size);
    printf("\nmerged array\n");
    mergeTwoArray(arr1, arr2, size, result);
    displayArrayData(result, size * 2);
    return 0;
}