//  ** (1) pre-order -------------> root-- -> left sub tree---->> right subtree(pre - pone)

class Node {
    constructor(incomingData) {
        this.value = incomingData;
        this.left = null;
        this.right = null;
    }


}

let rootNode = new Node(10);
let node1 = new Node(20);
let node2 = new Node(30);

rootNode.left = node1;
rootNode.right = node2;



function preorder(root) {
    if (root === null) {
        return;
    }

    console.log(root.value);
    preorder(root.left);
    preorder(root.right);
}
preorder(rootNode);

// ---------- pushing value in the array ------------

function preorder(root, result = []) {
    if (root === null) {
        return;
    }

    console.log(root.value);
    result.push(root.value);
    preorder(root.left, result);
    preorder(root.right, result);
    return result;
}
console.log("pre-order", preorder(rootNode));