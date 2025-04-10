function waysToClimb(n) {
    /*
    if(n===0 || n===1){
        return 1;
    }
    */
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return waysToClimb(n - 1) + waysToClimb(n - 2);
}

// (2) using loop .. or same concept of fibonacii..
function waysToClimbFibo(n) {
    if (n === 1) return 1;
    let one = 1;
    let two = 2;
    let next;

    for (let i = 3; i <= n; i++) {
        next = one + two;
        one = two;
        two = next;
    }

    return two;
}

// (3) using formula
function waysToClimbMaths(n) {
    let root5 = Math.sqrt(5);
    // phi is also called Golden Ratio
    let phi = (1 + root5) / 2;
    let psi = (1 - root5) / 2;

    // We need the (n+1)  Fibonacci number
    const k = n + 1;
    // using ** exponentiaon operator
    const ways = (phi ** k - psi ** k) / root5;

    return Math.round(ways);
}

// check for dp . on rev time









