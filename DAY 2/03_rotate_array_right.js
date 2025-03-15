// Rotate Array right by K side...


//! Brute force
let arr = [1, 2, 3, 4, 5, 6, 7];
let rotationTime = 3;
function rotateRight(arr, rotationTime) {
    for (let i = 0; i < arr.length; i++) {
        let temp = arr[arr.length - 1];
        if (rotationTime) {
            for (let j = arr.length - 1; j >= 1; j--) {
                arr[j] = arr[j - 1];
            }
            arr[0] = temp;
            rotationTime--
        }
    }

}
// console.log(rotateRight(arr, rotationTime));
// console.log(arr);


//! using extra space...

function rotateRightExtraSpace(arr, rotationTime) {
    let result = new Array();
    let remaningArrayLength = arr.length - rotationTime;
    console.log(remaningArrayLength);
    for (let i = 0; i < arr.length; i++) {
        if (rotationTime) {
            result[i] = arr[arr.length - rotationTime];
            console.log("result", result);
            rotationTime--;
        } else {
            console.log("i in else", i);
            console.log(i - (remaningArrayLength - 1));
            result[i] = arr[i - (remaningArrayLength - 1)];
            console.log("result [i] is -> ", result[i]);
        }
    }
    return result;
}
// console.log(rotateRightExtraSpace(arr, rotationTime));
/**
 * the above code might work fine for the odd length array but not for the even length array ....
 * let remaningArrayLength=nums.length-k; so for odd length of array we can find the index like arr[i-(remaningLength-1)] but for even length it will not be 0 it will come as 1 .. so either we need to write the logic to check the array length is even or odd   or we can take another variable and store the rotation time ...
 *! to avoid this we can use a variable and store the rotation times. and used it for to get valid index..
 ** edge case ... 
    *? (1) when array length is 1 and rotation are done above then length ... so for single length we can directly return the arr[0]. or arr[arr.length-1]
        * eg => [1], k=2

    *? (2) when array length is valid or greater then 2 but rotation are done above the length of array.. so run a while loop like this ..
        while (k > nums.length) {
            k = k - nums.length;
        }
        * eg => [1,2] , k=3 or k=5 
 */


function rotateRightExtraSpaceModify(nums, k) {

    // edge case 1 => single element.. 
    // [1] and k=2
    if (nums.length <= 1) {
        return nums[0];
    }

    // edge case 2 => rotation are larger then current length of array.

    // [1,2] and k=3
    // [1,2] and k=5
    while (k > nums.length) {
        k = k - nums.length;
    }

    // using extra space 
    let rotatedArray = [];
    // let remaningArrayLength=nums.length-k; so for odd length of array we can find the index like arr[i-(remaningLength-1)] but for even length it will not be 0 it will come as 1 .. so either we need to write the logic to check the array length is even or odd   or we can take another variable and store the rotation time ...
    let rotationtime = k;
    for (let i = 0; i < nums.length; i++) {
        if (k) {
            rotatedArray[i] = nums[nums.length - k];
            k--;
        } else {
            console.log("value of i is", i);
            rotatedArray[i] = nums[i - rotationtime];
        }
    }
    // console.log(rotatedArray);
    // return rotatedArray; // question says we need to do in-place...
    // nums=[...rotatedArray];
    // console.log(nums);
    // return nums;
    for (let i = 0; i < nums.length; i++) {
        nums[i] = rotatedArray[i];
    }

}
// console.log(rotateRightExtraSpaceModify(arr, 3));
// console.log(arr);

function rotateRightExtraSpaceOptimal(nums, k) {

    k = k % nums.length; // to avoid the extra roation.. (same to our while loop.)

    let rotatedArray = new Array(nums.length);

    for (let i = 0; i < nums.length; i++) {
        rotatedArray[(i + k) % nums.length] = nums[i];
        // so for the first iteration .. if i=0, k=3, and nums.length is 7 so 3 % 7 is 3 that means element at first index moves to index 3 after rotating 3 times.
        // 1+3%7=> 4%7= 4 means element at 1 index will now 4th index element
    }

    // Copy back to nums (in-place)
    for (let i = 0; i < nums.length; i++) {
        nums[i] = rotatedArray[i];
    }
}
console.log(rotateRightExtraSpaceOptimal(arr, 3));
console.log(arr);
