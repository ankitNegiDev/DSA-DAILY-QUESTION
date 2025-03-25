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
console.log("\n\n");

function insertionAtLast(head,data) {
    let newNode = new Node(data);
    while (head.next !== null) {
        head = head.next;
    }
    head.next = newNode;
}
insertionAtLast(head, 100000);
printLinkedList(head);
console.log("\n\n");