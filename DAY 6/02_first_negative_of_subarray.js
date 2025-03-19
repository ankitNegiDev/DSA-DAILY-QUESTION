// Q => Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

// Note: If a window does not contain a negative integer, then return 0 for that window.

let arr = [-8, 2, 3, -6, 10];
let k = 2;

function FirstNegativeInteger(arr, k) {

    //! using the variable but there is the error... we can still do but we need another variable which will store 2nd -ve no but instead of this we can use array........  try to write the code during rev...
    // let left=0;
    // let right=0;
    // let negativeValue=0;
    // let result=[];

    // while(right<arr.length){
    //     if(right-left+1<k){
    //         if(arr[right]<0 && negativeValue>=0){
    //             negativeValue=0;
    //         }else{

    //         }
    //         right++;
    //     }else if (right-left+1 === k){
    //          if(negativeValue<0){
    //             negativeValue=0;
    //         }
    //         result.push(negativeValue);
    //         negativeValue=0;
    //     }

    //     left++,right++;

    // }
    // return result;


    let left = 0;
    let right = 0;
    let result = [];
    let negativeArray = [];

    while (right < arr.length) {
        if (arr[right] < 0) {
            negativeArray.push(arr[right]);
        }


        // if k is not reached.
        if (right - left + 1 < k) {
            right++;
        } else if (right - left + 1 === k) {
            if (negativeArray.length === 0) {
                result.push(0);
            } else {
                result.push(negativeArray[0]);

            }

            // kicking out the past..
            if (arr[left] === negativeArray[0]) {
                negativeArray.shift();
            }
            left++, right++;
        }

    }
    return result;
}
console.log(FirstNegativeInteger(arr, k));