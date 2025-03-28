let arr = [1, 2, 3];
let map = new Map();
let result = [];
let index = 0;
let temp = [];

function generatePermutations(arr, map, result, index,temp) {
    // step 1 =>  base case ..
    if (temp.length === arr.length) {
        // console.log("temp is : ", temp);
        // result.push([...temp]);
        // console.log("result is : ", result);
        // console.log([...map.keys()]);
        result.push([...map.keys()]);
        /**
         * no need to pass the extra array temp ... as we are storing the values in the map...
         */
        return;
    }

    for (let i = 0; i < arr.length; i++){
        if (map.has(arr[i])) {
            // agar he to kuch mat kar age jaa..
            continue;
        } else if (!map.has(arr[i])) {
            // agar nah hae to add kar na map ma , temp mae add .
            map.set(arr[i], index);
            temp.push(arr[i]);

            // step 2 =>  recursive call...
            generatePermutations(arr, map, result, index + 1, temp);

            // step 3 => backtracking..
            map.delete(arr[i]);
            temp.pop();
        }
    }
    // console.log("result before return : ", result);
    return result;
}
console.log("result is " ,generatePermutations(arr, map, result, index, temp));

console.log("\n\n----------- modified--------------\n");

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



// a more optimized way would be ... doing inplace instead of using the map...

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