// https://leetcode.com/problems/sort-colors/description/

// https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

let arr = [2, 0, 2, 1, 1, 0];
// 2 2 1 1 1 0 0 0
// 2 1 0 1 2 1
// 0 2 1 1 0

// bruteforce...
function sortColor(arr) {
    let arr1 = [];
    let arr2 = [];
    let arr3 = [];
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === 0) {
            arr1.push(0);
        } else if (arr[i] === 1) {
            arr2.push(1);
        } else {
            arr3.push(2);
        }
    }
    let result = [...arr1, ...arr2, ...arr3];
    // let result = arr1.concat(arr2, arr3);

    return result;
}
// console.log(sortColor(arr));


// Dutch national flag problem....

//! works fine ?? but .
function threePointer(arr) {
    let left = 0;
    let mid = 0;
    let right = arr.length - 1;
    while (mid <= right) {
        console.log(mid);
        if (arr[left] === 0) {
            // 0 is already in its correct position..
            left++, mid++;
        } else if (arr[mid] === 0) {
            // swap it with left...
            let temp = arr[left];
            arr[left] = arr[mid];
            arr[mid] = temp;
        } else if (arr[mid] === 1) {
            mid++;
        } else if (arr[right] === 2) {
            // right is already in its correct poistion...
            right--;
        } else if (arr[mid] === 2) {
            // swap it with right...
            let temp = arr[right];
            arr[right] = arr[mid];
            arr[mid] = temp;
        }
        console.log(arr);
    }
}
// threePointer(arr);



function dutch(arr) {
    let left = 0;
    let mid = 0;
    let right = arr.length - 1;

    while (mid <= right) {
        if (arr[mid] === 0) {
            // swap it with left...
            let temp = arr[left];
            arr[left] = arr[mid];
            arr[mid] = temp;
            left++, mid++;
        } else if (arr[mid] === 1) {
            mid++;
        } else if (arr[mid] === 2) {
            // swap it with right
            let temp = arr[right];
            arr[right] = arr[mid];
            arr[mid] = temp;
            right--;
        }
    }
}
// dutch(arr);
// console.log("dutch :", arr);


// count one appraoch ...

function count(arr) {
    let countOfZero = 0;
    let countOfOne = 0;
    let countOfTwo = 0;
    let index = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === 0) {
            countOfZero++;
        } else if (arr[i] === 1) {
            countOfOne++;
        } else {
            countOfTwo++;
        }
    }

    while (countOfZero) {
        arr[index] = 0;
        index++, countOfZero--;
    }
    while (countOfOne) {
        arr[index] = 1;
        index++, countOfOne--;
    }
    while (countOfTwo) {
        arr[index] = 2;
        index++, countOfTwo--;
    }
}
// count(arr);
// console.log("count:", arr);

// switch case ...

function switchCase(arr) {
    let left = 0;
    let right = arr.length - 1;
    let mid = 0;
    while (mid <= right) {
        switch (arr[mid]) {
            case 0:
                console.log("left swap");
                let temp = arr[mid];
                arr[mid] = arr[left];
                arr[left] = temp;
                left++, mid++;
                break;
            
            case 1:
                console.log("mid === 1");
                mid++;
                break;
            
            case 2:
                console.log("right swapt");
                let temp1 = arr[mid];
                arr[mid] = arr[right];
                arr[right] = temp1;
                break;
        }
    }
}
switchCase(arr);
console.log("switch:", arr);