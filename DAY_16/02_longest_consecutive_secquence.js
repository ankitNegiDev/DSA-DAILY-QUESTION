// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// what is secquence -> a sequence refer to a set of numbers that appear consecutively in increasing order like [1, 2, 3, 4]. The main point of the problem is to find the longest consecutive sequence meaning numbers that appear in order without gaps.

// what is subsecquence -> A subsequence is a derived sequence from an original sequence . where some or no elements are removed without changing the order.
/**
[1, 2, 3, 4] (full sequence is also a subsequence)
[2,3,4] (1 removed)
[1, 3, 4]  (removed 2)
[2, 3]     (removed 1 and 4)
[1, 2, 4]  (removed 3)
[] (empty sequence is a valid subsequence)
 */

// we need to find logest consecutive sequence..

//! bruteforce approach .. 
/**
 * the approach is simple .. 
 * stpe 1 => run a first loop pick the first element -> take length of logest consecutive sequeice is 1 then do a +1 in current element and run a second loop to chck if this exist or not .. if yes then repeat this ... until it is a valid sequence and update length... if not then move to next element.. and do same thing..
 */
// let arr = [100, 4, 200, 1, 3, 2];
// let arr = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1];
// let arr = [1, 0, 1, 2];
// let arr = [1, 0, 1, 2];
// let arr= [1, 0, 1, 2, 3];
// let arr = [1, 2, 3, 4, 2];
// let arr = [2, 1, 3, 4]; // 4
// let arr = [1, 2, 2, 3, 4]; // 4
// let arr = [4, 2, 1, 3];  //! for this test case the bruteforce code breaks..  check why the j is not intialzing with 0 when the current element after first update is found at the last index... ??
// [1, 2, 3, 10, 11, 12];
// arr = [-2, -1, 0, 1, 2];
// arr = [1, 2, 3, 1, 2, 6, 7, 8];

function longestConsecutiveSecquence(arr){
    let maxLength=-Infinity;
    for(let i=0; i<arr.length; i++){
        let currentElement=arr[i];
        console.log("current element started : ",currentElement);
        let lenght=1;
        currentElement++;
        for(let j=0; j<arr.length; j++){
            if(currentElement===arr[j]){
                console.log("current element is  after one update inside if: ",currentElement);
                currentElement++;
                console.log("current element after 2nd updation inside if is : ",currentElement);
                lenght++;
                console.log("--------- length:",lenght);
                j=0;
            }
            // console.log("------value of j :",j);
        }
        console.log("----------ut side loopppp and current element ",currentElement);
        if(maxLength<lenght){
            maxLength=lenght;
        }

    }
    return maxLength;
}
// console.log(longestConsecutiveSecquence(arr));

// let arr1 = [100, 4, 200, 1, 3, 2];

function search(arr,target){
    for(let i=0; i<arr.length; i++){
        if(arr[i]===target){
            return true;
        }
    }
    return false;
}

function bruteforce1(arr){
    let maxLength=-Infinity;
    for(let i=0; i<arr.length; i++){
        let currentElement=arr[i];
        let lenght = 1;
        while(search(arr,currentElement+1)){
            // console.log("inside while");
            currentElement++
            lenght++;
        }
        if(maxLength<lenght){
            maxLength=lenght;
        }
    }
    return maxLength;
}
console.log(bruteforce1(arr));

// check its optimal solution on the rev time ...