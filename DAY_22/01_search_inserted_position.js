// Given a sorted array of distinct integers and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

let arr = [1, 3, 5, 6];
let target = 5;

//! (1) Bruteforce approach..
function searchInsertedPosition(arr,target){
    let insertedPosition=-1;
    for(let i=0; i<arr.length; i++){
        if(arr[i]<=target){
            insertedPosition=i;
        }
    }
    return insertedPosition;
}
console.log("the inserted position of target : ",target," is : ",searchInsertedPosition(arr,target));

//! (2) using binary search ..
let arr1=[1,3,5,6];
let target1=0;
function searchInsertedPositionBinarySearch(arr,target){
    let left=0;
    let right=arr.length-1;
    let insertedPosition=-1;
    while(left<=right){
        let mid=Math.floor((left+right)/2);
        if(arr[mid]===target){
            return mid+1;
        }
        else if(arr[mid]<target){
            insertedPosition=mid+1;
            left=mid+1;
        }else if(arr[mid]>target){
            right=mid-1;
        }
    }
    // return insertedPosition;
    if(insertedPosition===-1){
        return 0;
    }else{
        return insertedPosition;
    }
}
console.log("the inserted position of target : ", target, " is : ", searchInsertedPositionBinarySearch(arr1, target1));
