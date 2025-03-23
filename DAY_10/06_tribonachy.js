// Tribonachy


function Tribonachy(n) {
    if (n === 0) {
        return 0;
    }
    if (n === 1) {
        return 1;
    }
    if (n === 2) {
        return 1;
    }
    let sum = Tribonachy(n - 1) + Tribonachy(n - 2) + Tribonachy(n - 3);
    return sum;
}
console.log(Tribonachy(5));
