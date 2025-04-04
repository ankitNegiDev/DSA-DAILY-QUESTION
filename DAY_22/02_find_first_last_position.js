// Given an array of integers nums sorted in non - decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.


//! (1) Bruteforce approach..
// let arr = [5, 7, 7, 8, 8, 10];
let arr = [5, 7, 7, 8, 8, 10];
let  target = 8;
// let target=6;
function findFirstLast(arr,target){
    let firstIndex=-1;
    let lastIndex=-1;
    for(let i=0; i<arr.length; i++){
        if(arr[i]===target && firstIndex===-1){
            firstIndex=i;
        }else if(arr[i]===arr[firstIndex]){
            lastIndex=i;
        }
        // or we can do like if(arr[i]===target) then update the last index .. so the proble with first inde is arr[-1] si undefind and it would be false . .techinically it is also correct but depends on u.
    }
    return [firstIndex,lastIndex];
}
console.log(`first and last index of target ${target} is :`,findFirstLast(arr,target));


//! (2) using binary search .. 

/*
function findFirstLastBinary(arr,target){
    let left=0;
    let right=arr.length-1;
    let firstIndex=-1;
    let lastIndex=-1;
    while(left<=right){
        let mid=Math.floor((left+right)/2);
        if(arr[mid]===target){
            if(firstIndex===-1 && lastIndex!=-1){
                firstIndex=mid;
                left=mid+1;
            }else{
                lastIndex=mid;
                right=mid-1;
            }
        }else if(arr[mid]<target){
            left=mid+1;
        }else if(arr[mid]>target){
            right=mid-1;
        }
    }
    return [firstIndex,lastIndex];
}
console.log(`first and last index of target ${target} is ${findFirstLastBinary(arr,target)}`);
*/
// the problem in the above code is it can not find the correct indices of first and last.. we thought that in question it is given that if target found then return its first and last assuming that elmeent is given at the first and last but it is not like this .. the question ask if the element is given it can be at first and last index and middle we need to find the first and last index for it.


//! check what's the problem 
/*
var searchRange = function (nums, target) {
    // using binary search..
    let left = 0;
    let right = nums.length - 1;
    let firstIndex = -1;
    let lastIndex = -1;
    if (nums.length === 1 && nums[0] === target) {
        return [0, 0];
    }
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] === target) {
            if (firstIndex === -1 && lastIndex !== -1) {
                firstIndex = mid;
                left = mid + 1;
            } else {
                if (nums[mid] === nums[nums.length - 1]) {
                    lastIndex = mid + 1;
                    right = mid;
                } else {
                    lastIndex = mid;
                    if (nums[0] === nums[lastIndex]) {
                        right = mid;
                    } else {
                        right = mid - 1;

                    }
                }

            }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return [firstIndex, lastIndex];
};
*/

// one way could be we can find the first index seprately and last index seprately ... check it rev time its easy.

function findFirstLastBinary1 (nums, target) {
    let firstIndex = -1, lastIndex = -1;
    let left = 0, right = nums.length - 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        if (nums[mid] === target) {
            firstIndex = mid;
            lastIndex = mid;

            // assuming if we have given the duplicates then we have to find the first index from the mid to leftmost correct value that is equal to target.
            while (firstIndex > 0 && nums[firstIndex - 1] === target){
                firstIndex--;
            }

            // same for right..
            while (lastIndex < nums.length - 1 && nums[lastIndex + 1] === target){
                lastIndex++;
            }

            // if we found then return it..

            return [firstIndex, lastIndex]; 
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return [firstIndex, lastIndex]; // this is returning the - 1 -1 if not found..
};
console.log(`first and last index of target ${target} is ${findFirstLastBinary1(arr, target)}`);
