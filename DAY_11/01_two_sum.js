// Q 1 =>  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.


// the given question is two sum problem...



//! (1) Bruteforce approach .. since we have to return the first pair which is eqivalent to target..
/**
 * the approach is simple we will check each ith element pair are they equivalent to the target or not .. like 2 and 7 , 2 and 11 etc.. if yes then return the index in array format.
 */
let arr = [2, 7, 11, 15], target = 9
// Output: [0, 1]

function twoSumBrute(arr, target) {
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr.length; j++) {
            if (i === j) {
                continue
            }
            // when the continue will hit no mater what code is written below it wont execute. same for break same for return keyword.
            if (arr[i] + arr[j] === target) {
                return [i, j];
            }
        }
    }
    return [-1, -1];
}
console.log("two Sum Brute  :", twoSumBrute(arr, target));

// time complexity of above solution is O(n*n) and space complexity if O(2) ≈ O(1)


function twoSumBruteOptmize(arr, target) {
    for (let i = 0; i < arr.length; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[i] + arr[j] === target) {
                return [i, j];
            }
        }
    }
    // if no pair exist then 
    return [-1, -1];
}
console.log("two sum brute Optmize : ", twoSumBruteOptmize(arr, target));

// time complexity of above solution is O(n*n) and space complexity if O(2) ≈ O(1)


/**
 * now why we are starting the j with i+1 the reason if we check 2,7 or 2,11 or 2,15  then there is no need to check for 7 ,2 we its just redundent we can simply check 7,11 because if 7 and 2 gives the target then there it should be already our ans since 2,7 will also have equivalent to target.. but if we incist to start the j with 0 then we can do if (i===j) the continue else { if(arr[i]+arr[j] === target)} then we have to do like that..
 */



// ? (2) using another array..
/**
 * approach is simple we will store the array element in the array like at 0 it is 2 , at 1 it is 7 etc.. 
 * then we will run a loop and check that let key = target-currentValue if key is present in the array or not if yes then its a pair that on adding will give target.. example . if we have 2 at 0 index then there is no 7 so we will store 2 in our array at 0 index. next element is 7 then target (9) -7 which is 2 so is 2 is in our array yes so its our ans ... now how to find index then we can use indexOf() find() function etc  something like otherwise we can run the simple loop to get index...
 */
// let arr1 = [3, 2, 4];
// let target1 = 6

// let arr1 = [0, 4, 3, 0];
// let target1 = 0;

let arr1 = [-3, 4, 3, 90]
let target1 = 0;

function twoSumExtraSpaceUsingArray(arr, target) {
    let storedArray = [];
    for (let i = 0; i < arr.length; i++) {
        let key = target - arr[i];
        // console.log("key -> ", key);
        // console.log(storedArray.find(function callback(element,index,arr){console.log(element)}));
        // we can also use includes...here.
        // console.log("helooooooo",storedArray.find(function callback(element) { if (element === key) { if (element === 0) { return 1 } else { return element } } }));
        
        /*
        if (storedArray.find(function callback(element) { if (element === key) { if(element===0){return 1}else{return element} } })) {
            console.log("if execute");
            // console.log(storedArray.indexOf(key));
            // return [i, storedArray.indexOf(key)];
        } else {
            storedArray.push(arr[i]);
        }
        console.log(storedArray);
        */
        // lets store the result of find..
        let findRes = storedArray.find(function callback(element) {
            // console.log("element:", element, "key:", key);
            return element === key;
        });
        // console.log("-----find res", findRes);
        if (findRes === 0) {
            return [i, storedArray.indexOf(key)];
        }
        if (findRes !== undefined) {
            return [i, storedArray.indexOf(key)];
        } else {
            storedArray.push(arr[i]);
        }
        // console.log(storedArray);

    }
    return [-1, -1];
}
console.log("two sum extra space using array : ", twoSumExtraSpaceUsingArray(arr1, target1));


//? (3) using hasmap.

function twoSumHashMap(arr, target) {
    let map = new Map();
    for (let i = 0; i < arr.length; i++){
        let key = target - arr[i];
        if (map.has(key)) {
            return [i, map.get(key)];
        } else {
            map.set(arr[i], i);
        }
    }
    return [-1, -1];
}
console.log("two sum using map:", twoSumHashMap(arr1, target1));


//! Assuming that array is sorted then same question....

//? (4) using two pointer approach..
/**
 * the approach is simple just put the left and right pointer and add them if they are smaller then targer then move left pointer by 1 step and if they are bigger then target then just move right pointer left direction by 1 step.. and if left >= right then stop the codee and if did not find then return -1 -1.
 */

let arr2 = [2, 5, 6, 8, 11];
let target2 = 14;

function twoPointer(arr, target) {
    let left = 0;
    let right = arr.length - 1;
    // while(left<=right)
    /**
     * why not left<=right the reason is because we were asked about two index.. so if it is the case like  [2,5,6,8,11] and target is 12 then our ans would be 2,2 but the question says that we can't use same elemnt twic that's why we will run loop legt < right
     */
    while (left < right) {
        // if arr[left]+arr[right] > target  it means right --
        if (arr[left] + arr[right] > target) {
            right--;
        } else if (arr[left] + arr[right] < target) {
            left++;
        } else if(arr[left] + arr[right] === target) {
            return [left, right];
        }
    }
    return [-1, -1];
}

console.log("two pointre : ", twoPointer(arr2, target2));
