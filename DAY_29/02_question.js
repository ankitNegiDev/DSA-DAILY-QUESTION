class Node {

    constructor(incomingData) {
        this.value = incomingData;
        this.next = null;
    }
}

let head = new Node(4);

let node2 = new Node(5);
head.next=node2;
let node3 = new Node(1);
node2.next=node3;
let node4=new Node(9);
node3.next=node4;
function deleteGivenNode(node) {
    // assigning the next node value since it is mentioned that given node is not last node.
    node.value = node.next.value;
    // to decrease the ndoe by 1 we need to skip the middle node from the node which is given to the node that is next to next node.
    node.next = node.next.next;
    return "node is dleted check by traversing the node"
}


console.log(deleteGivenNode(node2));

while (head) {
    console.log(head.value);
    head = head.next;
}