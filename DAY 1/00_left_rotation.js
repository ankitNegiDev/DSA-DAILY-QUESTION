let arr = [10, 20, 30, 40, 50];

function leftRotate(arr, rotationTime) {
    while (rotationTime) {
        let temp = leftShift(arr);
        arr[arr.length - 1] = temp;
        rotationTime--;
    }
}

function leftShift(arr) {
    let firstElement = arr[0];
    for (let i = 0; i < arr.length-1; i++){

        arr[i] = arr[i+1];
    }
    return firstElement;
}
// leftRotate(arr, 5);

// console.log(arr);


// right rotation ..

function rightRotate(arr, rotationTime) {
    while (rotationTime) {
        let temp = rightShift(arr);
        arr[0] = temp;
        rotationTime--;
    }
}
function rightShift(arr) {
    let lastElement = arr[arr.length - 1];
    for (let i = arr.length-1; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    return lastElement;
}
rightRotate(arr, 5);
console.log(arr);
