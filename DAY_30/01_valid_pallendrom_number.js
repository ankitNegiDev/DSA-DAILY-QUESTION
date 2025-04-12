// solution => https://leetcode.com/problems/palindrome-number/submissions/1604628220/

// Q => https://leetcode.com/problems/palindrome-number/description/

function validPallendromNumber(num){
    let originalNum=num;
    let reverseNum=0;
    while(num!==0){
        let digit=num%10;
        reverseNum=reverseNum*10+digit;
        num=Math.floor(num/10);
    }
    if(originalNum===reverseNum){
        return true;
    }else{
        return false;
    }
}
console.log(validPallendromNumber(121));
console.log(validPallendromNumber(123));
