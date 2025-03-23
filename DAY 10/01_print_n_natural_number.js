// Q 1 -> print first n Natural number using recursion.. in both order.

function printNNaturalNumber(n) {
    if (n === 0) {
        return;
    } else {
        console.log(11 - n);
        // n--;
    }
    printNNaturalNumber(--n);
}
printNNaturalNumber(10);
console.log("\n\n");

function printNatural(i, n) {
    if (i > n) {
        return;
    } else {
        console.log(i);
    }
    printNatural(i + 1, n);
}
printNatural(1, 10);


// reverse order..
function reverse(i, n) {
    if (i > n) {
        return;
    }
    console.log(n + 1 - i);
    reverse(i + 1, n);
}
reverse(1, 4);

console.log("\n\n\n");
function reverse1(i, n) {
    if (i > n) {
        return;
    }
    reverse1(i + 1, n);
    console.log(i);
}
reverse1(1, 4);