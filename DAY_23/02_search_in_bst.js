// all element of left sub tree < root and root is less < right subtree nodes.
// left subtree nodes value is less then root and root is less then right sub tree value.

// inorder traversal of bst is sorted.


class Node {
    constructor(incomingData) {
        this.value = incomingData;
        this.left = null;
        this.right = null;
    }


}

let rootNode = new Node(4);
let node1 = new Node(2);
let node2 = new Node(1);
let node3 = new Node(3);
let node4 = new Node(7);

rootNode.left = node1;
rootNode.right = node4;
node1.left = node2;
node1.right = node3;
let target = 2;

function searchInBstRecursive(rootNode, target) {
    if (rootNode === null) {
        return null;
    }

    if (rootNode.value === target) {
        // return roootNode.value;
        return rootNode;
    } else if (rootNode.value > target) {
        return searchInBstRecursive(rootNode.left, target);
    } else if (rootNode.value < target) {
        return searchInBstRecursive(rootNode.right, target);
    }
    return null;
}
console.log("search in bst recursive :", searchInBstRecursive(rootNode, target));


//! iterative way 

function searchInBstIterative(rootNode, target) {
    while (rootNode !== null) {
        if (rootNode.value === target) {
            return rootNode;
        } else if (target < rootNode.value) {
            rootNode = rootNode.left;
        } else {
            rootNode = rootNode.right;
        }
    }
    return null; // Not found
}

console.log("search in bst iterative : ", searchInBstIterative(rootNode, target));