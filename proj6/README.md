[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/lPoZWe9E)
# CMSC340Project6
Create an <b>Iterator</b> for a <b>Double Linked list</b>. The nodes of the double linked list will have both a next and a prev.

You have been given the following files:
<br><b>main.cpp</b> - no need to modify
<br><b>DoubleLinkedList.h</b> - you will be implementing the functions in this file


<b>DoubleLinkedList.h</b>. This is a templated class, no .cpp
<br>Contains the following functions:
<br>(a) <b>constructor</b> - provided for you.
<br>(b) <b>destructor</b> - implement if needed.
<br>(c) <b>push\_front</b> - adds a node to the beginning of the double linked list.
<br>(d) <b>operator<<</b> - provided for you
<br>(e) <b>begin</b> - returns an Iterator, provided for you
<br>(f) <b>end</b> - Returns an iterator referring to the past-the-end element in the list container (null), provided for you.
<br>(g) <b>find</b> - Returns an iterator to the first element in the range [first,last) that is equal to value. The range searched is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last. If no elements match, the function returns end().
<br>(h) <b>insert\_before</b> -  inserting a new element before the element at the specified position. The function returns an iterator pointing to the newly inserted element. If not found return end().  Call the insert_before of the iterator except when adding to the beginning of the list, use the push\_front to do that. The function returns an iterator pointing to the newly inserted element. If not found return end().
<br>(i) <b>insert\_after</b> - inserting a new element after the element at the specified position. The function returns an iterator pointing to the newly inserted element. If not found return end()
<br>(j) <b>remove</b> - returns an iterator pointing to the element that followed the element erased by the function call. Returns end() if the operation erased the last element in the sequence.
<br>(k) <b>replace</b> - replaces all occurrences of the old\_value with a new\_value within two Iterator positions. The range searched is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
<br> (l) <b>reverseString</b> - Return a string of the data within the nodes from iterator position to beginning of linked list, separated by a space.
<br>(m) <b>toString</b> - provided for you. Returns a string of the data within all the nodes of the double linked list, separated by a space.

The <b>Iterator</b> class is a nested class within DoubleLinkedList.
It will contain the following methods:
<br>(a) <b>constructor</b> - provided for you
<br>(b) <b>destructor</b> - implement if needed
<br>(c) <b>operator!=</b> - determines if two Iterators are not equal
<br>(d) <b>operator++</b> - moves to the next node in the DoubleLinkedList
<br>(e) <b>operator--</b> - moves back to the previous node in the DoubleLinkedList
<br>(f) <b>operator*</b> - returns the data portion of the node
<br>(g) <b>insert\_before</b> - inserts a new node before the Iterator position, returns Iterator to the new node. You do not have to implement inserting before the beginning of the list. This should be caught by the insert\_before in DoubleLinkedList.
<br>(h) <b>insert\_after</b> - inserts a new node after the Iterator position, returns Iterator to the new node
<br>(i) <b>remove</b> - Removes the node and returns an iterator to the next node which is after the deleted node in the DoubleLinkedList.

The main.cpp provided will print out the following.

```
Original string
1 2 3 4 

Insert 33 before 3
1 2 33 3 4 

Reverse the string
4 3 33 2 1 

Original string
one two three four 

Insert 2 1/2 after two
one two 2 1/2 three four 

Insert five after four
one two 2 1/2 three four five 

Insert zero before one
zero one two 2 1/2 three four five 

```
A tests.cpp is provided for testing purposes. A testsGL.cpp is provided for running on the GL server and creating a Valgrind report.
