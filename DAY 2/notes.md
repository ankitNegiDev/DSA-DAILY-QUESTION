# learning of the day

### what is difference b/w nums[...rotatedArray] and a for loop copy

* the main difference is when we pass the array to a function then we are just passing the reference of that array to a parameter of function. so whatever changes are done in nums will be only avilable inside the function outside function the nums will still point to the original array. because we are assining the new reference into the nums by creating [...rotatedArray] a new array. means now nums will point to this new array inside the function.
* But on the other hand if we apply a for loop and put value at each index of nums array then we are techinically accessing each memory block of array and assigining value to it which ultimately changes or modify the original one..

    ```js
        console.log(rotatedArray);
        return rotatedArray; // question says we need to do in-place...
        nums=[...rotatedArray];
        console.log(nums);
        return nums;
        for (let i = 0; i < nums.length; i++) {
            nums[i] = rotatedArray[i];
        }
    ```
* for deep and shallow copy refer notes.