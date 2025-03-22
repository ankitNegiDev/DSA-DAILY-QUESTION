// Q 3 => Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


// creating a 2d array ...
let n = 5; 
// let arr = new Array(n).fill(0);
// for (let i = 0; i < n; i++){
//     arr[i] = new Array(n).fill(0);
// }
// console.log(arr);
// let arr = [[1, 2, 3, 4, 5], [1, 2, 3, 4, 5], [1, 2, 3, 4, 5], [1, 2, 3, 4, 5], [1, 2, 3, 4, 5]];
let arr = [];

function generatePascal(arr, n) {
    for (let i = 0; i < n; i++){
        arr[i] = [];
        for (let j = 0; j <= i; j++){
            if (j === 0) {
                arr[i][j] = 1;
            } else if (i === j) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]; // sum of previous two.
            }
        }
        console.log(arr[i].join(" "));
    }
    return arr;
}
console.log("\n\n", generatePascal(arr, n));

/*
    0    1
    1    1 1
    2    1 2 1
    3    1 3 3 1
    4    1 4 6 4 1
 */

/**
 * for this pascal triangle .. if we see the first colum then value 1 so we can say that when j==1 then put 1.
 * second condition .. at last when i===j then we can put -1
 * third condtion --- sum of above two ... so we need to just figure out how to make previous two to add .. just assume i = 3, j=1  the arr[i-1][j-1] is nothing but arr[2][0] which is 1 and + arr[i-1][j] which is arr[2][1] nothing but 2 so 2+1 is 3 that's why we got arr[3][1] is 3...
 */
