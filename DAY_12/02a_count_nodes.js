class Node {

    constructor(incomingData) {
        this.value = incomingData;
        this.next = null;
    }
}

let head = new Node(10);
let node2 = new Node(20);
let node3 = new Node(30);

head.next = node2;
node2.next = node3;

function printLinkedList(head) {
    while (head !== null) {
        console.log(head.value);
        head = head.next;
    }
}
printLinkedList(head);


function countNoOfNode(head) {
    let count = 0;
    for (let i = head; i !== null; i = i.next) {
        count++;
    }
    return count;
}
console.log("count : ", countNoOfNode(head));