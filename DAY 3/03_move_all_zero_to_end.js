// Q 2 => Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in -place without making a copy of the array.


let nums = [0, 1, 0, 3, 12];
// let nums = [0, 0, 1]

// Brute force approach

function MoveZeroToEnd(nums) {
    let length = nums.length;
    for (let i = 0; i < length;){
        console.log(i);
        if (nums[i] === 0) {
            let zero = nums[i];
            for (let j = i; j < nums.length-1; j++){
                nums[j]=nums[j+1]
            }
            nums[nums.length - 1] = zero;
            // console.log("lll",nums.length - 1);
            length--;
        } else {
            i++
        }
    }
}
// MoveZeroToEnd(nums);
// console.log(nums);

// 0, 1, 0, 3, 12
// l   r // swapping
// 1 , 0  0  3 12
//     l     r  // swapping.
// 1,  3  0  0 12 
        //   l    r  // swapping

// using two pointer approach ... 
function MoveZeroToEndTwoPointer(nums) {
    let left = 0;
    let right = 0;
    while (right < nums.length) {
        // console.log(right);
        if (nums[right] !== 0) {
            // console.log("insdie the ",left);
            temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;
            right++,left++;
        } else {
            right++;
        }
        // console.log(nums);
        // console.log("outside left", left);
    }
}
// MoveZeroToEndTwoPointer(nums);
// console.log(nums);


// .... normal logic ...
function f(arr) {
    let index = 0;
    for (let i = 0; i < arr.length; i++){
        if (arr[i] !== 0) {
            arr[index] = arr[i];
            index++
        }
    }
    let length = arr.length - index;
    while (length) {
        arr[index] = 0;
        index++, length--;
    }
}
f(nums);
console.log(nums);