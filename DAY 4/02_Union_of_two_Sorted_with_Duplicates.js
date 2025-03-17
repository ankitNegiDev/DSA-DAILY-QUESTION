// Q 2 => Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

// Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
// Output: 1 2 3 4 5 6 7
// 
let arr1 = [1, 2, 3, 4, 5];
let arr2 = [1, 2, 3, 4, 5];
// let arr1 = [1, 2, 3, 4, 5];
// let arr2 = [2, 3, 4, 5, 6, 7];
// let arr1 = [-7, 8];
// let arr2 = [- 8, - 3, 8];



// the question is similar to merge two sorted arrays in sorted way ..

// using two pointer approach .. 
function mergeTwoSortedArray(arr1, arr2) {
    let left = 0;
    let right = 0;
    let result = [];
    let index = 0;
    while (left < arr1.length && right < arr2.length){
        if (arr1[left] > arr2[right]) {
            // just checking that result is not having any duplicates... (extra check .. )
            if (index === 0 || result[index - 1] !== arr2[right]) {
                result[index] = arr2[right];
                index++;
            }
            right++;
            
        } else if (arr1[left] < arr2[right]) {
            if (index === 0 || result[index - 1] !== arr1[left]) {
                result[index] = arr1[left];
                index++;
            }
            left++
            
        } else if (arr1[left] === arr2[right]) {
            if (index === 0 || result[index - 1] !== arr1[left]) {
                result[index] = arr1[left];
                index++;
            }
            left++, right++;
        }
    }
    // copying the remaining element of arr1
    while (left < arr1.length) {
        result[index] = arr1[left];
        index++, left++;
    }

    // copying the remainingelement of arr2
    while (right < arr2.length) {
        result[index] = arr2[right];
        index++, right++;
    }
    return result;
}
console.log(mergeTwoSortedArray(arr1, arr2));


//! the above code gives error on gfg i don't know why ... but the logic is two pointer approach .. the only change i did is in above code i assume the arr2 will ahve smaller element at the time of writing code .. in below code i assume arr1 will ahve ... but getting tle for the above code ...

function mergeTwoSortedArray1(a, b) {
    let left = 0;
    let right = 0;
    let result = [];
    let index = 0;

    while (left < a.length && right < b.length) {
        // if left is smaller then right...
        if (a[left] < b[right]) {
            // this if condition will check that no duplicates are added
            // for the 0 index we need to run the if conditon tha'ts why we use
            if (index === 0 || result[index - 1] !== a[left]) {
                result[index] = a[left];
                index++;
            }
            left++;
            // if right is smaller then left 
        } else if (a[left] > b[right]) {
            // this if condtion will check that no duplicates are added 
            if (index === 0 || result[index - 1] !== b[right]) {
                result[index] = b[right];
                index++;
            }
            right++;
        } else {
            // If both elements are equal then we will add only once
            if (index === 0 || result[index - 1] !== a[left]) {
                result[index] = a[left];
                index++;
            }
            left++;
            right++;
        }
    }

    // Copy remaining elements from a
    while (left < a.length) {
        if (index === 0 || result[index - 1] !== a[left]) {
            result[index++] = a[left];
        }
        left++;
    }

    // Copy remaining elements from b
    while (right < b.length) {
        if (index === 0 || result[index - 1] !== b[right]) {
            result[index++] = b[right];
        }
        right++;
    }

    return result;
}
console.log(mergeTwoSortedArray1(arr1, arr2));