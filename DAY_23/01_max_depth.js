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
let node3 = new Node(40);

rootNode.left = node1;
rootNode.right = node2;
node2.left = node3;

function maxDepthInBT(rootNode) {
    if (rootNode === null) {
        return 0;
    }
    let leftDepth = maxDepthInBT(rootNode.left);
    let rightDepth = maxDepthInBT(rootNode.right);
    let maxDepth;
    if (leftDepth > rightDepth) {
        maxDepth = leftDepth;
    } else {
        maxDepth = rightDepth;
    }
    return 1 + maxDepth;
}
console.log("max depth is : ", maxDepthInBT(rootNode));


// can 't we do like take two variable depth and maxDepth and on each node we increase the depth and  in back track do --depth and check for maxDepth ??


function maxDepth(root) {
    let maxDepth = 0;
    let depth = 0;

    function traverse(node) {
        if (!node) return;

        depth++;  // Increase depth when entering a node
        maxDepth = Math.max(maxDepth, depth);  // Update maxDepth

        traverse(node.left);
        traverse(node.right);

        depth--;  // Backtrack (decrease depth when leaving a node)
    }

    traverse(root);
    return maxDepth;
}
