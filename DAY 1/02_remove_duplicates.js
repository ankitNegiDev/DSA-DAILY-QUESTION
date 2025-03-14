let arr = [0, 0, 10, 10, 10, 20, 20, 30, 30, 40];
//! (1) brute force approach .....
function removeDuplicate(arr) {
    let count = 0;
    let index = 0;
    for (let i = 0; i < arr.length; i++){
        console.log("----- i", i);
        if (arr[i] === arr[i - 1]) {
            console.log("continumeee or if block");
            console.log("i-- inside if block ", i);
            continue;
        } else {
            console.log("else block");
            for (let j = i; j < arr.length; j++){
                if (arr[i] === arr[j]) {
                    count++;
                }
            }
        }
        arr[index] = arr[i];
        index++;
        console.log("arr in i th iteration and index", arr, i,index);
    }
    console.log(arr);
    console.log("index is ", index);
}
// removeDuplicate(arr);

//! modifyied approach ..............
function removeDuplicateModify(arr) {
    let index = 0;
    for (let i = 0; i < arr.length-1; i++){
        if (arr[i] !== arr[i + 1]) {
            arr[index] = arr[i];
            index++;
        }
    }
    arr[index] = arr[arr.length - 1];
    index++;
    console.log(arr);
    console.log("index", index);
}
// removeDuplicateModify(arr);


//! second solution is using set... why not map we can use no problem..

function removeDuplicateSet(arr) {
    let set = new Set();
    // putting the unique element into the set
    for (let i = 0; i < arr.length; i++){
        set.add(arr[i]);
    }

    console.log(set);

    // putting unique element back to the array.
    let index = 0;
    for (item of set) {
        // console.log(item);
        arr[index] = item;
        index++;
    }
    console.log(arr);
    console.log("index ", index);
}
// removeDuplicateSet(arr);



//! using map .....................
function removeDuplicateMap(arr) {
    let map = new Map();
    let index = 0
    for (let i = 0; i < arr.length; i++) {
        // if (map.has(arr[i])) {

        // } else {
        //     map.set(arr[i],index++);
        // }
        if (!map.has(arr[i])) { // If the value is not in the map
            map.set(arr[i], index);
            index++;
        }
    }

    for (item of [...map.keys()]) {
        arr[[...map.keys()].length - index] = item;
        // console.log(index);
        index--;
    }
    console.log(arr);
}
// removeDuplicateMap(arr);


//!  another ways ....................
function removeDuplicateMapModify(arr){
    let map = new Map();
    let index = 0;
    for (let i = 0; i < arr.length; i++) {
        if (!map.has(arr[i])) {
            map.set(arr[i], index++);
        }
    }
    index = 0;
    for (let key of map.keys()) {
        arr[index] = key;
        index++;
    }
    console.log(arr);
}
removeDuplicateMapModify(arr);
console.log("\n\n");





// //! can we use for of loop in object ??  ----> the ans is no but the map.keys() does not return the regular object...
let obj = {
    name:"bingo",
}
// for (i of obj) {
//     console.log(i);
// }
//! the above code when using for of loop on object will throw error because object is not iterable.
/*
The iterable protocol
The iterable protocol allows JavaScript objects to define or customize their iteration behavior, such as what values are looped over in a for...of construct. Some built-in types are built-in iterables with a default iteration behavior, such as Array or Map, while other types (such as Object) are not.

In order to be iterable, an object must implement the [Symbol.iterator]() method, meaning that the object (or one of the objects up its prototype chain) must have a property with a [Symbol.iterator] key which is available via constant Symbol.iterator 
*/

/**
 *? map.keys() return the iterator object and it is same as we studey in  .. advance js ... sa... fourth pillar...(iterator generator concept ... using which we immplement asynce await)...
 */

let map = new Map();
map.set("a", 1);
map.set("b", 2);
map.set("c", 3);

// Get the keys iterator
let keysIterator = map.keys();
console.log(keysIterator);  // MapIterator {}

console.log(keysIterator.next());  // { value: 'a', done: false }
console.log(keysIterator.next());  // { value: 'b', done: false }
console.log(keysIterator.next());  // { value: 'c', done: false }
console.log(keysIterator.next());  // { value: undefined, done: true }
console.log("\n\n");



//! another ways is two pointer approach ...

function removeDuplicateOPtimalSol(arr) {

    let left = 0, right = 1;
    while (right < arr.length) {
        // console.log("left", left);
        if (arr[left] !== arr[right]) {
            left++;
            arr[left] = arr[right];
        } else {
            right++;
        }
    }
    console.log(arr);
}
removeDuplicateOPtimalSol(arr);

