//  using set...




//! Approach using set..
/**
 * the approach is simple ... first store all the node of list a in head.. 
 * next run a loop and checking if there is any node in the list b if yes then its a corring point
 */

function intersectionPointSet (headA, headB) {
    
    let set=new Set();
    let temp=headA;
    // first store the headA in set..
    while(temp !==null){
        set.add(temp);
        temp=temp.next;
    }

    temp = headB;
    while (temp !== null) {
        if (set.has(temp)) {
            return temp;
        } else {
            set.add(temp);
        }
        temp = temp.next;
    }
};


//! approach two using two pointer
/**
 * the approach is simple first we will create a function for counting the node.. 
 * then we will calculate the length of each list . by passing headA, or headB
 * then we will take two pointer i for first list and assinging headA and j for second assinig headB.
 * then we will take the diff of both the length of linked list. whoever is greater length we will move its pointer to that no of time by using loop until diff is not 0 increase either i or j ... like i=i.next or j=j.next
 * next we need to find the intersection point ... so run a loop until i!=j so if there is no intersection then we can return the null or if there is intersection then we can return i or j since both will become same .
 */

function countNode(head) {
    let count = 0;
    while (head !== null) {
        count++;
        head = head.next;
    }
    return count;
}
function intersectionPoint(headA, headB) {
    let lengthA = countNode(headA);
    let lengthB = countNode(headB);

    let difference = Math.abs(lengthA - lengthB);

    let i = headA;
    let j = headB;
    if (lengthA > lengthB) {
        while (difference) {
            i = i.next;
            difference--;
        }
    } else {
        while (difference) {
            j = j.next;
            difference--;
        }
    }
    // if both pointer point to same node stop the loop and return any pointer.
    while (i !== j) {
        i = i.next;
        j = j.next;
    }
    return i;
}


// if we don't wna use the countNode function then we can use it like

//! just check this code at the rev...
function intersectionPoint(headA, headB) {
    if (headA == null || headB == null) {
        return null;
    }
    let temp1 = headA;
    let temp2 = headB;
    while (temp1 != temp2) {
        temp1 = temp1.next;
        temp2 = temp2.next;
        if (temp1 == temp2) return temp1;
        if (temp1 == null) temp1 = headB;
        if (temp2 == null) temp2 = headA;
    }
    return temp1;
}