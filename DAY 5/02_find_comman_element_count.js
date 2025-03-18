// Find Common Elements count Between Two Arrays
/**
You are given two integer arrays nums1 and nums2 of sizes n and m, respectively. Calculate the following values:

answer1 : the number of indices i such that nums1[i] exists in nums2.
answer2 : the number of indices i such that nums2[i] exists in nums1.
Return [answer1,answer2].
 */

// https://leetcode.com/problems/find-common-elements-between-two-arrays/


let arr1 = [4, 3, 2, 3, 1];
let arr2 = [2, 2, 5, 2, 3, 6];


function twoPointer(arr1, arr2) {
    let ans1 = 0;
    let ans2 = 0;
    for (let i = 0; i < arr1.length; i++) {
        for (let j = 0; j < arr2.length; j++) {
            if (arr1[i] === arr2[j]) {
                ans1++;
                break;
            }
        }
    }

    // second array...
    for (let i = 0; i < arr2.length; i++) {
        for (let j = 0; j < arr1.length; j++) {
            if (arr2[i] === arr1[j]) {
                ans2++;
                break;
            }
        }
    }
    return [ans1, ans2];
}
console.log(twoPointer(arr1, arr2));


function set(arr1, arr2) {
    let ans1 = 0;
    let ans2 = 0;
    // first one ..
    let set2 = new Set(arr2);
    for (let i = 0; i < arr1.length; i++) {
        if (set2.has(arr1[i])) {
            ans1++;
        }
    }

    // second one 
    let set1 = new Set(arr1);
    for (let i = 0; i < arr2.length; i++) {
        if (set1.has(arr2[i])) {
            ans2++;
        }
    }
    return [ans1, ans2];
}
console.log(set(arr1, arr2));