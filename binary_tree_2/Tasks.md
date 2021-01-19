# Tasks


## 1. Sum of all the parent nodes having child node x
Given a binary tree containing n nodes. The problem is to find the sum of all the parent node’s which have a child node with value x.
```
Input : Binary tree with x = 2:
        4        
       / \       
      2   5      
     / \ / \     
    7  2 2  3    
Output : 11

        4        
       / \       
      2   5      
     / \ / \     
    7  2 2  3    

The highlighted nodes (4, 2, 5) above
are the nodes having 2 as a child node.
```

## 2. Check whether a binary tree is a full binary tree or not
A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes. Empty tree is also considered full binary tree.  
## 3. Check if two trees are Mirror
Given two Binary Trees, write a function that returns true if two trees are mirror of each other, else false.

For two trees ‘a’ and ‘b’ to be mirror images, the following three conditions must be true:

- Their root node’s key must be same
- Left subtree of root of ‘a’ and right subtree root of ‘b’ are mirror.
- Right subtree of ‘a’ and left subtree of ‘b’ are mirror.
```
tree a
        1        
       / \       
      3   2      
         / \     
         5  4    
tree b

        1        
       / \       
      2   3      
     / \       
    4  5       

Trees a and b are mirror
```
## 4. Check if two nodes are cousins in a Binary Tree
Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the two nodes are cousins of each other or not.
Two nodes are cousins of each other if they are at same level and have different parents.
```
     6
   /   \
  3     5
 / \   / \
7   8 1   3
7 and 1 are cousins.
3 and 5 are not
7 and 5 are not
```
## 5. Check if a binary tree is BST or not