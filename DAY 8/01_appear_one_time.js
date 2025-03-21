//  Q 1 => Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.


// Approach 1 ->
/**
 * using xor bit-wise operator ... as we know that xor table
    0   0   0
    1   0   1
    0   1   1
    1   1   1
 * any number xor with 0 is same number means x ^ 0 = x 
 * eg =>    128 64  32  16  8   4   2   1
            0   0   0   0   1   0   1   0   this is binary of 10
            0   0   0   0   0   0   0   0   this is binary of 0 
        ^   0   0   0   0   1   0   1   0   get the same number 10

 * any number xor with itself is 0 means  x ^ x = 0
 * eg =>    128 64  32  16  8   4   2   1
            0   0   0   0   1   0   1   0   this is binary of 10
            0   0   0   0   1   0   1   0   this is binary of 10
        ^   0   0   0   0   0   0   0   0    10 ^ 10 is 0
 * since we know this that any number ^ samenumber is 0 and in question it is given that all the number exactly appear twice except 1 that means while doing xor of all elmeents the finial ans we will have is the xor of that number which comes one time.
 */
let arr = [4, 1, 2, 1, 2]; // in this 4^1 is 5 and 5^2 is 7 and 7^1 is 6 and 6^2 is 4 so ans is 4.
function singleNumber(arr) {
    let singleNum = 0;
    for (let i = 0; i < arr.length; i++){
        singleNum = singleNum ^ arr[i];
    }
    return singleNum;
}
// console.log("single number is :", singleNumber(arr));


// Bruteforce..
/**
 * so the approach is like we will count the how many times a element is appearing if any of the elmeent is appear 1 time then that is our ans.
 */
// let arr1=[1,2,2,1,4]
// let arr1 = [1];
// let arr1 = [1, 2];
let arr1 = [1, 2, 1];
function singleNumberBrute(arr) {
    // if length of array is 1 then return same element.
    if (arr.length === 1) {
        return arr[0];
    }
    for (let i = 0; i < arr.length; i++){
        console.log("i ", i);
        let single = true;
        for (let j = 0; j < arr.length; j++){
            if (arr[i] === arr[j] && i!=j) {
                single = false;
            }
        }
        console.log("value of single : ", single);
        if (single) {
            return arr[i];
        }
    }
    // if all are appearing twice then return 0.
    return 0;
}
// console.log("single number brute:", singleNumberBrute(arr1));



// Approach 3 => using set.
/**
 * in set we will store the count of each  element whose count is 1 then it appear only 1 time.
 */
/*
let arr2 = [4, 1, 2, 1, 2];
function singleNumberSet(arr) {
    let set = new Set();
    for (let i = 0; i < arr.length; i++){
        let count = 0;
        for (let j = 0; j < arr.length; j++){
            if (arr[i] === arr[j]) {
                count++;
            }
        }
        set.add(count);
    }
    console.log(set);
}
singleNumberSet(arr);
! But the main problem that i got here is what i will do with the count if i don't know whose count is this. like for arr[4,1,2,1,2] set will store like 1,2,2 then how would i know whose element count is 1 that is stored in set .. so i think we can't use set here.
*/
