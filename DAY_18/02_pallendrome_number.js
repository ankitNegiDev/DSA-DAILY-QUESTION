// pallendrome number...

//! Brute force ... 
/**
 * the approach is take the number and reverse it and then compare both if both are same then true else false..
 * any number % 10 gives us last digit...  123 %10 -> last digit is 3. 12%10 -> 2 and 1 %10 -> 1 becausee if we do modulus of any number that is smaller then the divisior then ans will be that smaller number..
 *  divisior )divident ( quotent  
            reminder.
    if the divisior is 10 and divident is 1 then modulus of 1%10 is 1..

 * any number divided by 10 gives us number without last digit. 123 /10 -> 12.
 */

function pallendromeNumber(num){
    let reverseNum=0;
    let tempNum=num; // need to preseve rthe original num
    while(tempNum!==0){
        let lastDigit=tempNum%10;
        tempNum=Math.floor(tempNum/10); // imp to take floor value ..
        // console.log("temp num:",tempNum);
        reverseNum=reverseNum*10+lastDigit;
    }
    // console.log("reverse num : ",reverseNum);
    if(reverseNum===num){
        return true;
    }else{
        return false;
    }
}
console.log(pallendromeNumber(1212));


//! 2 approach 2 -> two pointer..
function pallendromeNumberTwoPointer(num){
    let str=JSON.stringify(num);
    let left=0;
    let right=str.length-1;
    while(left<right){
        if(str[left]===str[right]){
            left++,right--;
        }else{
            break;
        }
    }
    if(left!==right){
        return false;
    }else{
        return true;
    }
}
console.log(pallendromeNumberTwoPointer(121));