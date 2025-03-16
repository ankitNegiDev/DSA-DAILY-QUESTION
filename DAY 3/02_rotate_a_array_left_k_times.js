// Q 2 =>  Given an integer array nums, rotate the array to the left by one steps , whereas k is a non-negative number.


// brute force approach...
let arr = [10, 20, 30, 40, 50];
console.log(arr);
function rotateArrayInLeftBruteForce(arr, k) {
    for (let i = 0; i < arr.length; i++) {
        let temp = arr[0];
        if (k) {
            for (let i = 0; i < arr.length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[arr.length - 1] = temp;
            k--;
        }
    }
}
// rotateArrayInLeftBruteForce(arr, 3);
// console.log(arr);




//! using extra space ...
/**
 * the approach is simple our goal is to insert the correct element in the roatedArray ...
 */
function rotateLeftExtraSpace(arr, k) {

    k = k % arr.length; // to avoid the extra roation.. (same to our while loop.)

    let rotatedArray = new Array(arr.length);

    for (let i = arr.length-1; i>=0; i--) {
        rotatedArray[i] = arr[(i + k) % arr.length] 
    }

    // Copy back to nums (in-place)
    for (let i = 0; i < arr.length; i++) {
        arr[i] = rotatedArray[i];
    }
}
// console.log(rotateLeftExtraSpace(arr, 3));
// console.log(arr);



//! rotating array left using reverse approach...
/**
 * the approach is simple ... first we reverse the entire array and then reverse the n-k elements ... and then reverse the last k elements  and for reverse we run a half loop always..
 */

function rotateLeftReverse(arr, k) {
    k = k % arr.length;
    // step 1 => reversing the entire array.
    for (let i = 0; i < Math.floor(arr.length / 2); i++){
        temp = arr[i];
        arr[i] = arr[arr.length - 1 - i];
        arr[arr.length - 1 - i] = temp;
    }
    console.log("entire reverse array:", arr);
    
    // step 2 => reversing the first  arr.length - k elements


    // console.log(Math.floor(0));

    for (let i = 0; i < Math.floor((arr.length - k)/2); i++){
        // console.log("hello i am first n-k loop");
        console.log(arr.length - 1 - k - i);
        temp = arr[i];
        arr[i] = arr[arr.length - 1 - k - i]
        arr[arr.length - 1 - k - i] = temp;
        console.log(arr);
    }
    console.log(`first n-k element are : ${arr}`);


    // step 3 =>  reversing the last k elements..


    // console.log(Math.floor(1 / 2));
    for (let i = 0; i < Math.floor(k / 2); i++){
        temp = arr[arr.length - k + i];
        arr[arr.length - k + i] = arr[arr.length - 1 - i];
        arr[arr.length - 1 - i] = temp;
    }
    console.log(`las k element are: ${arr}`);
}
rotateLeftReverse(arr, 7);
console.log("rotated array 1 times :", arr);


// both condition works fine arr.length-1-k-i or arr.length-k-1-i