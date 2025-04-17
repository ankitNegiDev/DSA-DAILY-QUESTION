// Q 7 => write a program to find second largest elment in the array take array values from the user..

#include <stdio.h>
#include <limits.h>
int secondLargestInArray(int *arr, int size);
int main (){
    int size;
    printf("enter the value of size\n");
    scanf("%d",&size);
    int arr[size];
    printf("enter the data in the array\n");
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    printf("the data of the array\n");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    int secondLargest=secondLargestInArray(arr,size);
    printf("the second largest element in the array is %d\n",secondLargest);
    return 0;
}
int secondLargestInArray(int *arr, int size){
    int max = INT_MIN;
    int secondMax=INT_MIN;
    for(int i=0; i<size; i++){
        if(max<arr[i]){
            // update to both max and second max..
            secondMax=max;
            max=arr[i];
        }else if(max>arr[i] && secondMax<arr[i]){
            // there can be a case where max is greter the current val but secondmax is smaller.. so we need to update this also.
            secondMax=arr[i];
        }
    }
    // edge case for this when same elements..
    /*
    enter the value of size
    3
    enter the data in the array
    3
    3
    3
    the data of the array
    3 3 3
    the max number is 3
    the second largest element in the array is -2147483648
    */
    printf("\nthe max number is %d\n", max);
    if (secondMax == INT_MIN)
    {
        printf("No second maximum found all elements are same.\n");
        return -1;
    }
    return secondMax;
}
