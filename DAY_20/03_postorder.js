//  ** (3) post - order-- -> left sub - tree-- -> right sub - tree---->> root(post - pone)

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


function postorder(root, result) {
    if (root === null) {
        return;
    }
    postorder(root.left, result);
    postorder(root.right, result);
    result.push(root.value);
    return result;
}
console.log(postorder(rootNode, []));