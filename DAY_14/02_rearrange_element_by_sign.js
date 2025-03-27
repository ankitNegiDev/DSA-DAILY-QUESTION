// You are given a 0 - indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.


// the question says that we need to rearrange the array in such way that array start from positive and then negativ ans so on.. first element is always positive .. and the order in which positive or -ve element appear in original it should be intact means if array is [1,2,-5,-8,3,-6] then first 1 then -5 then 2 then -8 and then 3 and -6 means 1,2,3 are in same order after re-arranging  and -5,-8 and -6 are in same order...


//! Bruteforce approach . 
/**
 * the approach is simple first we will get all the +ve element and then we will get all the -ve element and then insert it into the result array.
 */
let arr = [3, 1, -2, -5, 2, -4];
function rearrangeBrute(arr) {
    let result = [];
    let positiveArr = [];
    let negativArr = [];
    for (let i = 0; i < arr.length; i++){
        if (arr[i] < 0) {
            negativArr.push(arr[i]);
        } else {
            positiveArr.push(arr[i]);
        }
    }
    console.log("negative arr:", negativArr);
    console.log("positive arr:", positiveArr);
    /*
    for (let i = 0; i < positiveArr.length; i++){
        result.push(positiveArr[i]);
        result.push(negativArr[i]);
    }
    */
    for (let i = 0; i < Math.floor(arr.length / 2); i++){
        result[2 * i] = positiveArr[i];
        result[2 * i + 1] = negativArr[i];
    }
    return result;
}
console.log(rearrangeBrute(arr));


function rearrangeBruteWithTwoPointer(arr) {
    let left = 0;
    let right = 1;
    let result = new Array(arr.length);
    let index = 0;

    while (index < arr.length) {
        if (arr[left] > 0 && index % 2 === 0) {
            result[index] = arr[left];
            left++;
            index++;
        } else if (arr[right] < 0 && index % 2 === 1) {
            result[index] = arr[right];
            right++;
            index++;
        } else if (arr[left] <= 0) {
            // move to next positive number
            left++; 
        } else if (arr[right] >= 0) {
            // move to next negaitive number
            right++; 
        }
    }

    console.log("Rearranged Array:", result);
    return result;
}
console.log("rearrange brute with two pointer" ,rearrangeBruteWithTwoPointer(arr))

//! approach two .. using two pointer..
// let arr = [3,   1,   -2,   -5,   2,   -4];
// lri ->lri    l
/**
 * what im thinking is that ... first take two pointer left for neg and right for positive one.
 * stpe 1 => when index is 0 check and arr[0] is +ve if yes then no need to do anything move ahead. all l,r,i
 * step 2 => when index is 0 and arr[0] is -ve then swap i+1 with i and incriment left , right ,index.
 * step 3 => next if condition for right and left , then at last two if condition for finding the left and right (pos and neg index.)
 */

/*
for the below code using two pointer getting tle .. check it on rev ... 
 */
// let arr2 = [-1, 1];
/*
! error in the belo code ..
let arr3 = [28, -41, 22, -8, -37, 46, 35, -9, 18, -6, 19, -26, -37, -10, -9, 15, 14, 31];
function rearrangeTwoPointer(arr) {
    let left = 0;
    let right = 0;
    let index = 0;
    while (left < Math.floor(arr.length / 2)) {
        if (arr[right] > 0 && index === 0) {
            left++, right++, index++;
        } else if (arr[left] < 0 && index === 0) {
            let temp = arr[left];
            arr[left] = arr[left + 1];
            arr[left + 1] = temp;
            left++, right++, index++;
        } else if (arr[right] > 0 && arr[index - 1] < 0) {
            if (right !== left) {
                let temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
            right++, index++,left++;
        } else if (arr[left] < 0 && arr[index - 1] > 0) {
            if (left !== right) {
                let temp = arr[right];
                arr[right] = arr[left];
                arr[left] = temp;
            }
            left++, right++, index++;

        } else if (arr[index - 1] > 0) {
            left++;
        } else if (arr[index - 1] < 0) {
            right++;
        }
        console.log("arr is : ", arr);
        console.log("left is : ", left);
        console.log("right is : ", right);
        console.log("index is : ", index);
    }
    return arr;

}
console.log(rearrangeTwoPointer(arr3));
*/
let arr3 = [28, -41, 22, -8, -37, 46, 35, -9, 18, -6, 19, -26, -37, -10, -9, 15, 14, 31];

