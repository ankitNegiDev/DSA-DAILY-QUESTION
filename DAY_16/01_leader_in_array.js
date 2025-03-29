// You are given an array arr of positive integers.Your task is to find all the leaders in the array.An element is considered a leader if it is greater than or equal to all elements to its right.The rightmost element is always a leader

// Input: arr = [16, 17, 4, 3, 5, 2]
// Output: [17, 5, 2]
// Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2


//! Bruteforce approach .. 
let arr=[16,17,4,3,5,2];
function leaderInArray(arr){
    let result=[];
    let isLeader;
    for(let i=0; i<arr.length-1; i++){
        isLeader=true;
        for(let j=i+1; j<arr.length; j++){
            if(arr[i]<arr[j]){
                isLeader=false;
            }
        }
        if(isLeader){
            result.push(arr[i]);
        }
    }
    result.push(arr[arr.length-1]); // last element is always leader since no elmeent is in its right
    return result;
}
console.log("leader in array are : ",leaderInArray(arr));

console.log("----- approach 2 : two pointer \n\n");


//! (2) approach 2 using two pointer .. 
/**
 * the approach is simple ... move the right if it is === length then push it in result then reinitialize right with left +1 ..
 */

let arr1 = [10, 9, 8, 7]
// let arr1 = [5, 5, 5, 5];
// let arr1 = [3];
function leaderInArrayTwoPointer(arr){
    let left=0;
    let right=1;
    let result=[];
    while(left<arr.length){
        if(arr[left]<arr[right]){
            left++;
            right=left;
            right++;
        }else if (arr[left]>=arr[right]){
            right++;
        }
        if(right===arr.length){
            result.push(arr[left]);
            left++;
            right=left;
            if(right!==arr.length-1){
                right++;
            }else{
                result.push(arr[left]);
                left++;
            }
        }
    }
    return result;
}
console.log("leader in array Two pointer : ",leaderInArrayTwoPointer(arr1));
/**
 * currently the problem is we are moving right to lenght and then agian reinitializing it ... which cause the o(n*n) in worst case if it is like [100 , 90,20]; then for 100 right has to move to length of array, same for 90 ..
 */

// optimizing the two pointer .....
/**
 * in this time lets move from the last and we know that last element is a leader always 
 ** step 1 => take left and right varible and result array. initialize left with arr.length-2, and right iwth arr.length-1;
 ** step 2 => run a while loop unitila left is not 0.
 ** step 3 => if(arr[left]>=arr[right]) that means this is the case where we need to push the last element... but assume array length is 6 so left is on 4 and right is on 5 so if this condition is true we push last element which is result.push(arr[right]) but just think when we will push arr[left] because it is greater the arr[right]... if we do push two time like this 
    * if(arr[lft] > arr[righ]){
        result.push(arr[righ]);
        right=i;
        result.;push(arr[righ]);
    }
    for the first time it will push 2 , 5 in the result array but next time when 17>arr[righ] whisi is 5 at this time it will push 5 again and then 17 but we did not want this ... 
 ** step 3 .... updated.. put the last element into the result before entering into the loop then check for arr[left]>arr[righ] if yes then do right = i and push arr[righ] in the result and after if condion do left -- for reverse traversal.
 */

// approach for revesion ---> take left = arr.length-2 and right=arr.elng-1 and put last element in the result. now compare arr[lft]>arr[righ] agar current arr[left] is greater then arr[right] it means it is leader if not that means it is not. then left -- and same until left >=0

function twoPointerOptimize(arr){
    let left=arr.length-2;
    let right=arr.length-1;
    let result=[arr[right]];
    // console.log(result);
    while(left>=0){
        /**
         * why the >= sign because a leader is greater then or equal to element on its right. and think of this test case [5,5,5,5] when all element are same.
         */
        if(arr[left]>=arr[right]){
            right=left;
            result.push(arr[right]);
        }
        left--;
    }
    console.log("result before reverse : ",result);
    /*
    for(let i=0; i<Math.floor(result.length/2); i++){
        let temp=result[i];
        result[i]=result[result.length-1-i];
        result[result.length-1-i]=temp;
    }
    */
    // using two pointer to reverse .. 
    left=0;
    right=result.length-1;
    while(left<right){
        // console.log(left);
        let temp=result[left];
        result[left]=result[right];
        result[right]=temp;
        left++,right--
    }
    console.log("resutl after reverse : ",result);
    // result.reverse();
    return result;
}
console.log("optimize two pointer :",twoPointerOptimize(arr));


// can we use map or set here ?? 
/**
 * set no ..because of duplicates...
 * map ? no - no use case here 
 */