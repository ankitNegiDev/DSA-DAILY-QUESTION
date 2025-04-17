// Q 3 => write a program to calculate the sum of all even number and sum of all odd numbers which are stored in the array of size 10 take array values from the user.

// Q 2 => write a program to calculte the average of numbers stored in an array of size 10 take array values from the user..

#include <stdio.h>
void inputArrayData(int *arr, int size);
void displayArrayData(int *arr, int size);
int sumOfEven(int *arr,int size);
int countEvenNumber(int *arr, int size);
int sumOfOdd(int *arr,int size);
int countOddNumber(int *arr, int size);

int main()
{
    int size;
    printf("enter the value of size \n");
    scanf("%d", &size);
    int arr[size];
    inputArrayData(arr, size);
    displayArrayData(arr, size);
    int evenSum=sumOfEven(arr,size);
    int evenCount=countEvenNumber(arr,size);
    printf("\nthe sum of %d even number in array is %d\n",evenCount,evenSum);
    int oddSum=sumOfOdd(arr,size);
    int oddCount=countOddNumber(arr,size);
    printf("\nthe sum of %d odd number in array is %d\n",oddCount,oddSum);
    return 0;
}
void inputArrayData(int *arr, int size)
{
    printf("enter the data in the %d size array\n", size);
    for (int i = 0; i < size; i++)
    {
        // scanf("%d",&arr[i]);
        // scanf("%d",&*arr+i);
        scanf("%d", arr + i);
    }
}
void displayArrayData(int *arr, int size)
{
    printf("the %d data of array is : \n", size);
    for (int i = 0; i < size; i++)
    {
        // printf("%d ",arr[i]);
        printf("%d ", *arr + i);
    }
}

int countOddNumber(int *arr, int size){
    int count=0;
    for(int i=0; i<size; i++){
        if((*arr+i)%2!=0){
            count++;
        }
    }
    return count;
}

int countEvenNumber(int *arr, int size){
    int count = 0;
    for(int i=0; i<size; i++){
        if((*arr+i)%2==0){
            count++;
        }
    }
    return count;
}

int sumOfOdd(int *arr, int size){
    int sum=0;
    for(int i=0; i<size; i++){
        if(arr[i]%2==1){
            sum=sum+arr[i];
        }
    }
    return sum;
}
int sumOfEven(int *arr, int size){
    int sum=0;
    for(int i=0; i<size; i++){
        if(arr[i]%2==0){
            sum=sum+arr[i];
        }
    }
    return sum;
}


