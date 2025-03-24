// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times.You may assume that the majority element always exists in the array.


// the question is about which element occur most time...



//! (1) bruteforce ...
/**
 * the approach is simple we will count the each eleemnt and we take maxCount variable and element variable ..  and a count variable .. so every time the count is greater then max count we will update the maxcount and element variable..a t las we will return whose count is max.. like we will return element
 * it might be a question why using the maxCount .. not Math.floor(n/2) so the ans is simple it is because ... we make sure that maxCount will store the maximum count of any number.. and question is saying that there will be one element which is majority element . instead of maxCount we can write a if condition like if count > math.florr(n/2) then return arr[i] this is our majority element.
 */

let arr = [2, 2, 1, 1, 1,1, 2,1, 2];
function majorityElementBruteForce(arr) {
    let maxCount = null;
    let element = null;
    for (let i = 0; i < arr.length; i++){
        let count = 0;
        for (let j = 0; j < arr.length; j++){
            if (i === j) {
                continue;
            }
            if (arr[i] === arr[j]) {
                count++;
            }
        }
        if (maxCount < count) {
            maxCount = count;
            element = arr[i];
        }
    }
    return { element: element, count: maxCount };
}
console.log(majorityElementBruteForce(arr));

function majorityElementBruteForce1(arr) {
    console.log("---- arr", arr);
    for (let i = 0; i < arr.length; i++){
        let count = 0;
        for (let j = 0; j < arr.length; j++){
        
            if (arr[i] === arr[j]) {
                count++;
            }
        }
        // console.log("count ", count);
        if (count > Math.floor(arr.length / 2)) {
            return arr[i];
        }
    }
    return -1;
}
console.log("majority element " , majorityElementBruteForce1(arr));

// 1,1,1,2,2,2
//! (2) sorting ...
/**
 * the approach is simple .. first we will sort the array and then run a single loop and at any point ot time if arr[i] !=arr[i-1] then just stop the count  and check max count and start the new element count ... 
 * 
 * here count variable is started with 0 that means for the first element we considred its count as 0 and increasing count by 1 when that samele element appear again.
 */

function majorityElementSorting(arr) {
    arr.sort();
    console.log(arr);
    let maxCount = -1;
    let element = -1;
    let count = 0;
    for (let i = 0; i < arr.length-1; i++){
        if (arr[i] !== arr[i + 1]) {
            if (maxCount < count) {
                maxCount = count;
                element = arr[i];
                count = 0;
            }
        } else {
            count++;
        }
    }
    if (maxCount < count) {
        maxCount = count;
        element = arr[arr.length-1];
    }
    return { element: element, count: maxCount };
}
console.log("majority element sorting : ", majorityElementSorting(arr));

// time complexity of this code is O(n log n) adn space complexity is O(1)


//! (3) using hasmap..
/**
 * approach is simple if elment is not in map then store it with count 1 .. if we found it agian then increase its count once the loop finished then run a for loop and check if map.get(Key) which will give count if it is greater then n/2 then that is our ans..
 */
let arr1 = [2, 2, 1, 1, 1, 2, 2,1,1];

function majorityElelementHashMap(arr) {
    let map = new Map();
    for (let i = 0; i < arr.length; i++){
        if (map.has(arr[i])) {
            // console.log(map.get(arr[i]));
            let value = map.get(arr[i]) + 1;
            map.set(arr[i], value);
        } else {
            map.set(arr[i], 1);
        }
    }
    console.log(map);
    // for (let i = 0; i < arr.length; i++){
    //     if (map.get(arr[i]) > Math.floor(arr.length / 2)) {
    //         return arr[i];
    //     }
    // }
    for (let item of map) {
        console.log("item of map", item);
        if (item[1] > Math.floor(arr.length / 2)) {
            return item[0];
        }
    }
}
console.log(majorityElelementHashMap(arr1));


//! (4) most optimal solution ....

// using moores voting algorithm
/**
 * the approach is simple 
    ** step 1 => first take the count=0 and current element varible .. the algo says that if count is 0 then element is arr[i] and increase the count by 1 or directly set count =1 
    *?  step 2 => check else if element === arr[i] or not if yes then increase the count else decrease the count 
 */

let arr2 = [7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5];
function majorityElelementMooresVotingAlgo(arr) {
    let count = 0;
    let element;
    for (let i = 0; i < arr.length; i++){
        if (count === 0) {
            element = arr[i];
            count = 1;
        } else if (element === arr[i]) {
            count++;
        } else if (element !== arr[i]) {
            count--;
        }
    }
    return element;
}
console.log("majority element using Moorse Vooting algorithm ", majorityElelementMooresVotingAlgo(arr2));