// second smallest element.



// let arr = [10, 5, 10, 2];
let arr = [-1, 2, -4, -1000, 1000];
// let arr = [0, 0, 0];
// let arr = [1];



//! using sorting ..
function secondSmallestSorting(arr) {
    if (arr.length <= 1) {
        return -1;
    }
    let a = arr.sort(function (a, b) { return a - b });
    console.log(a);
    for (let i = 1; i < arr.length; i++){
        if (arr[i] !== arr[0]) {
            return arr[i];
        }
    }
    return -1;
}
// console.log(secondSmallestSorting(arr));

function findSecondSmallest(arr) {
    if (arr.length <= 1) {
        console.log("sorry the length of array is less then 2");
        return -1;
    }
    let firstSmallest = arr[0];
    let secondSmallest = arr[1];
    for (let i = 0; i < arr.length; i++){
        if (arr[i] < firstSmallest) {
            secondSmallest = firstSmallest;
            firstSmallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] !== secondSmallest) {
            // console.log("---hel");
            // console.log(arr[i],i);
            secondSmallest = arr[i];
        }
    }
    if (secondSmallest === firstSmallest) {
        console.log("sorry no second smallest element found ");
        return -1;
    } else {
        return secondSmallest;
    }
}
console.log(findSecondSmallest(arr));

// Time complexity - O(n) , space complextiy - O(1).
