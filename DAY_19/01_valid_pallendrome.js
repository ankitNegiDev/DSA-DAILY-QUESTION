function isPalindrome(s) {
    // we use js regular expression here .... refer notes
    let filteredStr = s.replace(/[^a-zA-Z0-9]/g, "").toLowerCase();

    // simple two pointer..
    let left = 0, right = filteredStr.length - 1;

    while (left < right) {
        if (filteredStr[left] !== filteredStr[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// Test cases
console.log(isPalindrome("12345racecar54321"));
