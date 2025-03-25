// Q  Given an integer array nums, find the subarray with the largest sum, and return its sum.


// the question says return the sum of that sub array whose sum is maximum among all the sub array..

// Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
// Output: 6
//! bruteforce .
/**
 * the approach is simple first we will iterate on each element and calculate its sub array sum. and same process for all the elemnts and at last which subbarray is having maximum sum we will return it..
 */
let arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4];

let arr1 = [1, 2, 3, 4];
function printSubArray(arr) {
    for (let i = 0; i < arr.length; i++){
        let subArray = [];
        for (let j = i; j < arr.length; j++){
            subArray.push(arr[j]);
            console.log(subArray);
        }
    }
}
printSubArray(arr1);

function maximumSubArraySum(arr) {
    let maxSum = 0;
    for (let i = 0; i < arr.length; i++){
        let sum = 0;
        let subArray = [];
        for (let j = i; j < arr.length; j++){
            sum = sum + arr[j];
            subArray.push(arr[j]);
            // console.log(subArray, " with sum ", sum);
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    
    return maxSum;
}
console.log("maximum subarray sum using brute force : ", maximumSubArraySum(arr));


// for the optimal solution we need to use Kadana's algorithm
/**
 * this algorithm tell's that -> 
    ** step 1 => create a maxSum variable with min value in it. create a sum variable for storing sum.
    ** step 2 => run a loop and add sum = sum +arr[i] and check it with max if max sum is less then sum then put value of sum into the max.
    
    ** step 3 => then check if (sum < 0) then move forward and put sum =0 don't put - ve values in sum because it will ultimatly reduce our sum. in else case if sum is greater then 0 then do nothing .. since we want to carry the sum forwared.
 */

function maximumSubArraySumKadans(arr) {
    let maxSum = arr[0];
    let sum = 0;
    for (let i = 0; i < arr.length; i++){
        // step 1 => run a for loop and add sum to current arr[ith index]
        sum = sum + arr[i];
        
        // step 2 => check with max sum 
        if (maxSum < sum) {
            maxSum = sum;
        }
        
        // if sum is <0 then we don't want to carry -ve values ..
        if (sum < 0) {
            sum = 0;
        }
        // else we want ... so no change in sum.
    }
    return maxSum;
}
console.log("maxium sub array sum Kadan's algo : ", maximumSubArraySum(arr));



// follow up question ... print the sub array whose sum is maximum..

let arr2 = [-2, -3, 4, -1, -2, 1, 5, -3];
function printMaximumSubArraySumKadans(arr) {
    let maxSum = -Infinity;
    let sum = 0;
    let subArray
    let start = 0, potentialStartIndex=0,end = 0;
    for (let i = 0; i < arr.length; i++){
        sum = sum + arr[i];
        if (sum > maxSum) {
            maxSum = sum;
            start = potentialStartIndex;
            end = i;
        }

        if (sum < 0) {
            sum = 0;
            /**
             * for -3 the if wil execute and sum will be 0.. i know that the next index may be going to be start of the subarray so i can set the value of start to i  we need  one more variable  . like a valid sub arry is only when sum is = 0 so we started and each time my sum > maxsum the valid sub array length increases but at any point of time if my maxSum > sum that means it is the end of sub array.
             */
            potentialStartIndex = i+1;
        }

    }
    subArray = arr.slice(start, end + 1);
    console.log("sub array : ", subArray);
    return maxSum;
}
console.log("print: ", printMaximumSubArraySumKadans(arr2));


// both are fine ..... 

function printMaximumSubArraySumKadans1(arr) {
    let maxSum = -Infinity;
    let sum = 0;
    let subArray
    let start = 0, end = 0, potentialStartIndex=0;
    for (let i = 0; i < arr.length; i++) {
        if (sum === 0) {
            potentialStartIndex = i;
        }
        sum = sum + arr[i];
        if (sum > maxSum) {
            maxSum = sum;
            start = potentialStartIndex;
            end = i;
        }

        if (sum < 0) {
            sum = 0;
        }

    }
    subArray = arr.slice(start, end + 1);
    console.log("sub array : ", subArray);
    return maxSum;
}
console.log("print: ", printMaximumSubArraySumKadans(arr2));