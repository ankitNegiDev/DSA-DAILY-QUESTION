# LEARNING OF DAY 1.

### (1) how to rotate array in left side

-   _to rotate array in left side we need to do shifting of array elements in the left side._
-   **we need to pick always arr[0] element and then shift all the remaining element in left side and then at last put the arr[0] elment at last.**
-   _the total no of rotation are valid upto from 0 to arr.length-1._
-   _if we rotate array upto arr.length then it will become the same array as it was originally so array.length + 1 rotation will count as the first rotation since array already does one rotation cycle completely_

    ```js
    let arr = [10, 20, 30, 40, 50];

    function leftRotate(arr, rotationTime) {
        while (rotationTime) {
            let temp = leftShift(arr);
            arr[arr.length - 1] = temp;
            rotationTime--;
        }
    }

    function leftShift(arr) {
        let firstElement = arr[0];
        for (let i = 0; i < arr.length-1; i++){

            arr[i] = arr[i+1];
        }
        return firstElement;
    }
    leftRotate(arr, 5);
    console.log(arr);

    <!-- output  -->
    [ 20, 30, 40, 50, 10 ]  // when rotated 1 times
    [ 30, 40, 50, 10, 20 ]  // when rotated 2 times
    [ 40, 50, 10, 20, 30 ]  // when rotated 3 times
    [ 50, 10, 20, 30, 40 ]  // when rotated 4 times
    [ 10, 20, 30, 40, 50 ]  // when rotated array.length times same original array.
    ```

---

### (2) how to rotate array elements in the right side.

-   _to rotate array in right side we need to do shifting of array elements in the right side._
-   **we need to pick always arr[arr.length-1] element and then shift all the remaining element in right side and then at last put the arr[arr.length-1] elment at first.**
-   _the total no of rotation are valid upto from 0 to arr.length-1._
-   _if we rotate array upto arr.length then it will become the same array as it was originally so array.length + 1 rotation will count as the first rotation since array already does one rotation cycle completely_

    ```js
    function rightRotate(arr, rotationTime) {
        while (rotationTime) {
            let temp = rightShift(arr);
            arr[0] = temp;
            rotationTime--;
        }
    }
    function rightShift(arr) {
        let lastElement = arr[arr.length - 1];
        for (let i = arr.length - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        return lastElement;
    }
    rightRotate(arr, 2);
    console.log(arr);

    <!-- output -->
    [ 50, 10, 20, 30, 40 ]  // when rotated 1 time
    [ 40, 50, 10, 20, 30 ]  // when rotated 2 time
    [ 30, 40, 50, 10, 20 ]  // when rotated 3 time
    [ 20, 30, 40, 50, 10 ]  // when rotated 4 time
    [ 10, 20, 30, 40, 50 ]  // when rotated 5 time
    ```

### (3) whay for of loop is not applicable on the normal javascript object where as for of loop is applicable on the map.keys()

-   _map.keys() does not return the normal javascript object. it might looks like object but it is not a normal javascript object._

-   **map.keys() returns a Map Iterator Object — not a regular object.**

## Iterator And Generator Concept

