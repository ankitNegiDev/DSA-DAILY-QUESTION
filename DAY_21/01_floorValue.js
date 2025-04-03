/*
Given a sorted array arr[] and an integer x, find the index(0 - based) of the largest element in arr[] that is less than or equal to x.This element is called the floor of x.If such an element does not exist, return -1.

Note: In case of multiple occurrences of ceil of x, return the index of the last occurrence.

    Examples

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
Output: 1
Explanation: Largest number less than or equal to 5 is 2, whose index is 1.
*/


//! (1) Bruteforce ... 
let arr = [1, 2, 8, 10, 10, 12, 19];
let x=5;
function floorIndexLinear(arr,x){
    let floorIndex=-1;
    let i=0;
    while(arr[i]<=x){
        floorIndex=i;
        i++;
    }
    return floorIndex;
}
console.log(`the floor index of ${x} is : ${floorIndexLinear(arr,x)}`);

// O(log n) is smaller or better then O(n).. 

//! (2) using binary search ... 
function floorIndexBinary(arr,x){
    let left=0;
    let right=arr.length-1;
    let floorIndex=-1;
    while(left<=right){
        let mid=Math.floor((left+right)/2);
        // no need to check mid === x since floor is not equivalent to x since a floor value is less then or equal to x. 
        if (arr[mid] <= x) {
            floorIndex = mid;
            left = mid + 1;
        } else if (arr[mid] > x) {
            right = mid - 1;
        }
    }
    return floorIndex;
}
console.log(`the floor index of ${x} is : ${floorIndexBinary(arr, x)}`);
