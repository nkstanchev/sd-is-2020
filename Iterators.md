# Iterators

In computer programming, an iterator is an object that enables a programmer to **traverse a container**, particularly lists.

An external iterator may be thought of as a type of pointer that has two primary operations: referencing one particular element in the object collection (called element access), and modifying itself so it points to the next element (called element traversal).

There must also be a way to create an iterator so it points to some first element as well as some way to determine when the iterator has exhausted all of the elements in the container.

The primary purpose of an iterator is to allow a user to **process every element of a container while isolating the user from the internal structure of the container**. This allows the container to store elements in any manner it wishes while allowing the user to treat it as if it were a simple sequence or list.

An iterator class is usually designed in tight coordination with the corresponding container class. Usually, the container provides the methods for creating iterators.

## Contrasting with indexing

- Counting loops are not suitable to all data structures, in particular to data structures with **no or slow random access, like lists or trees.**

- Iterators can provide a **consistent** way to iterate on data structures of all kinds, and therefore make the code more **readable, reusable, and less sensitive to a change in the data structure.**


## In C++


The C++ language makes wide use of iterators in its [Standard Library](https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library),

Traversal using iterators usually involves a **single varying iterator**, and **two fixed iterators** that serve to delimit a range to be traversed. The distance between the limiting iterators, in terms of the number of applications of the operator ++ needed to transform the lower limit into the upper one, equals the number of items in the designated range; the number of distinct iterator values involved is **one more than that**.

By convention, the lower limiting iterator "points to" the first element in the range, while the upper limiting iterator does not point to any element in the range, but rather just beyond the end of the range. For traversal of an entire container, the begin() method provides the lower limit, and end() the upper limit. The latter does not reference any element of the container at all, but is a valid iterator value that can be compared against.

The following example shows a typical use of an iterator.
```c++
std::vector<int> items;
items.push_back(5);  // Append integer value '5' to vector 'items'.
items.push_back(2);  // Append integer value '2' to vector 'items'.
items.push_back(9);  // Append integer value '9' to vector 'items'.

for (auto it = items.begin(); it != items.end(); ++it) {  // Iterate through 'items'.
  std::cout << *it;  // And print value of 'items' for current index.
}
// In C++11, the same can be done without using any iterators:
for (auto x : items) {
  std::cout << x;  // Print value of each element 'x' of 'items'.
}
```