```js
// taking an example of array ....

// lets assume we want to access the array elements one by one ... or some element at once ... then after some time we again access some elements of array etc..

// imperative way ..
let arr = [1, 2, 3, 4, 5];
for (let i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}
console.log("\n\n");
function fetchNextElement(arr) {
    // let index=-1;
    let index = 0;
    function nextElement() {
        // index accessible because of closure.
        if (index < arr.length) {
            // index++;
            // return arr[index];
            let element = arr[index];
            index++;
            return { value: element, done: false };
        } else {
            return { value: undefined, done: true };
        }
    }

    return nextElement;
}
let nextElement = fetchNextElement(arr);
console.log(nextElement());
// some other task...
console.log(nextElement());
// some other task....
console.log(nextElement());
console.log(nextElement());
// some other task ....
console.log(nextElement());
console.log(nextElement());
console.log("\n\n");

//! now the problem in the imperative way is that it does not solve this problem of acessing array elments like we access first element once and then after some other task we can't again acess the first element ... it is like we can access first element at one time at any place of code..

// (2) creating a iterator function that fetch element from end to start
function fetchElementFromLastToFirst(arr) {
    let index = arr.length - 1;
    return function next() {
        if (index >= 0) {
            let element = arr[index];
            index--;
            return { value: element, done: false };
        } else {
            return { value: undefined, done: true };
        }
    };
}
let elementFromLastToFirst = fetchElementFromLastToFirst(arr);
console.log(elementFromLastToFirst()); // 5
console.log(elementFromLastToFirst()); // 4
console.log(elementFromLastToFirst()); // 3
console.log(elementFromLastToFirst()); // 2
console.log(elementFromLastToFirst()); // 1
console.log(elementFromLastToFirst()); // undefined
console.log(elementFromLastToFirst()); // undefined.
console.log("\n\n");

// (3) creating a iterator function that fetch element from start to end but with jump of 2|3 etc.
function fetchElementFromFirstToLastWithJump(arr, jump) {
    let index = 0;
    return function nextElement() {
        if (index < arr.length) {
            let element = arr[index];
            index += jump;
            return { value: element, done: false };
        } else {
            return { value: undefined, done: true };
        }
    };
}
let elementFromFirstToLastWithJump = fetchElementFromFirstToLastWithJump(
    arr,
    2
);
console.log(elementFromFirstToLastWithJump());
console.log(elementFromFirstToLastWithJump());
console.log(elementFromFirstToLastWithJump());
console.log(elementFromFirstToLastWithJump());

console.log("\n\n");

// (4) creating a iterator function that fetch element from end to start but with some jump..
function fetchElementFromLastToFirstWithJump(arr, jump) {
    let index = arr.length - 1;
    return function nextElement() {
        if (index >= 0) {
            let element = arr[index];
            index -= jump;
            return { value: element, done: false };
        } else {
            return { value: undefined, done: true };
        }
    };
}
let elementFromLastToFirstWithJump = fetchElementFromLastToFirstWithJump(
    arr,
    2
);
console.log(elementFromLastToFirstWithJump());
console.log(elementFromLastToFirstWithJump());
console.log(elementFromLastToFirstWithJump());
console.log(elementFromLastToFirstWithJump());

console.log("\n\n");

console.log("-----5------");
// (5) creating a iterator function that fetch element from a range like we give the range and our function fetch elements from with that range.. .( case 1 when last index is exclusive)..

function fetchElementRange(arr, start, end) {
    return function next() {
        if (start <= end) {
            let element = arr[start];
            start++;
            return { value: element, done: false };
        } else {
            return { value: undefined, done: true };
        }
    };
}
// let rangeElement=fetchElementRange(arr,0,3);
// console.log(rangeElement());
// console.log(rangeElement());
// console.log(rangeElement());
// console.log(rangeElement());
// console.log(rangeElement());

// modified version that when we pass the range then it fetch that element at once...
function fetchElementRange(arr, start, end) {
    let result = [];
    while (start <= end) {
        let element = arr[start];
        start++;
        result.push(element);
    }
    if (start > end) {
        return result;
    } else {
        return undefined;
    }
}
console.log(fetchElementRange(arr, 1, 3));

// but in js we have inbuilt iterator  to fetch the array element ...

let it = arr[Symbol.iterator]();
console.log(it.next());
console.log(it.next());
console.log(it.next());
console.log(it.next());
console.log(it.next());
console.log(it.next());
console.log(it.next());

// imperative way ..
// let arr=[1,2,3,4,5];
// for(let i=0; i<arr.length; i++){
//     console.log(arr[i]);
// }
// console.log("\n\n");
// function fetchNextElement(arr){
//     // let index=-1;
//     let index=0;
//     function nextElement(){
//         // index accessible because of closure.
//         if(index<arr.length){
//             // index++;
//             // return arr[index];
//             let element=arr[index];
//             index++;
//             return {value:element,done:false};
//         }else{
//             return {value:undefined, done:true};
//         }
//     }

//     return nextElement;
// }
// let nextElement=fetchNextElement(arr);
// console.log(nextElement());
// // some other task...
// console.log(nextElement());
// // some other task....
// console.log(nextElement());
// console.log(nextElement());
// // some other task ....
// console.log(nextElement());
// console.log(nextElement());
// console.log("\n\n");
/**
 * now to make the above imperative code to a declarative code we use generator functions...
 */
```

### generator concept

-   genrator function are different then normal functions.
-   inside generator function we have special keyword which is called yield.
-   generator function will not work or behave like noraml funciton in normal function when we call the function it execute but in generator function when we call it wont execute.
-   **generator function return iterator and this iterator have a function called next.**
-   **_generator function return the generator object whcih has iterator capability._**
-   **_✔ Generator functions return generator objects, NOT just plane iterators._**
-   **✔ Generator objects have iterator capabilities (they implement [Symbol.iterator]).**

-   when first time we called it.next() then it will execute the myGenerator () function upto that point when it does not encounter yield keyword .. when it encounter yield keyowrd it return that yield value and control moves out of generator function which means its entry from callstack will be removed.. and next time when we do it.next() either immediately or after some line of code then control will again move inside the myGenerator() function and it will execute all the line of code just below the previous yield to next incoming yield... and when it hit 2nd yield it will return that yield value and control moves out of generator functions... same process goes on doing it.next() until we reached to last yield keyword. and once the last yield value is retured then if we do it.next() then it will return value undefined and done true... so until done is false that means there are some more value inside the myGenerator function and when done is true that means no values left inside the generator functions..
-   done will be true only when we do iterator.next() after last yielded value.

```js
// example of generator function ...

function* myGenerator() {
    console.log("hello i am generator function");
    yield 100;
    console.log("value after 100 inside generator function ");
    yield 200;
}
let it = myGenerator();
console.log(it.next());
console.log("out side the myGeneraotor fauncitono");
console.log(it.next());
console.log("out side the myGeneraotor fauncitono");

console.log(it.next());
console.log("end");
console.log("\n\n");

// fetching values from the array ...
let arr = [100, 200, 300, 400];
function* gen(arr) {
    console.log("inside generator function");
    for (let i = 0; i < arr.length; i++) {
        yield arr[i];
    }
}
let iterator = gen(arr);
console.log(iterator.next());
console.log("outside generator function");
console.log(iterator.next());
console.log("outside generator function");

console.log(iterator.next());
console.log("outside generator function");

console.log(iterator.next());
console.log("outside generator function");

console.log(iterator.next());

console.log("end");

console.log("\n\n");

//? the it.next() can also take one parameter ...

function* genn() {
    console.log("inside generator fun");
    const x = yield 10; // x will have 30 here when we do i.next() second time..
    const y = x + 30;
    yield y;
}
let i = genn();
console.log(i.next());
console.log("outside the genn funct");
console.log(i.next(30));
console.log("outside gnerator func");
console.log(i.next());
```

-   if we write return and after return we write yield then as we know all the code below the return is a code that is never going to be accessed or never going to be execute...

#### difference b/w iterator and generator

-   iterator is a object which gives us a next function using which we can get the done and value property
-   on the other generator is a fucntion which can pause its execution momentarily and along with it also have iterator capibilities..

#### the Async and await behind the scene uses the iterator and generator function concept.
