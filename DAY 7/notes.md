# when we spread obj inside the array then it gives array but why not error with set since set also return object

```js
let obj={
    fullName:"bingo",
    age:22,
}
let arr=[...obj]; //! TypeError: obj is not iterable
    at <anonymous>:5:13
console.log(arr); 

let set = new Set();
for(let i=0; i<5; i++){
    set.add(i);
}
console.log(set);
let setArray=[...set];
console.log(setArray);
```

* the main reason why this doubt comes is becasue of not knowing that set does not return the object it return then iterator object which have iterator capability where as normal object is simple object it does not have any iterator capability .
* so spreading an normal object inside the array will give the error but if we spread the iterator object inside the array then it works fine.
* to make a normal javascript object iterable object we can use inbuilt Object.entries() or Object.values() method that are present on object.

---
