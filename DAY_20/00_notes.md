# Tree data structure

```js
class Node{
    constructor(incomingData){
        this.value=incomingData;
        this.left=null;
        this.right=null;
    }


}

let rootNode=new Node(10);
let node1=new Node(20);
let node2=new Node(30);

rootNode.left=node1;
rootNode.right=node2;
```

* ## root node

  * the top most node.

* ### lef node or leaves

  * nodes which are on at the bottom of tree structure.

* ### levels

* ### verticals

  * vertical no decreases in left of root node and vertical no increase in right.

* ### sub-tree

* ### ancestor

* ### descendent

* ### degree

  * no of child define degree.. if child are 0 then degree is 0 if 1 child then degree it 1 and so on..

* ### types of tree

  * (1) B T -> where every node is having 0 node 1 node or 2 two child that's it.
  * (2) Full B T -> where every node is having either 0 node or 2 child that's it.
  * (3) degenerate -> only one child either in left or right..
  * (4) skewed -> (1) left skewed -> only the left child. (2) right skewed -> only right child.
  * (5) complete BT -> every node must be having left and right child.

* ### tree

  * every tree is having three parts one is root node , left sub-tree , right sub-tree.

* ### tree traversal

  * (1) pre-order  ---> root ---> left sub tree ---->> right subtree (pre-pone)
  * (2) in-order   ---> left sub-tree ---> rooot ---->> right subtree (in-pone)
  * (3) post-order  ---> left sub-tree ---> right sub-tree ---->> root (post-pone)
  * (4)
