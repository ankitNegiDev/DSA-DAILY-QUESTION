#include <stdio.h>
int countDuplicates(int arr[], int n);

int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Number of elements that appear exactly twice: %d\n", countDuplicates(arr, n));
    return 0;
}
int countDuplicates(int arr[], int n)
{
    int duplicateCount = 0;

    // Check each element in the array
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        // Count occurrences of arr[i] in the array
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        // If the element occurs exactly twice and has not been counted before
        if (count == 2)
        {
            duplicateCount++;
        }
    }

    return duplicateCount;
}