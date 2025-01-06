# Project Code Standards
## Module Header
Each Module should have a header that contains:
1. The name of the module.
2. What the module does.
3. Module functions overview.
4. The date of creation.
5. The author of the module.
## Naming Conventions
1. Local Variables: Snake case or Flat case (i.e. `variable_name`, `variablename`)
2. Global Variables: Pascal snake case (i.e. `Global_Variable`)
3. Constants: Capital letters only (i.e. `CONSTANT`)
4. Functions: Camel case (i.e. `functionName`)
5. Classes: Pascal case (i.e. `ClassName`)

*Avoid including digits as much as possible.*
## Code Format
1. Indentation size: 2 space.
2. Braces: Open brace on the same line as the control statement.
# Project Requirements
- Singly Linked List to store students.
- Stack to store course prerequisites.
- Doubly Linked List to track students' course history.
- Queue to be used as a wait-list for courses.
- Binary Tree to store courses.
- Hash table for searching.
# Project Class Diagram
```mermaid
---
title: University System
---
classDiagram
class Student {
	+student_name: string
	+student_id: int
	+student_email: string
	+student_password: string
	+student_phone_number: int
	+student_address: string
	+student_course_history: DoublyLinkedList~Course~
}
class Course {
	+course_name: string
	+course_id: int
	+course_instructor: string
	+course_credits: int
	+course_prerequisites: Stack~Course~
	+course_waitlist: Queue~Student~
}
class Node~T~ {
	+value: T
	+next: Node<T>
}
class DoubleNode~T~ {
	+value: T
	+next: Node<T>
	+previous: Node<T>
}
class SinglyLinkedList~T~ {
	-head: Node~T~
	-tail: Node~T~
	+isEmpty() bool
	+append(T: value) bool
	+insert(T: value, int: position) bool
	+push(T: value) bool
	+removeHead() bool
	+removeNode() bool
	+removeTail() bool
	+deleteNode(T: value) bool
	+display() void
}
class Stack~T~ {
	-stack_top: Node~T~
	+isEmpty() bool
	+push(T: object) bool
	+pop() bool
	+peek() T
}
class DoublyLinkedList~T~ {
	-head: Node~T~
	-tail: Node~T~
	+isEmpty() bool
	+append(T: value) bool
	+insert(T: value, int: position) bool
	+push(T: value) bool
	+removeHead() bool
	+removeNode() bool
	+removeTail() bool
	+deleteNode() bool
	+display() void
}
class Queue~T~ {
	-front: Node~T~
	-rear: Node~T~
	+isEmpty() bool
	+enqueue(T: value) bool
	+dequeue() bool
	+peek() T
}
class BinaryTree~T~ {
	-root: DoubleNode~T~
	+isEmpty() bool
	+insert(T: value) bool
	+deleteNode(T: value) bool
	+traverse(Node~T~: root) void
	+display() void
}
class HashTable {
	pending
}

Student <--> Course
Stack --* SinglyLinkedList
SinglyLinkedList --* Node
Queue --* DoublyLinkedList
DoublyLinkedList --* DoubleNode
BinaryTree --* DoubleNode
```
# Modules
## Singly Linked List
### To-Do
- [ ] `isEmpty()` to check if the list is empty.
- [ ] Inserting
	- [ ] `push()` to insert at the start.
	- [ ] `append()` to insert at the end.
	- [ ] `insert(T value, int position)` to insert at a specific position.
- [ ] Deleting
	- [ ] `removeHead()` to remove the list's head.
	- [ ] `removeTail()` to remove the list's tail.
	- [ ] `deleteNode(T value)` to remove a specific value.
- [ ] `display()` to display the values in the list.

The Singly Linked will be used to store students and should:
1. Add students with their ID, Name, Email, Phone Number, Address, and Password.
2. Remove students by their ID.
3. Display student details.
## Stack
### To-Do
- [ ] `isEmpty()` to check if the stack is empty.
- [ ] `push()` to add elements to the top of the stack.
- [ ] `pop()` to remove the top element in the stack.
- [ ] `peek()` to return the top element in the stack.

The Stack will be used to store course prerequisites and should:
1. Check if a student is able to register a course by checking if their prerequisites stack is empty.
2. If the student is not able to register a course, the prerequisites left should be displayed.
The Stack is implemented using the Singly Linked List.
## Doubly Linked List
### To-Do
- [ ] `isEmpty()` to check if the list is empty.
- [ ] Inserting
	- [ ] `push()` to insert at the start.
	- [ ] `append()` to insert at the end.
	- [ ] `insert(T value, int position)` to insert at a specific position.
- [ ] Deleting
	- [ ] `removeHead()` to remove the list's head.
	- [ ] `removeTail()` to remove the list's tail.
	- [ ] `deleteNode(T value)` to remove a specific value.
- [ ] `display()` to display the values in the list.

The Doubly Linked List will be used to store each student's course enrollment history and should:
1. Add new completed courses.
2. Display the enrollment history of a specific student.
## Queue
### To-Do
- [ ] `enqueue(T value)` to add elements to the end of the Queue.
- [ ] `dequeue()` to remove the first element in the Queue.
- [ ] `peek()` to return the first element in the Queue.

The Queue will manage each course's wait-list and should:
1. Add a student to the wait-list when a course is full.
2. Enroll the first student on the wait-list when a spot is free.
The Queue is implemented using a Doubly Linked List.
## Binary Tree
### To-Do
- [x] `isEmpty()` to check if the tree is empty.
- [x] `insert(T value)` to add elements to their appropriate location in the tree.
- [x] `deleteNode(T value)` to remove elements from the tree.
- [x] `traverse(Node<T> root)` to traverse the tree.
- [x] `display()` to print all values in the tree.

The Binary Tree will be used to store courses and should:
1. Add courses.
2. Drop courses.
## Hash Table
### To-Do
- [ ] Insert
- [ ] Delete
- [ ] Search

The Hash Table will be used for efficient lookup.
