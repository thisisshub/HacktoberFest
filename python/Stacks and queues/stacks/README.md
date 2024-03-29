# Introduction

A **stack** is a LIFO (Last In First Out) data structure. A stack pushes (inserts) a new element to the top of the stack and also pops (removes) the element from the top.

## Stack includes the following functions:

- empty() – Returns a boolean value for whether the stack is empty or not.
- size() – Returns the size of the stack.
- top() – Returns a reference to the topmost element of the stack.
- push(item) – Inserts the element ‘item’ at the top of the stack.
- pop() – Deletes the topmost element of the stack.

# Implementation

Stacks can be implemented in any of the following ways-

- [List](./list.ipynb)
- [Collections](./collection.ipynb)
- [queue.LifoQueue](./queue.ipynb)
- [Class](./class.ipynb)

# Time Complexity

- Popping an element from a stack takes O(1) time complexity
- Popping the last element in a stack will take O(n).
