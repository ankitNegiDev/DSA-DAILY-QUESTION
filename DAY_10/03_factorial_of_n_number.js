// find the facturial of the n natural number.


function factorial(n) {
    if (n <= 1) {
        return 1;
    }
    let fact = n * factorial(n - 1);
    return fact;
}
console.log(factorial(5));

/**
 * 5*factorial(5-1) -> 4*factorial(4-1)  -----> 3*factorial(3-1) ----> 2*factorial(2-1) ----> base case hit return 1
 * 120 <---- 5*24   <------   4*6         <-----      3 *2       <------     2*1    <----- return 1
 */

// using for loop ... 
function factorialLoop(n) {
    let fact = 1;
    for (let i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}
console.log(factorialLoop(5));