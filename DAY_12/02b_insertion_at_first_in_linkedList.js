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
    let temp = head;
    while (temp !== null) {
        console.log(temp.value);
        temp = temp.next;
    }
}
// let newNode = new Node(100);

function insertionAtTheBegning(data, head) {
    let newNode = new Node(data);
    newNode.next = head;
    // head = newNode;
    // console.log("head :", head);
    return newNode;
}
head = insertionAtTheBegning(100, head);
head = insertionAtTheBegning(200, head);
printLinkedList(head);

