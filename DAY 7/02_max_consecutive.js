//  Q 2 => Given a binary array nums, return the maximum number of consecutive 1's in the array.

let nums = [1, 1, 0, 1, 1, 1];
function findMaxConsecutiveOnes (nums) {
    let maxLengthOne = 0;
    let length = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 1) {
            length++;
        } else {
            if (length > maxLengthOne) {
                maxLengthOne = length;
            }
            length = 0;
        }
    }
    if (length > maxLengthOne) {
        maxLengthOne = length;
    }
    return maxLengthOne;
};
console.log(findMaxConsecutiveOnes(nums));
