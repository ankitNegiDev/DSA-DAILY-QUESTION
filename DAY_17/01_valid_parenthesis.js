// valid parenthesis...
/**
 * open bracket must come before closing bracket.
 * opeaning of one brack must closed by the same.
 * count of operaning is === count of clositng bracket.
 */
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


// ths is the code for validating only the "parenthesis".
function validOne(str) {
    let stack = new Stack();

    for (let i = 0; i < str.length; i++) {
        if (str[i] === "(") {
            // push into stack.
            stack.push(str[i]);
        } else if (str[i] === ")") {
            if (stack.size() !== 0) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    // console.log("size" ,stack.size());
    if (stack.isEmpty()) {
        return true;
    } else {
        return false;
    }
}
console.log("valid one ", validOne("(())"));

// this is for the "(), [], {}"

function validOne(str) {
    let stack = new Stack();

    for (let i = 0; i < str.length; i++) {
        if (str[i] === "(" || str[i] === "{" || str[i] === "[") {
            // push into stack.
            stack.push(str[i]);
        } else if (str[i] === ")") {
            if (stack.size() !== 0) {
                if (stack.peek() !== "(") {
                    return false;
                }
                stack.pop();
            } else {
                return false;
            }
        } else if (str[i] === "}") {
            if (stack.size() !== 0) {
                if (stack.peek() !== "{") {
                    return false;
                }
                stack.pop();
            } else {
                return false;
            }

        } else if (str[i] === "]") {
            if (stack.size() !== 0) {
                if (stack.peek() !== "[") {
                    return false;
                }
                stack.pop();
            } else {
                return false;
            }
        }
    }
    // console.log("size" ,stack.size());
    if (stack.isEmpty()) {
        return true;
    } else {
        return false;
    }
}



console.log("valid one ", validOne("(()){}[]"));