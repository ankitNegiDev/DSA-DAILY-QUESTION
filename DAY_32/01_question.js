// Q -> Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// solution => https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1606612199/?envType=problem-list-v2&envId=string


// brute force approach without any pre-defined function .. 
function findFirstOccurance(haystack,needle){
    if (needle.length === 0) return 0;

    let index = -1;
    let count = 0;
    let length = needle.length;

    for (let i = 0; i < haystack.length; i++) {
        if (haystack[i] === needle[count]) {
            if (count === 0) {
                index = i;
            }
            count++;
            if (count === length) {
                return index;
            }
        } else {
            if (count > 0) {
                i = i - count;
            }
            count = 0;
            index = -1;
        }
    }

    return -1;
}
console.log(findFirstOccurance("bingolive","live"));