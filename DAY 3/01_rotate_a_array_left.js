// Q 1 =>  Given an integer array nums, rotate the array to the left by one steps


let arr = [10, 20, 30, 40, 50];
// let arr = [20, 30, 40, 50, 60, 10];

function rotateArrayInLeftBruteForce(arr) {
    let temp = arr[0];
    for (let i = 0; i < arr.length - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[arr.length-1] = temp;
}
// rotateArrayInLeftBruteForce(arr);
// console.log(arr);


// using extra space ... 
/**
 * approach is simple just push the arr[i+1] elements into the roated array and at last index push the arr[0]
 */
function rotateArrayInLeftExtraSpace(arr) {
    let rotatedArray = [];
    for (let i = 0; i < arr.length-1; i++){
        rotatedArray[i] = arr[i+1];
    }
    // rotatedArray[rotatedArray.length] = arr[0];
    rotatedArray[arr.length-1] = arr[0];
    return rotatedArray;
}
// console.log(rotateArrayInLeftExtraSpace(arr));


//! using reverse approach ... 
/**
 * let arr=[10,20,30,40,50] and if we rotate it 1 time then it become [20,30,40,50,10] ..
 * so if we reverse the originial array -> [50,40,30,20,10] that means 10 is on its correct position ... now reverse the remaining element.. [20,30,40,50,10];
 */

function rotateArrayInLeftReverse(arr) {
    // we need to reverse entire array for which we will use swapping..
    for (let i = 0; i < Math.floor(arr.length / 2); i++){
        // console.log("i in first loop ", i);
        let temp = arr[i];
        arr[i] = arr[arr.length - 1 - i];
        arr[arr.length - 1-i] = temp;
    }
    console.log("entire reverse array ", arr);
    /*
    for (let i = arr.length - 2; i >= Math.floor((arr.length - 1) / 2); i--){
        console.log("---- i ", i);
        let temp = arr[i];
        console.log(temp);
        arr[i] = arr[(arr.length - 2)-i];
        arr[(arr.length - 2)-i] = temp;
    }
    */
    /**
     * the problem in this loop is that when the original length of array is odd length then n-1 element will be even length and while initializing the value of i to the n-1 and the arr.length-1 will become eventlength/2 which is a even length .. 
     * eg -> orignal array length is 5 then n-1 element length is 4 and n/2 is 2 so initializing the i to n-1 and then decreasing it .. so index will become 3 and then 2 but if we do >= sign then for the even length of original array this will make one unnecessary swap of element with it self... to avoid this can we use loop from starting...
     */
    for (let i = 0; i < Math.floor((arr.length - 1) / 2); i++){
        // console.log(i);
        let temp = arr[i];
        arr[i] = arr[arr.length - 2 - i];
        arr[arr.length - 2 - i] = temp;
    }
    // now its correctly behaving.. the reason is because since the indexing is staring from 0 and in above case the last index is actual index of counting.. like in 0 based 0 index means counting 1 tha'ts why its working here..
}
rotateArrayInLeftReverse(arr);
console.log(arr);
