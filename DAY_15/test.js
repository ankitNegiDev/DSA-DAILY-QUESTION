let arr = [1, 2, 3, 4];
function test(arr) {
    arr[4] = 100;
    let tempArr = [100, 200, 399];
    arr = tempArr;
    console.log("arr in test function :", tempArr);
}
test(arr);
console.log(arr);
/**
 * here array is passed as the reference ... so any changes we do in the arr it will be refelected into the arr.
 ** assigning a new reference into a arr will not refelect any changes into the original one. but inside the test() function arr will point to the tempArr but outside it will point to original arr.
 */

let obj = {
    fullName: "bingolive",
    age:23,
}
function fun(obj) {
    obj.city = "dehradune";
    // assigning reference in obj..
    let tempObj = { name: "lloove" };
    obj = tempObj;
    console.log("obj isn fun function : ", obj);
}
fun(obj);
console.log(obj);
/**
 * here object is also passed as the refrence meaning that if we do any changes in the object inside the function will casuse changes in the original object.
 ** but if we try to assign reference then inside the fun function scope obj will point to the temp object... but outside the fun obj will point to the original object.
 */

class Node{
    constructor(incomingData) {
        this.value = incomingData;
        this.next = null;
    }
}
let head = new Node(100);

function gun(head) {
    // head.value = "i changed the value";
    // head = { name: "peter", age: 23 };
    let myObj = {
        name: "loove",
        age:23
    }
    head = myObj;
    console.log("head inside the gun function : ", head);
}
gun(head);
console.log(head);