/**
//  check mainly for list1 [1] and list[2] and for lists where last elment comes same.. because this  is only point where it breaks  and secondly for the repetitive elemnts also.
    if (!list1) return list2;
    if (!list2) return list1;
    let tempList1 = list1;
    let tempList2 = list2;
    // Only swap if list1 has a larger value
    if (list1.val > list2.val) {
        let temp = list1;
        list1 = list2;
        list2 = temp;
    }
    let root = list1;
    let head = list1;
    while (list1 != null && list2 != null) {
        if (list1.val > list2.val) {
            tempList2 = list2.next;
            root.next = list2;
            root = root.next;
            list2 = tempList2;
        } else if (list1.val < list2.val) {
            tempList1 = list1.next;
            root.next = list1;
            root = root.next;
            list1 = tempList1;
        } else if (list1.val === list2.val) {
            // if (list1.next === null) {

            // } else {
            //     tempList1 = list1.next;

            // }

            if (list1.next !== null) {
                tempList1 = list1.next;
            } else {
                if (root == list1) {
                    tempList1 = null;
                } else {
                    tempList1 = list1;
                }
            }
            // list1=list1.next
            root.next = list2;
            root = root.next;
            list2 = list2.next;
            list1 = tempList1;
        }

        // now adding the remaning nodes either from list 1 or list 2
        root.next = list1 !== null ? list1 : list2;
    }
    console.log("list 1 :", list1);
    console.log("list 2 : ", list2);
    console.log("templist1 is : ", tempList1);
    return head;
    the main problem is we are swapping the head of both list..
 */


class Node {
    constructor(data) {
        this.value = data;
        this.next = null;
    }
}
// let newNode = new Node(10);

function mergeTwoSortedListIterative(list1, list2) {

    // if list 1 is empty then return list 2 same if list 2 is empty return list 1.
    if (!list1) return list2;
    if (!list2) return list1;

    // Step 1: checking whichever list is smaller make head point to it.
    let head;
    if (list1.val < list2.val) {
        head = list1;
        list1 = list1.next;
    } else if (list1.val > list2.val) {
        head = list2;
        list2 = list2.next;
    } else if (list1.val === list2.val) {
        head = list1;
        list1 = list1.next;
    }

    // Step 2: we need to create another pointer which we need for the traversing means which will move to last of merged sorted linked list..
    let root = head;

    while (list1 !== null && list2 != null) {
        if (list1.val < list2.val) {
            root.next = list1;
            list1 = list1.next;
        } else if (list1.val > list2.val) {
            root.next = list2;
            list2 = list2.next;
        } else if (list1.val === list2.val) {
            root.next = list2;
            list2 = list2.next;
        }
        root = root.next;
    }

    // last step : point the root.next to whoever list which is remanined.. the loop will only break if one list is finished or if both are equal then root.next will have null.
    root.next = list1 || list2;

    return head;

}
function mergeTwoSortedListIterativeOptmize(list1, list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    // Step 1
    let head;
    if (list1.val < list2.val) {
        head = list1;
        list1 = list1.next;
    } else {
        // it handel both case of list1.val > and list1.val === list2.val
        head = list2;
        list2 = list2.next;
    }

    // Step 2
    let root = head;

    while (list1 && list2) {
        if (list1.val < list2.val) {
            root.next = list1;
            list1 = list1.next;
        } else {
            // same handel both case .. list1.val > list2.val and equal to one
            root.next = list2;
            list2 = list2.next;
        }
        root = root.next;
    }

    // Step 3
    root.next = list1 || list2;

    return head;
}