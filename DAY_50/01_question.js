// Q 1 => Given an array which only contains 0 & 1 the data is shuffled randomly we have to write a function that re-arrange the data such that all the 0's are present before 1
// eg : [1, 0, 0, 1, 1, 0, 1, 0, 0, 1]-- -> [0, 0, 0, 0, 1, 1, 1, 1]
// do not create any new array..and we are not allowed to use any internal function also. also we can't traverse array more then one time.. we can traverse array only one time.

// eg : [1, 0, 0, 1, 1, 0, 1, 0, 0, 1]-- -> [0, 0, 0, 0, 1, 1, 1, 1]

// using two pointer
let arr = [1, 0, 0, 1, 1, 0, 1, 0, 0, 1];
function rearrangeArrayTwoPointer(arr) {
    let left = 0;
    let right = arr.length - 1;
    // we have to make sure that before left every thing is 0 ..
    // and after right everything is 1..
    while (left < right) {
        if (arr[left] === 0) {
            left++;
        } else if (arr[right] === 1) {
            right--;
        } else if (arr[left] !== 0 || arr[right] !== 1) {
            // swapping..
            let temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++, right--;
        }

        // or we can do if(arr[i]==0 ) left ++
        // if(arr[i]==1) do swapping.
        // it is also fine
    }
    return arr;
}
console.log("the re-arrange array is : ", rearrangeArrayTwoPointer(arr));

// using count .. we can count 0 and 1..
// this is a valid but acc to question we can't do like this.
function rearrangeArrayCount(arr) {
    let countZero = 0;
    let countOne = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === 0) {
            countZero++;
        } else {
            countOne++;
        }
    }
    for (let i = 0; i < arr.length; i++) {
        if (i < countZero) {
            arr[i] = 0;
        } else {
            arr[i] = 1;
        }
    }
    return arr;
}
console.log("the re-arrange array is : ", rearrangeArrayTwoPointer(arr));
