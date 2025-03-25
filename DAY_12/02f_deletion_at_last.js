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


function deletionAtLast(head) {
    if (head.next === null || head===null) {
        return null;
    }
    while (head.next.next !== null) {
        head = head.next;
    }
    console.log("head :", head, "head value ", head.value);
    head.next = null;
    return head; 
}
deletionAtLast(head);
printLinkedList(head);
console.log("----\n\n 2nd deletion");

deletionAtLast(head);
printLinkedList(head);
console.log("-----3 rd deletion");

head = deletionAtLast(head); //! for last one node...
console.log("value of head after deletion all node",head);

console.log("-----\n\n");
printLinkedList(head);
