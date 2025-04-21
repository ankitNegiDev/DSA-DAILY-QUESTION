// Q 10 => write a function to count the frequence of each element of an array.

// 1,2,3,2,4,3,4 // => 1->1, 2->2, 3->2, 4->2

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
void countFrequency(int *ptr, int size, int *frq)
{
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        bool isCounted = 0;
        for (int k = 0; k < i; k++)
        {
            if (ptr[k] == ptr[i])
            {
                isCounted = 1;
                break;
            }
        }
        if (isCounted)
        {
            continue;
        }
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (ptr[i] == ptr[j])
            {
                count++;
            }
        }
        // frq[index]=count;
        // index++;
        printf("%d -> %d\n", ptr[i], count);
    }
}

int main()
{
    int size;
    printf("enter the value of size\n");
    scanf("%d", &size);
    int arr[size];
    int freqArr[size];
    inputArrayData(arr, size);
    displayArrayData(arr, size);
    countFrequency(arr, size, freqArr);
    // displayArrayData(freqArr,size);

    return 0;
}
