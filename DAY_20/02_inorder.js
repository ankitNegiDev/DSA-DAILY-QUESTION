//  ** (2) in -order-- -> left sub - tree-- -> rooot---->> right subtree(in -pone)

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




function inorder(root, result) {
    if (root === null) {
        return;
    }
    inorder(root.left, result);
    result.push(root.value);
    inorder(root.right, result);
    return result;
}
console.log(inorder(rootNode, []));
