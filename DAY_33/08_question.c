// Q 8 => write a recrisive function to print binary of a given decimal numbeer..

// the approach is ... divide the number until quoten is not 0 and store the rminder  read it from bottom to top.. that means we can take the array... and reverse it..

// divisiion operator gives us the quotent and % gives us reminder..
#include <stdio.h>
void printBinaryOfDecimalNumberLoop(int n);
void printBinaryOfDecimalNumberRecursive(int n);
int main()
{
    int n;
    printf("etner the value decimal number\n");
    scanf("%d", &n);

    printBinaryOfDecimalNumberLoop(n);
    printf("\n\n---------method 2 -----------\n\n");
    printBinaryOfDecimalNumberRecursive(n);
}
// 128 64 32 16 8 4 2 1
// 0   0  0   0 1 0 1 1 // its binary of 11
// 0   0  0   0 1 1 0 1 // now its binary of 13
//  so we need to reverse the our result.
void pushData(int *ptr, int size, int data, int lastFilledIndex)
{
    *(ptr + lastFilledIndex) = data;
}
void displayArrayData(int *ptr, int lastFilledIndex)
{
    for (int i = 0; i <= lastFilledIndex; i++)
    {
        printf("%d ", *(ptr + i));
    }
}
void reverseArrayData(int *ptr, int lastFilledIndex)
{
    // using two pointer...
    int left = 0;
    int right = lastFilledIndex;
    while (left <= right)
    {
        int temp = *(ptr + left);
        *(ptr + left) = *(ptr + right);
        *(ptr + right) = temp;
        left++, right--;
        // printf("----helloo\n");
    }
}
void formatBinary(int *ptr, int size, int lastFilledIndex)
{
    // [0 1 2 3 4 5 6 7]
    //        L
    // shift it to the right...
    int shiftingIndex = (size - 1) - lastFilledIndex; // 7-3 -> 4
    for (int i = 0; i < size; i++)
    {
        *(ptr + size - 1 - i) = *(ptr + lastFilledIndex - i);
        // [0, 1,2,3,4,5,6,7]
        //         D -----> D
        //       D ----> D
    }
    // filling the initial indexes with 0.
    for (int i = 0; i <= lastFilledIndex; i++)
    {
        *(ptr + i) = 0;
    }
}
void printBinaryOfDecimalNumberLoop(int n)
{
    int originalNum = n;
    int arr[8];
    int lastFilledIndex = -1;

    while (n != 0)
    {
        int reminder = n % 2;
        printf("%d ", reminder);
        pushData(arr, 8, reminder, ++lastFilledIndex);
        n = n / 2;
        // printf("n is : %d\n",n);
    }
    printf("\n\ndata stroed in array is : \n\n");
    displayArrayData(arr, lastFilledIndex);
    reverseArrayData(arr, lastFilledIndex);
    printf("\nthe reverese data of array is : \n");
    displayArrayData(arr, lastFilledIndex);
    printf("\n\n-------------the binary of %d is :  \n\n", originalNum);
    formatBinary(arr, 8, lastFilledIndex);
    lastFilledIndex = 7;
    displayArrayData(arr, lastFilledIndex);
}

void printBinaryOfDecimalNumberRecursive(int n)
{
    if (n == 0)
    {
        return;
    }
    int reminder = n % 2;
    n = n / 2;
    printBinaryOfDecimalNumberRecursive(n);
    printf("%d ", reminder);
}