// Q 1 => Given an array arr[]. The task is to find the largest element and return it.
let arr = [1, 8, 7, 56, 90];

// Brute force solution
//! using sorting ..
function largestElementSorting(arr) {
    arr.sort();
    return arr[arr.length - 1];
}
console.log(largestElementSorting(arr));

// Time complexity - O(nlogn) , Space complexity - O(1).


//! using normal logic 
function largestElement1(arr) {
    let max = arr[0];
    for (let i = 0; i < arr.length; i++){
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}
console.log(largestElement1(arr));

// Time complexity - O(n), Space complexity - O(1)

