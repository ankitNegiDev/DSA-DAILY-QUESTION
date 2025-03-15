// similar to largest element ...

//! bruteforce ... sorting
let arr = [1, 2, 3, 4];
function smallestElementSorting(arr) {
    arr.sort();
    return arr[0];
}
console.log(smallestElementSorting(arr));

// Time complexity - O(nlogn), Space complexity - O(1)

//! optimal...
function smallestElement(arr) {
    let smallest = arr[0];
    for (let i = 0; i < arr.length; i++){
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}
console.log(smallestElement(arr));

