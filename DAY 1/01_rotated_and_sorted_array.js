
let arr = [3, 4, 5, 1, 2];
function checkIsRotatedSorted (arr) {
    let count = 0;
    for (let i = 1; i < arr.length; i++) {
        // this is case when array is sorted and roted 
        if (arr[i] < arr[i - 1]) {
            count++;
        }
    }
    // when the array is sorted in that case end value is greater then the first value but if the array is sorted and rotated by 0 to array length-1 times then arr[0]>arr[arr.length-1]
    // when the all the values are duplicate in that case 
    // arr[end]==arr[begin]
    // and the arr[i-1]==arr[i]
    // so the value of the count will be 0 
    // when the array is roted but not sorted in that case 
    // value of the count for sure it is greater then 1 ..
    if (arr[arr.length - 1] > arr[0]) {
        count++;
    }
    if (count <= 1) {
        return true;
    } else {
        return false;
    }
};
console.log(checkIsRotatedSorted(arr));

/**
 * - 1 . as we know for a ascending sorted array like 1,2,3 etc the arr[i]>arr[i-1] 
 * - here in code inside the loop we are checking if this order (arr[i]>arr[i-1] ) is breaked or not ....  
    * if order is breaks 0 times that means array is sorted.. and if condition will handel the rotation part.
    * if order is break only 1 time then it might be possible that array was initially sorted and then we rotate it but for a rotated array as we know the arr[0] > arr[arr.length-1] element upt to array.length rotations means if array is of 5 size then upto 5 rotation in left side the arr[0] > arr[arr.length-1] so to check this we need to apply a condition .. like if the order is breaks 1 time and arr[0] >arr[arr.length] that means array is sorted and rotated  correctly. but if the arr[0]<arr[arr.length] that means array is not rotated 
    * if order breaks more then 1 times that means array is not sorted...

 */