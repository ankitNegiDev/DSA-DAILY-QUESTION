class Stack {
    constructor() {
        this.item = [];
    }

    print() {
        // console.log(this.item.join(" "));
        for (let i = 0; i < this.item.length; i++) {
            console.log(this.item[i]);
        }
    }

    push(element) {
        this.item.push(element)
    }

    isEmpty() {
        if (this.item.length === 0) {
            return true;
        } else {
            return false;
        }
    }
    size() {
        return this.item.length;
    }

    pop() {
        if (this.isEmpty()) {
            return false;
        } else {
            return this.item.pop();
        }
    }

    peek() {
        if (this.isEmpty()) {
            return false;
        } else {
            return this.item[this.item.length - 1];
        }
    }
}
function largestRectangleAreaLogic(heights) {
    let n = heights.length;
    let nsl = [];
    let nsr = new Array(n);
    let stack = [];

    // NSL
    for (let i = 0; i < n; i++) {
        while (stack.length && heights[stack[stack.length - 1]] >= heights[i]) {
            stack.pop();
        }

        if (stack.length === 0) {
            nsl.push(-1);
        } else {
            nsl.push(stack[stack.length - 1]);
        }
        stack.push(i);
    }

    // Clear stack for NSR
    stack = [];

    // NSR
    for (let i = n - 1; i >= 0; i--) {
        while (stack.length && heights[stack[stack.length - 1]] >= heights[i]) {
            stack.pop();
        }

        if (stack.length === 0) {
            nsr[i] = n;
        } else {
            nsr[i] = stack[stack.length - 1];
        }
        stack.push(i);
    }

    // Calculate max area
    let maxArea = 0;
    for (let i = 0; i < n; i++) {
        let width = nsr[i] - nsl[i] - 1;
        maxArea = Math.max(maxArea, width * heights[i]);
    }

    return maxArea;
}
let heights = [2, 1, 5, 6, 2, 3]
console.log(largestRectangleAreaLogic(heights));