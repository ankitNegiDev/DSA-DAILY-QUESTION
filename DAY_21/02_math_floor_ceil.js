let x = 7;
let arr = [5, 6, 8, 9, 6, 5, 5]

function floorCeil(arr,x){
    let floorIndex = -1;
    let ceilIndex = -1;
    let i = 0;
    // while(arr[i]<=x || arr[i]>=x){
    while (i < arr.length) {
        if(floorIndex===-1 && ceilIndex===-1){
            floorIndex=i;
            ceilIndex=i;
        }
        if (arr[i] <= x || arr[floorIndex] <arr[i]) {
            // floorIndex = i;
            if(arr[floorIndex]===x-1){

            }else{
                floorIndex=i;
            }
        }
        // if (arr[i] >= x && arr[ceilIndex] > arr[i]) {
        // }else{
        //     ceilIndex=i;
        // }
        // ceil
        if(arr[i]>=x && arr[ceilIndex] <arr[i]){
            // ceilIndex=i;
            if(arr[ceilIndex]===x+1){

            }else{
                ceilIndex=i;
            }
        }
        i++;
    }
    return [arr[floorIndex], arr[ceilIndex]];
}
console.log(floorCeil(arr,x));

/**
 * now the problem is that ... when i run this code it give me the value which comes at last or which is less then x and comes last in array before x but when x=7 and array element has 6 and 5 but the 5 is at last index then floor should be 6 not 5 but mine cvode is giving 5... same for ceil.
 * how to fix it .......... so we can put a condition like since we know that floor of x is x-1 and ceil of x is x+1 why not to use them...
 */

// mdoified logic....
function floorCeil(arr, x) {
    let floorIndex = -1;
    let ceilIndex = -1;

    for (let i = 0; i < arr.length; i++) {
        if (arr[i] <= x) {
            // the above if condition will aloow the all smaler no then x but inner if will make sure if any number that comes earlier like if 6 comes before then floorINdex will have index of 6 and if it comes later then arr[i]>arr[floorIndx] will be false becase 6>6 is false... but if question demand like we need last occurance then we can check if arr[i]>=arr[floorINdex]...
            if (floorIndex === -1 || arr[i] > arr[floorIndex]) {
                floorIndex = i;
            }
        }

        // ceil...
        if (arr[i] >= x) {
            if (ceilIndex === -1 || arr[i] < arr[ceilIndex]) {
                ceilIndex = i;
            }
        }
    }

    // return [arr[floorIndex], arr[ceilIndex]];
    return [floorIndex, ceilIndex];

} 
console.log("floor ceil modifined : ",floorCeil(arr,x));

// but the problem is  it is having O(n) we need logn ..

//! (2) Binary search .

function findFloorAndCeil(arr, x) {
    arr.sort();
    console.log(arr);
    let left = 0;
    let right = arr.length - 1;
    let floorIndex = -1;
    let ceilIndex = -1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        if (arr[mid] === x) {
            return [mid, mid]; 
        }
        /**
         * the logic is simple if arr[mid] < x then move to the right direction in order to find the suitable floor value but the array must be sorted.
         */
        if (arr[mid] < x) {
            floorIndex = mid;  
            left = mid + 1;    
        } else {
            ceilIndex = mid;   
            right = mid - 1;  
        }
    }

    return [arr[floorIndex], arr[ceilIndex]];
}
console.log(findFloorAndCeil(arr,x));

// problemative cod on gfg ...... check it .. 
//{ Driver Code Starts
// Initial Template for javascript
// Position this line where user code will be pasted.
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => { inputString += inputStdin; });

process.stdin.on('end', _ => {
    inputString =
        inputString.trim().split('\n').map(string => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

function main() {
    let t = parseInt(readLine());
    for (let i = 0; i < t; i++) {
        let x = parseInt(readLine());
        let input_line = readLine().split(' ');
        let arr = input_line.map(num => parseInt(num));

        let obj = new Solution();
        let ans = obj.getFloorAndCeil(x, arr);
        console.log(ans[0], ans[1]);
        console.log("~");
    }
}

// } Driver Code Ends


// User function Template for javascript

/*
class Solution {
    getFloorAndCeil(x, arr) {
        // code here
        // arr.sort();
        arr.sort((a, b) => a - b);
        console.log(arr);
        let left = 0;
        let right = arr.length - 1;
        let floorIndex = -1;
        let ceilIndex = -1;

        while (left <= right) {
            let mid = Math.floor((left + right) / 2);

            if (arr[mid] === x) {
                return [arr[mid], arr[mid]];
            }

            if (arr[mid] < x) {
                floorIndex = mid;
                left = mid + 1;
            } else {
                ceilIndex = mid;
                right = mid - 1;
            }
        }


        if (floorIndex === -1 && ceilIndex === -1) {
            return [-1, -1];
        } else if (floorIndex === -1 && ceilIndex !== -1) {
            return [-1, arr[ceilIndex]];
        } else if (floorIndex !== -1 && ceilIndex === -1) {
            return [arr[floorIndex], -1];
        } else if (floorIndex !== -1 && ceilIndex !== -1) {
            return [arr[floorIndex], arr[ceilIndex]];
        }

    }  //what's the problem ?
}
    */
// check it rev time 