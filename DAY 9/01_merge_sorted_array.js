/** 
Q 1 => You are given two integer arrays nums1 and nums2, sorted in non - decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non - decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1.To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored.nums2 has a length of n.
*/

// questin is merge two sorted array in place in arr1. 

//! Brute force approach  or using sorting ..
/**
 * approach is simple first we will merge the both array and then we will apply the sorting on  hte arr1.
 */

let arr1 = [1, 2, 3,0,0,0];
let arr2 = [2, 5, 6];
let m = 3;  // it is the length  of the arr1
let n = 3;  // it is the length of arr2

function mergeSortedSorting(arr1, arr2, m, n) {
    // first we will copy the arr2 elements in the arr1.
    for (let i = 0; i < arr2.length; i++){
        arr1[m + i] = arr2[i];
    }
    console.log("merged array not sorted : ", arr1);

    // now we will apply the sorting on it..
    arr1.sort();
}
// mergeSortedSorting(arr1, arr2, m, n);
// console.log(arr1);

// time complexity of this solution is  O(n log n)  and space complexity is O(n) because of sort () .

/**
 * for inbuilt sort () method .. time complexity is O(n logn ) and sapce complexity is O(n) worst case 
 */





/**
 * but in this approach we will return the sorted array from the function ... 
 */

// let arr1 = [1, 2, 3];
// let arr2 = [2, 5, 6];
// let m = 3;  // it is the length  of the arr1
// let n = 3;  // it is the length of arr2

function mergeSortedBrute(arr1, arr2, m, n) {
    let left = 0;
    let right = 0;
    let totalLength = m + n; // means total length is equivalent to the length of arr1 and arr2.
    let result = new Array(totalLength).fill(0);
    console.log("result :", result);
    for (let i = 0; i < totalLength; i++){
        // the logic is simple if arr1[left] >arr2[right] that means arr2[i] is smaller since both are sorted so out of both arr2 is smaller. 
        if (arr1[left] > arr2[right]) {
            result[i] = arr2[right];
            right++;
        } else if (arr1[left] < arr2[right]) {
            result[i] = arr1[left];
            left++;
        } else if (left < arr1.length) {
            /*
            this condition will be true in two case when the both left and right are same no like arr[left]=2 and arr[right]=2 so here we will just put the arr[left] in the result array and move the left.. and second case is when this condtion will be true is when assuming all element of arr2 are finished..
            */
            result[i] = arr1[left];
            left++;
        } else if (right < arr2.length) {
            /**
             * sam here also this condtion will be true in two case when both arr1[left] and arr2[right] are having same values and other is when arr1 is having all element finished..
             */
            result[i] = arr2[right];
            right++;
        }
    }
    return result;

    // if the question demand that no duplicates are allowed then we can simply put the one condition that when arr[left] === arr[right] then put eithe arr[left] or arr[right] and do incriment in both left and right.. but then we can't create the array with fixed size like m+n then we will just create the dynamic array..
}
// console.log(mergeSortedBrute(arr1, arr2, m, n));

// time complexity of this solution is O(n + m) and space is O(n).



//! But the question says we can't return the array we need to adjust the rest values in the arr1 so that it consist of sorted merge array..

// let arr1 = [1, 2, 2,0,0,0];
// let arr2 = [2, 5, 6];
// let m = 3;  // it is the length  of the arr1
// let n = 3;  // it is the length of arr2



//? case 2
// let arr1 = [1];
// let arr2 = [];
// let m = 1;
// let n = 0;

//? case 3
// let arr1 = [4, 5, 6, 0, 0, 0];
// let arr2 = [1, 2, 3];
// let m = 3;
// let n = 3;

//? case 4 
// let arr1 = [4, 0, 0, 0, 0, 0, 0];
// let arr2 = [1, 2, 3, 4, 5, 6]
// let m = 1;
// let n = 6;

