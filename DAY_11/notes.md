# Learnings of the day

## find() method

* **syntax => `arrayName.find(callback(currentElement,index,array),thisArg){...code...}`**

  * **Parameters:**

    ***1. callback (required):*** 
    * function that is executed on each element in the array until it finds an element where the function returns true. The function can take the following arguments:

    ***2. element:***
    * The current element being processed in the array.

    ***3. index (optional):***
    * The index of the current element being processed.

    ***4. array (optional):***
    * The array find was called upon.

    ***5. thisArg (optional):***
    * Value to use as this when executing the callback function.

  * **Return Value:**
    * it return the first matching element that satisfied the condition.
    * Returns the first element in the array that satisfies the provided testing function.
    * Returns undefined if no elements satisfy the condition.

  ```js
    let arr=[0,10,20,30];
    function callback(element,index,arr){
        console.log(`the element ${element} at index ${index} in array ${arr}`);
        return 100;
    }
    let findResult=arr.find(callback);
    console.log("the value of find result is ",findResult);
    <!-- output  -->
    <!-- the element 0 at index 0 in array 0,10,20,30 
         the value of find result is  0    -->
  ```

* it proves that `find() function` will always return the first element based on the condition weather we return something or not.. if it does not found then it will return undefind.

  ```js
    let arr=[0,10,20,30];
    function callback(element,index,arr){
        console.log(`the element ${element} at index ${index} in array ${arr}`);
        if(element>10){
            console.log("first elemnt greater then 10 is ",element);
            return 10000;
        }
    }
    let findResult=arr.find(callback);
    console.log("the value of find result is ",findResult);
    /*
    output =>
    the element 0 at index 0 in array 0,10,20,30
    the element 10 at index 1 in array 0,10,20,30
    the element 20 at index 2 in array 0,10,20,30
    first elemnt greater then 10 is  20
    the value of find result is  20
    */
  ```

* this also proves that find will return the first mathching element that's it if there are more then then it doesn't care at all.
