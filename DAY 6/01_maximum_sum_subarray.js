/**
 * Q => Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

 * Note: A subarray is a contiguous part of any given array.
 */


// sub array .. let arr=[1,2,3,4];  contiginous part of array like , 1, 1,2,3 or 2,3  its is not like 2,4,1 it is a subsecquence.
/**
 * the minimum size of the sub array is of size 1.
 * the maximum size of the sub array is the entire length of original array.
 */

// print the sub array .
let arr1=[10,20,30,40,50]
function printSubArray(arr) {
    for (let i = 0; i < arr.length; i++) {
        let subArray = [];
        for (let j = i; j < arr.length; j++) {
            subArray.push(arr[j]); 
            console.log(subArray); 
        }
    }
}
printSubArray(arr);
/**
    [ 10, 20 ]
    [ 10, 20, 30 ]
    [ 10, 20, 30, 40 ]
    [ 10, 20, 30, 40, 50 ]
    
    [ 20 ]
    [ 20, 30 ]
    [ 20, 30, 40 ]
    [ 20, 30, 40, 50 ]
    
    [ 30 ]
    [ 30, 40 ]
    [ 30, 40, 50 ]
    
    [ 40 ]
    [ 40, 50 ]
    
    [ 50 ]
 */

// Brute force approach ..

let arr = [100, 200, 300, 400];
function maximumSumSubarrayBrute(arr, k) {
    let maxLength = 0;
    let maxSum = 0;
    for (let i = 0; i <= arr.length - k; i++) {
        let subArray = [];
        let sum = 0;
        for (let j = i; j < i + k; j++) {
            subArray.push(arr[j]);
            console.log(subArray);
        }
        for (let i = 0; i < subArray.length; i++) {
            sum += subArray[i];
        }
        console.log(sum);


        if (maxLength <= subArray.length) {
            maxLength = subArray.length;
            if (maxSum < sum) {
                maxSum = sum;
            }
        }
    }
    console.log("max length ", maxLength);
    console.log("max Sum", maxSum);
}
// maximumSumSubarrayBrute(arr, 2);


// optimized approach using sliding window or two pointer...
function maximumSumSubarray(arr, k) {
    // code here
    let left = 0;
    let right = 0;
    let maxSum = 0;
    let sum = 0;
    while (right < arr.length) {
        sum = sum + arr[right];

        if (right - left + 1 < k) {
            right++;

        } else if ((right - left) + 1 === k) {
            if (sum > maxSum) {
                maxSum = sum;
            }
            sum = sum - arr[left];
            left++;
            right++;
        }

    }
    return maxSum;
}
// console.log(maximumSumSubarray(arr, 2));



//! getting error here .....  check dry run ...... problem with index.. check while rev
// let arr = [100, 200, 300, 400];
/*
let k = 2;
function subArray(arr, k) {
    let left = 0;
    let right = k;
    let sum = 0;
    let maxSum = 0;
    while (left < k) {
        sum = sum + arr[left];
        // console.log("sum", sum);
        left++;
        right++;
    }
    console.log(sum, left, right);
    if (maxSum < sum) {
        maxSum = sum;
    }
    sum = sum - arr[left - k - 1];
    while (right < arr.length) {
        sum = sum + arr[left];
        right++;
        left++;
    }

    if (maxSum < sum) {
        maxSum = sum;
    }
    return maxSum;
}
// console.log(subArray(arr, 2));
*/

// modified of above

function subArray(arr, k) {
    // sum of first k elements
    let sum = 0;
    let left = 0;
    let right = k;

    for (let i = 0; i < k; i++) {
        sum += arr[i];
    }

    let maxSum = sum;
    while(right < arr.length) {
        sum = sum - arr[left] + arr[right];
        // maxSum = Math.max(maxSum, sum); 
        if (sum > maxSum) {
            maxSum = sum;
        }
        left++;
        right++;
    }

    return maxSum;
}

console.log(subArray(arr, k));
