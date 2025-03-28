# Generate permutations

* for this we have two approach.

* ## using Map or extra space.

    ```js
    function generatePermutations1(arr, map, result, index) {
        // base case ..
        if (map.size === arr.length) {
            result.push([...map.keys()]); // map return an iterable and similarly .keys() also return iterable and we can use spread on iterable.
            return;
        }

        for (let i = 0; i < arr.length; i++){
            if (map.has(arr[i])) {
                continue;
            } else if (!map.has(arr[i])) {
                map.set(arr[i], index);

                // recursive call..
                generatePermutations1(arr, map, result, index + 1);

                // backtracking..
                map.delete(arr[i]);
            }
        }
        return result;
    }
    let map1 = new Map();
    let result1 = [];
    console.log(generatePermutations1(arr, map1, result1, index));
    ```

* ## Dry run or recursion tree

  * ![generate permutation map](../00_IMAGES/dry%20run%20of%20generate%20permutations%20map.jpg)

* ## inplace or using swapping or without extra space

    ```js
    let arr1 = [1, 2, 3];
    let result2 = [];

    function getPermutationsOptimizeInplace(arr, result,index) {
        // base case 
        if (index === arr.length) {
            result.push([...arr]);
            // result.push(arr);
        }

        for (let i = index; i < arr.length; i++){
            // swapping the i with index.
            let temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;

            // recursive call..
            getPermutationsOptimizeInplace(arr, result, index + 1);

            // backtracking..
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
        return result;
    }
    console.log("---------\n\n optimize one \n\n");
    console.log(getPermutationsOptimizeInplace(arr1, result2, 0));
    ```

* ## Dry run of inplace

* ![generate permutation in place](../00_IMAGES/dry%20run%20of%20inplace%20generate%20permutation%20swapping.jpg)

---
