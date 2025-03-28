

//! Bruteforce ...
/**
 * the approach is 
 ** stpe 1 => find or generate all the permutation.
 ** step 2 => find that permuation in the ans array which is given.
 ** step 3 => now return its next index permutation it is the our ans..
 */

// let arr = [1, 2,3];
let arr = [3, 2, 1];
// let arr=[1];
let result = [];
function generatePermutations(arr, result, index) {
    // base case ..
    if (index === arr.length) {
        // result.push([...arr].toString()); // problem is it put the , comma which i dont want..
        result.push(arr.join(""));
        return;
    }
    for (let i = index; i < arr.length; i++){
        let temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;

        // recursive call.. 
        generatePermutations(arr, result, index + 1);
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    return result;
}
// console.log(generatePermutations(arr, result, index = 0));

function findNextPermutation(arr) {
    let result = [];
    let index = 0;
    result = generatePermutations(arr, result, index);
    // console.log(result);

    // result.sort((a, b)=>{
    //     a[0] - b[0]
    // })

    // result.sort((a, b) => a.join("") > b.join("") ? 1 : -1);
    result.sort();
    console.log("result" , result);


    // now finding the current array index.. but we need to convert it into the string..
    let currentArray = arr.join("");
    // console.log(currentArray);
    // console.log(typeof currentArray);

    // now finding the index of currentArray string..
    let currentArrayIndex = result.indexOf(currentArray);
    console.log("index of current array string isn result : ", currentArrayIndex);

    // Step 4: Return the next permutation if possible
    if (currentArrayIndex < result.length - 1) {
        // console.log(typeof result[currentArrayIndex + 1]);
        // console.log(typeof result[currentArrayIndex + 1].split("")); // object (array)
        let x = result[currentArrayIndex + 1].split("");
        // console.log(Array.isArray(x));
        // console.log("type of first character or first index :  " ,typeof x[0]); // string..
        
        return result[currentArrayIndex + 1].split("").map(Number);
    } else {
        return result[0].split("").map(Number); 
    }

}

console.log("next permutation is :", findNextPermutation(arr));



// solve its optimal appraoch at rev time..