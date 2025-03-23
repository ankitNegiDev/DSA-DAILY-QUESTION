function sumNatural(n) {
    let sum;
    if (n === 0) {
        return 0;
    } else {
        // sum = n + sumNatural(--n);
        sum = n + sumNatural(n - 1);
    }
    return sum;
}
console.log(sumNatural(10));