//? case 5 
// let arr1 = [4, 0, 0, 0, 0, 0];
// let arr2 = [1, 2, 3, 5, 6];
// let m = 1;
// let n = 5;
/**
 * the approach is simple first we initialize the left pointer with 0 for arr1 and right pointer with 0 for arr2 and then a current index variable with 0 so  *no need to currentIndex variable we can do it with left.. just traverse the lft to m+n length.
 * first condition is arr1[left] < arr2[right] that means arr1[left] element is in its valid position so just do left++
 * second condition when arr[left] > arr2[right]  that means we need to do swapping other wise we will loose the arr[left] value  but if we directly put the value in the arr2[right] then our sorted arr2 will become unsorted or distorted so to find the correct index for the arr[left] value we will shift the element in the arr2 until we found this condition when arr[left] < arr2[i+1] that means  on the current index put arr1[left] value ... and there might be possiblity that if arr1[left] value is greater then whole array 2 then we will check by some varible like findIndex ... if the loop is done and we did not find the case where arr1[left]<arr2[i+1] that measn we will put this at last index of arr2.
 * next condition is for duplicates so do nothing just incriment in left since it is already in its correct position..
 * now at last just put al lthe remaning values of arr2 that's it. 
 * But just because of shifting it becomes slightly in efficient then when putting value at last valid index.
*/

//! in this approach we put the element from the first valid index not from the last valid index and just because of this we need to do shifting and which is not efficient as compare to when we put element from the last valid index.

function mergeSortedTwoPointer(arr1, arr2, m, n) {
    let left = 0;
    let right = 0;
    while (left < m && right<n) {
        if (arr1[left] < arr2[right]) {
            // since arr1[left] is in its correct position..
            left++;
        } else if (arr1[left] > arr2[right]) {
            // now we need to do swap becuse suppose we assinging arr2[right] at the current index then we will lost the value at current index..
            let temp = arr1[left];
            arr1[left] = arr2[right];
            
            // now we will do shifting ... 
            let findIndex = false;
            for (let i = right; i < arr2.length-1; i++){
                if (temp < arr2[i + 1]) {
                    arr2[i] = temp; 
                    findIndex = true;
                    break;
                } else {
                    arr2[i] = arr2[i + 1];
                }
            }
            if (!findIndex) {
                arr2[arr2.length - 1] = temp;
            }
            // console.log("aarr 2 in swap :", arr2);

            left++; // why left ++ because we put the correct element at left index so now we need to put correct element on next index that's why doing index++
        } else if (arr1[left] === arr2[right]) {
            left++;
        }
    }
    // this while loop will put first m-1 index elements in the correct order and now we need to just copy the remaining ones.
    right = 0;
    // console.log("left value before puting ", left);
    // console.log("arr2 is ", arr2);
    while (left < m + n && right < n) {
        // console.log("hii");
        arr1[left] = arr2[right];

        left++, right++;
    }
    // console.log("left val is ", left);
    // console.log("right iva ", right);
    // console.log("nums 1:", arr1);
}
mergeSortedTwoPointer(arr1, arr2, m, n);
// console.log("sorted arr1 is : ", arr1);
// console.log(arr2);




// now putting value at last valid index......
/**
 * the approach is simple we will first put the valid value at the last index .. like if arr1[left]>arr2[right] then we will put arr1[left] and do left-- and index -- 
 * if the arr2[right] > arr1[left] then we will put arr2[right] and do right -- and index -- 
 * at last we will copy the remaining element of the arr2.
 */

                        // 4  5  6
// let arr1 = [4, 0, 0, 0, 0, 0];
// let arr2 = [1, 2, 3, 5, 6];
// let m = 1;
// let n = 5;


// let arr1 = [1, 2, 3];
// let arr2 = [2, 5, 6];
// let m = 3;  // it is the length  of the arr1
// let n = 3; // it is leng of arr2 .
function mergeSortedTwoPointerOptimal(arr1, arr2) {
    let left = m - 1;   // 1-> 0 
    let right = n - 1; // 4 -> 3 -> 2 
    let index = arr1.length - 1;  // m+n-1
    while (left >= 0 && right >= 0) {
        // we will put the larger element at the back and do  upt to index 0..
        if (arr1[left] > arr2[right]) {
            arr1[index] = arr1[left];
            left--, index--;
        } else if (arr2[right] > arr1[left]) {
            arr1[index] = arr2[right];
            index--, right--;
        }
    }

    // now copying the remaining element of the arr2 .. 
    while (right >= 0) {
        arr1[index] = arr2[right];
        index--, right--;
    }
}
mergeSortedTwoPointerOptimal(arr1, arr2);
console.log("arr1 sorted : ", arr1);