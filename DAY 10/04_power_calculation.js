// calculate the powr...
// calculate linear power calculaton ..
// x is whose power we want to calculate , what power we want to calculate is n. 2, 3  2*2*2
function power(x, n) {
    if (n <= 3) {
        return x * x * x;
    }
    let product = x * power(x, n - 1);  // x* power(x (power n-1))
    return product;
}
console.log(power(2, 4));



// logrithmic


// or i can do if (n<=0) {reeturn 1}

function powerLog(x, n) {
    let power;
    // base case ...
    if (n === 1) {
        return x;
    }

    if (n % 2 === 0) {
        let ans = powerLog(x, Math.floor(n / 2));
        power = ans * ans;
    } else {
        let ans = powerLog(x, Math.floor(n / 2));
        power = ans * ans * x;
    }
    return power;
}
console.log(powerLog(2, 5));