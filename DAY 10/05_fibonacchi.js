// fibonaachiii



function fibonaachiii(n) {
    if (n === 0) {
        return 0;
    }
    if (n === 1) {
        return 1;
    }
    let sum = fibonaachiii(n - 1) + fibonaachiii(n - 2);
    return sum;
}
console.log(fibonaachiii(5));