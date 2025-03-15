// Rotate Array right by K side...


//! Brute force
let arr = [1, 2, 3, 4, 5, 6, 7];
let rotationTime = 3;
function rotateRight(arr, rotationTime) {
    for (let i = 0; i < arr.length; i++) {
        let temp = arr[arr.length - 1];
        if (rotationTime) {
            for (let j = arr.length - 1; j >= 1; j--) {
                arr[j] = arr[j - 1];
            }
            arr[0] = temp;
            rotationTime--
        }
    }

}
// console.log(rotateRight(arr, rotationTime));
// console.log(arr);


//! using extra space...

function rotateRightExtraSpace(arr, rotationTime) {
    let result = new Array();
    let remaningArrayLength = arr.length - rotationTime;
    console.log(remaningArrayLength);
    for (let i = 0; i < arr.length; i++){
        if (rotationTime) {
            result[i] = arr[arr.length - rotationTime];
            console.log("result", result);
            rotationTime--;
        } else {
            console.log("i in else",i);
            console.log(i-(remaningArrayLength-1));
            result[i] = arr[i - (remaningArrayLength - 1)];
            console.log("result [i] is -> ", result[i]);
        }
    }
    return result;
}
console.log(rotateRightExtraSpace(arr, rotationTime));