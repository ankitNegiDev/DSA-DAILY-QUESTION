class Node {
    constructor(data) {
        this.value = data;
        this.next = null;
    }
}
let head = new Node(10);
let node2 = new Node(20);
let node3 = new Node(30);
let node4 = new Node(40);

head.next = node2;
node2.next = node3;
node3.next = node4;


function print(head) {
    for (let i = head; i !== null; i = i.next) {
        // console.log(i, "value : ", i.value);
        console.log(i.value);
        // console.log("\n\n");
    }
}
print(head);


function countNoOfNode(head) {
    let count = 0;
    for (let i = head; i !== null; i = i.next) {
        count++;
    }
    return count;
}
console.log("count : ", countNoOfNode(head));
let count = countNoOfNode(head);


// console.log("\n\n");

function insertionAtTheBegning(data, head) {
    let newNode = new Node(data);
    newNode.next = head;
    // head = newNode;
    // console.log("head :", head);
    return newNode;
}
// head = insertionAtTheBegning(100, head);
// console.log("\n");

// print(head);

function insertionAtLast(head, data) {
    let newNode = new Node(data);
    while (head.next !== null) {
        head = head.next;
    }
    head.next = newNode;
}
// insertionAtLast(head, 100000);
insertionAtLast(head, 20000);
print(head);

// ----------------- middle of linked list --------------------------
function middleOfLinkedList(head,count) {
    let finialCount = Math.floor(count / 2);
    while (finialCount) {
        head = head.next;
        finialCount--;
    }
    // console.log(head);
    return head;
}

let middleNodePointer = middleOfLinkedList(head, count);
// console.log(middleNodePointer.value);



// ---------------- using two pointer approach slow and fast point ------------------

/**
 * approach is simple take two point start them from same node and first point will take 1 jump at a time where as 2nd pointer will take two jump and we know whne second point is null then it is end of linked list.
 */
console.log("\n\n-------------- two pointer");
print(head);
count = countNoOfNode(head);
console.log(count);
function twoPointer(head) {
    let slow = head;
    let fast = head;

    // this is for even one like 10,20,30,40,50 so slow will be on 30 (second middle) and fast will be null. which is 50.next=null..

    // if the question demand for the first middle then use fast.next.next !==null

    /*
    for the odd one
    while (fast !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    */
    /*
    for even first middle..
    while(fast.next.next !==null){
        slow=slow.next;
        fast=fast.next.next;
    }
     */

    /*
    for the even second middle node.
    while(fast.next !==null){
        slow=slow.next;
        fast=fast.next.next;
    }
    */
    
    while (fast !== null && fast.next!==null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    // if we said to return only one node the center one then we can do 
    // slow.next=null;
    return slow;
}
console.log(twoPointer(head));