![alt text](https://raw.githubusercontent.com/zivkovicmilos/BinarySearchTree/master/img/BannerImg.jpg)

# Project Description
The goal of this homework project for the Algorithms and Data Structures 2 course was to implement a BST (in C++), with the following conditions:
1. BST holds integers as keys
2. BST allows duplicate keys
3. When adding a duplicate key, add as the successor

# Features
The following menu is used for interacting with the BST.

![alt text](./img/menu.svg)
<img src="./img/menu.svg">

# Program Breakdown
## BST
The binary search tree is implemented using structures. By separating out '''bstTree''' and '''bstNode''', we allow for a more generalized implementation of multiple BSTs.
### bstNode
The '''bstNode''' structure contains the key (as specified, an int), pointers to the left and right child, as well as a pointer to the parent node. By having the pointer to the parent node, general operations with the BST (like deleting) are simplified at a small cost. The default constructor initializes the pointers to '''nullptr'''.
### bstTree
The tree struture contains the root of the BST, as well as the height of the tree (set at -1 without the root node)

## Tree Traversal
The standard tree traversal operations are implemented.
### Inorder
Because of the BST structure, printing the nodes in inorder displays them sorted (ascending).
For implementing the Inorder traversal, a stack (std::stack) was used.
The algorithm is pretty straightforward:
1. Go down the leftmost branch, while adding all the elements along the path to the stack
2. When you reach the end, take the first value from the stack, print it, and then check if it has a right child.
3. If it has a right child, set it as the current watched node, and repeat steps 1-3.

### Level Order
Level Order traversal is implented using a queue (std::queue), for priting out each level of the BST.
nodeNum keeps track of the number of nodes on the current level.

1. Add root to the queue
2. Dequeue the node, print it, and check if it has a left and / or right child. 
3. If so, add them to the queue as well.
4. Repeat steps 2-3.
The while loop will exit when all the keys of the BST are printed.