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

// insertion at the midddle....

function insertionAtTheMiddle(insertAfter, data) {
    let newNode = new Node(data);
    let temp = insertAfter.next;
    insertAfter.next = newNode;
    newNode.next = temp;
}

insertionAtTheMiddle(head.next, 2000);
insertionAtTheMiddle(head.next.next, 400);
console.log("200 is inserted at the middle\n");
printLinkedList(head);



