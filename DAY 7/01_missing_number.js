// Q 1 -> Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

//! Bruteforce approach .

let nums = [3, 0, 1]
function missingNumberBrute(nums) {
    let missingElement = 0;
    let find = false;
    for (let i = 0; i <= nums.length; i++) {
        for (let j = 0; j < nums.length; j++) {
            if (i === nums[j]) {
                find = true;
                break;
            }
        }
        if (find) {
            find = false;
        } else {
            return i;
        }
    }
}
// console.log(missingNumberBrute(nums);

//! using set..

//? (a) storing the array into the set and then running a loop from 0 to n and checking which is missing in set..
function missingNumberSet(nums) {
    let set = new Set(nums);
    console.log(set);
    for (let i = 0; i <= nums.length; i++) {
        if (!set.has(i)) {
            return i;
        }
    }
}
// console.log(missingNumberSet(nums));

//? (b) storing the range in the set instead of array .

function missingNumberSet1(nums) {
    let set = new Set();
    for (let i = 0; i <= nums.length; i++) {
        set.add(i);
    }
    console.log(set);

    for (let i = 0; i <= nums.length; i++) {
        if (set.has(nums[i])) {
            set.delete(nums[i])
        }
        // console.log(set);
    }
    return [...set][0];
}
console.log(missingNumberSet1(nums));


//! (3) using map
/**
    let arr = [1, 2, 3, 4, 5];
    let map = new Map(arr);  // ❌ ERROR: arr is not an array of key-value pairs
    console.log(map);
    Map expects an array of pairs ([key, value]), but [1, 2, 3, 4, 5] is    just an array of numbers.
    JavaScript doesn’t know what should be the keys and what should be the values.
*/


//? (a) storing array element as key in map .. 
function missingNumberMap(nums) {
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        map.set(nums[i], 0);
    }
    // console.log(map);

    for (let i = 0; i <= nums.length; i++) {
        if (!map.has(i)) {
            return i;
        }
    }
}
// console.log(missingNumberMap(nums));


//? (b) storing all values from 0 to n inside the map..
function missingNumberMap1(nums) {
    let map = new Map();
    for (let i = 0; i <= nums.length; i++) {
        map.set(i, i);
    }
    console.log(map);
    for (let i = 0; i < nums.length; i++) {
        if (map.has(nums[i])) {
            map.delete(nums[i]);
        }
    }
    // console.log(map);
    return [...map][0][0];
}
console.log(missingNumberMap1(nums));



//! (4) optimal approach .
/*
logic is simple since the element are from 0 to n and we need to find the missing one .. 
so first we find the total n element sum and then subtract it with current sum.
*/


function missingElement(nums) {
    let totalSum = 0;
    let currentElementSum = 0;
    let missingElement = -1;
    for (let i = 0; i < nums.length; i++) {
        currentElementSum += nums[i];
        // we can calculate total sum and current element sum 
        // inside the single loop.
        // totalSum=totalSum+i+1;
    }

    // toal sum of n element..
    for (let i = 1; i <= nums.length; i++) {
        totalSum = totalSum + i;
    }
    missingElement = totalSum - currentElementSum;
    return missingElement;
}
console.log(missingElement(nums));


//! check this approach ??
/*
approach is we are setting the count to 1 for element that can occur from 0 to n and next we are checking which array element  is not having count 1 ..  
like if array is 0,1,2 then missing is 3 because length is 3 so inside map 0-1, 1-1, 2-1 and then we run a loop 0 to n and checking is 0-1 if yes then continue -------
we can also do something like using map.. only key-value pair required.

function missing(nums) {
    let map = new Map();
    for (let i = 0; i <= nums.length; i++) {
        // like setting the count 1 for all the element from 0 to n
        map.set(i, 1);
    }
    console.log(map);

    for (let i = 0; i <= nums.length; i++) {
        // console.log('HII')
        if ((map.get(i)) === 1) {
            console.log(map.has(i));
            return i;
        }
    }
}
*/
