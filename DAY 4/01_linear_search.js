// Q 1 => Given an array, arr[] sorted in ascending order and an integer k.Return true if k is present in the array, otherwise, false.

// Brute force

let arr = [1, 2, 3, 4, 5, 6];
function searchInSortedArray(arr, k) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === k) {
            return true;
        }
    }
    return false;
}
console.log(searchInSortedArray(arr, 6));

// using binary search ...

function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;
    // since in js we don't have integer overflow case so we can avoid checking for it..
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        console.log(`left : ${left} right is ${right} and mid is ${mid}`);
        if (arr[mid] === target) {
            return true;
        } else if (arr[mid] > target) {
            // if current element is greater then target that simply means our target is on the left side so decrease the right=mid-1;
            right = mid - 1;
        } else if (arr[mid] < target) {
            // if current element is less then target that simply means our target is on the right side so increse left.. lft=mid+1
            left = mid + 1;
        }
    }
    return false;
}
console.log(binarySearch(arr, 6));
