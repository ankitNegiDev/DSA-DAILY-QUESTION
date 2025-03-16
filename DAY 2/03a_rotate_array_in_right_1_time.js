// rotate the array in right 1 time

// Brute force
let arr = [10, 20, 30, 40, 50];
// let arr = [1,2,3];
function rotateArrayInRight(arr) {
    let temp = arr[arr.length - 1];
    for (let i = arr.length-1; i>=1; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}
// rotateArrayInRight(arr);
// console.log(arr);


// using extra space ....
/**
 * approach is simple just push the arr[i] elements to arr.length-1 in roated array[i+1] index.
 */
function rotateArrayInRightExtraSpace(arr) {
    let rotatedArray = [];
    for (let i = 0; i < arr.length-1; i++){
        rotatedArray[i + 1] = arr[i];
    }
    rotatedArray[0] = arr[arr.length - 1];
    return rotatedArray;
}
// console.log(rotateArrayInRightExtraSpace(arr));



// using reversal approach ...
/**
 * let arr=[10,20,30,40,50] and if we rotate it 1 time then it become [50,10,20,30,40] ..
 * so if we reverse the originial array -> [50,40,30,20,10] that means 50 is on its correct position ... now reverse the remaining element.. [40,30,20,10];
 */

function rotateArrayInRightReversal(arr) {
    if (arr.length <= 1) {
        console.log("sorry length is too small");
        return 
    }
    // setep 1 => reverse entire array ... 
    for (let i = 0; i < Math.floor(arr.length / 2); i++){
        let temp = arr[i];
        arr[i] = arr[arr.length - 1 - i];
        arr[arr.length - 1 - i] = temp;
    }
    // console.log(arr);

    // step 2 => reverse the n-k last elements..
    for (let i = 0; i < Math.floor(arr.length - 1) / 2; i++){
        let temp = arr[i + 1];
        arr[i + 1] = arr[arr.length - 1 - i];
        arr[arr.length - 1 - i] = temp;
    }
    console.log("fineial ", arr);
}
rotateArrayInRightReversal(arr);