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