## What is a stack?

In computer science, a stack is an abstract data type that serves as a collection of elements, with two principal operations:

  * push, which adds an element to the collection, and
  * pop, which removes the most recently added element that was not yet removed.

The order in which elements come off a stack gives rise to its alternative name, LIFO (last in, first out). Additionally, a peek operation may give access to the top without modifying the stack.

The name "stack" for this type of structure comes from the analogy to a set of physical items stacked on top of each other, which makes it easy to take an item off the top of the stack, while getting to an item deeper in the stack may require taking off multiple other items first.

![alt text][logo]

[logo]: https://www.tutorialspoint.com/data_structures_algorithms/images/stack_representation.jpg

## Time Complexity in Stack 
|Operation|Time Complexity|
|---------|---------------|
|Access|O(n)|
|Search|O(n)|
|Insertion|O(1)|
|Deletion|O(1)|

## Basic Operations on Stack
  * push
  * pop
  * top
  * isEmpty

  
|Operation|Complexity|
|---------|---------------|
|Push|O(1)|
|Pop|O(1)|
|Top|O(1)|
|isEmpty|O(1)|

### Push

 1) Check if the stack is full or not.
 2) If the stack is full,then print error of overflow and exit the program.
 3) If the stack is not full,then increment the top and add the element .

![alt text][logo2]

[logo2]: http://img.c4learn.com/2010/06/Push-Operation-on-Stack.jpg

### Pop

 1) Check if the stack is empty or not.
 2) If the stack is empty, then print error of underflow and exit the program.
 3) If the stack is not empty, then print the element at the top and decrement the top.

![alt text][logo3]

[logo3]: http://img.c4learn.com/2010/06/Pop-Operation-on-Stack.png


## Links:
  * [STL Stack](http://www.cplusplus.com/reference/stack/stack/)
  * [TutorialsPoint Stack](https://www.tutorialspoint.com/cpp_standard_library/stack.htm)
 