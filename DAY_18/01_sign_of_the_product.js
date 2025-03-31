// sign of the product of an array
/**
 * there is a function signFunc(x) that returns : 
    * 1 if x is positive.
    * -1 if x is negative.
    * 0 if x is equal to 0
 * you are given an integer array nums. let product be the product of all values in the nums.
 */

// console.log(-1*-3);

//! Brute force approach .. 
let arr = [-1, -2, -3, -4, 3, 2, 1];
function signOfArray(arr){
    let product=1;
    for(let i=0; i<arr.length; i++){
        product=product*arr[i];
    }
    if(product>0){
        return "+1";
    }else if(product===0){
        return 0;
    }else{
        return "-1";
    }
}
console.log(signOfArray(arr));


//! approach 2 ..  count.
/**
 * we will count no of -ve element in the arrya if elemeent are even that simply means sign is +1 because we know that (-1*-1) is +1 if odd then ans is -1 and if any array element is 0 that means reutrn 0. becasue -1*0 is 0 and +1*0 is 0
 */

function arraySign1(arr){
    let negVal=0;
    for(let i=0; i<arr.length; i++){
        if(arr[i]<0){
            negVal++;
        }else if(arr[i]===0){
            return 0;
        }
    }
    if(negVal%2==0){
        console.log("negValue : ",negVal);
        return +1;
    }else{
        return -1;
    }
}
console.log("array sign math : ",arraySign1(arr));