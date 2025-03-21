// Q 2 => just like we do for the two sum .. can we do same for product also. but this time no target is given..
// find the maximum product of two distinct elements in the array..

let arr = [1, 4, 3, 6, 7, 0];

// using bruteforce..
function maxProduct(arr) {
    let maxProduct = 1;
    for (let i = 0; i < arr.length; i++){
        for (let j = i + 1; j < arr.length; j++){
            if (arr[i] * arr[j] > maxProduct) {
                maxProduct = arr[i] * arr[j];
            }
        }
    }
    return maxProduct;
}
console.log(maxProduct(arr));

//! think how we can use map here .. since target is not given ... during rev..