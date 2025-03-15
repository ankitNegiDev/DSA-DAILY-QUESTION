// Q 2 => Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

// Note: The second largest element should not be equal to the largest element.




// let arr = [12, 35, 1, 10, 34, 1];
// let arr = [10, 5, 10];
// let arr = [10, 5, 10, 8];
// let arr = [10, 10, 10];
// let arr = [-1, -5, 0, 1, 2];
// let arr = [ -2, -5, -5, 9];
let arr = [10, 10, 10];

//! assume we can use sorting then ... 
function secondLargestElementSorting(arr) {
    if (arr.length <= 1) {
        return -1;
    }
    let a = arr.sort(function (a,b) { return a - b; });
    // console.log("sorted", a);
    for (let i = arr[arr.length - 2]; i >= 0; i--){
        if (arr[arr.length - 1] > arr[i]) {
            // console.log("value of arr[i] is ", arr[i]);
            return arr[i];
        }
    }
    return -1;
}
// console.log(secondLargestElementSorting(arr));


// Time complexity - O(nlogn + n) , Space complexity - O(1)

//! brute force approach ..

function secondLargestElement(arr) {
    if (arr.length <= 1) {
        return -1;
    }
    let firstLarge = arr[0];
    let secondLarge = arr[1];
    for (let i = 0; i < arr.length; i++){
        if (firstLarge < arr[i]) {
            secondLarge = firstLarge;
            firstLarge = arr[i];
        } else if (secondLarge < arr[i] && arr[i] !== firstLarge) {
            secondLarge = arr[i];
        }
    }
    if (firstLarge === secondLarge) {
        return -1; 
    } else {
        return secondLarge;
    }
}
console.log(secondLargestElement(arr));

/**
 * why the arr[i] !== firstLarge condition .... this is for the case when we have input like this 10,5,10 here we know that second large element is 5 but if we did not apply the condition arr[i] !==firstLarge then secondLarge will be 10 in our case which is not true so to avoid this firstLarge and secondLarge never be same.
 * the reason why we are checking firstLarge===secondLarge is because we need to prevenet the case when array element are same in that case our firstLarge and secondLarge would be same which is incorrect so we need to return -1 because second large element does not exist.
 * why secondLarge is not -1 since we are assuming that our array can have -ve no so we can't put -1.
 */
