# Linked Lists

A linked list is a **linear** collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a **collection of nodes** which together represent a sequence

## Doubly-linked lists

Double-linked lists **require more space per node** (unless one uses [XOR-linking](https://en.wikipedia.org/wiki/XOR_linked_list)), and their elementary operations are more expensive; but they are often easier to manipulate because they allow fast and easy sequential access to the list in both directions.

In a doubly linked list, one **can insert or delete a node in a constant number of operations given only that node's address**. To do the same in a singly linked list, one must have the address of the pointer to that node, which is either the handle for the whole list (in case of the first node) or the link field in the previous node.

## Advantages

The principal benefit of a linked list over a conventional array is that the list elements **can be easily inserted or removed** without reallocation or reorganization of the entire structure because the data items **need not be stored contiguously in memory or on disk**, while restructuring an array at run-time is a much more expensive operation.

Linked lists allow insertion and removal of nodes at any point in the list, and allow doing so with a constant number of operations by keeping the link previous to the link being added or removed in memory during list traversal.

On the other hand, since simple linked lists by themselves **do not allow random access to the data or any form of efficient indexing**, many basic operations — such as obtaining the last node of the list, finding a node that contains a given datum, or locating the place where a new node should be inserted—may require iterating through most or all of the list elements.

## Disadvantages

* They **use more memory** than arrays because of the storage used by their pointers.
* Nodes in a linked list **must be read in order from the beginning** as linked lists are inherently sequential access.
* Nodes are stored **noncontiguously**, greatly increasing the time periods required to access individual elements within the list, especially with a **CPU cache**.
* Difficulties arise in linked lists when it comes to **reverse traversing**. For instance, singly-linked lists are cumbersome to navigate backward and while doubly linked lists are somewhat easier to read, memory is consumed in allocating space for a back-pointer.

## Complexity

![Linked list vs Dyn Array complexity comparison](/assets/images/ll_complexity_comparison.png)

For further reading [Linked List](https://en.wikipedia.org/wiki/Linked_list)
