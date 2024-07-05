#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
#include <string>
#include<sstream>
using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
		Node(const T& d, Node* n, Node* p) : data(d), next(n), prev(p) { }
	};
	Node* head;

public:
	DoubleLinkedList() : head(NULL) { }
	~DoubleLinkedList() {/*Implement if needed*/ 
	Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
	//adds a new node to the beginning of the double linked list
	void push_front(const T& value) {
		/*Implement*/
		Node* newNode = new Node(value, head, NULL);
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;

	}

	friend std::ostream& operator<< (std::ostream& os, DoubleLinkedList<T>& linkedList)
	{
		for (Iterator iter = linkedList.begin(); iter != linkedList.end(); ++iter)
		{
			os << *iter << " ";
		}
		return os;
	}

	class Iterator
	{
	 private:
        Node* iNode;
    public:
        Iterator(Node* node) : iNode(node) {}
		~Iterator() {/*Implement if needed*/}

		//check if iNode is the same
        bool operator!=(const Iterator& other) const {
			//Implement
            return iNode != other.iNode;
        }
		//prefix increment
        Iterator& operator++() {
           //Implement
			//moves to the next node in the double linked list
			iNode = iNode->next;
			return *this;
        }

		//prefix decrement
        Iterator& operator--() {
			//Implement
			//moves back to the previous node in the double linked list
            iNode = iNode->prev;
            return *this;
        }

      	//reference operator, return the data contained in iNode
        T& operator*() const {
			//Implement - then get rid of following statement
            return iNode->data;
        }

		// Determines if two Iterators are equal to each other
        bool operator==(const Iterator& rhs) const {
            return iNode == rhs.iNode;
        }

		//insert a new node with this value before this iterator
		//return an iterator to the new node
        Iterator insert_before(const T& value) {
			//Implement
            if (iNode == nullptr) {
                return *this; // Or handle differently
            }
            Node* newNode = new Node(value, iNode, iNode->prev);
            if (iNode->prev != nullptr) {
                iNode->prev->next = newNode;
            }
            iNode->prev = newNode;
            return Iterator(newNode);
        }
		//insert a new node with this value after this iterator
      //return an iterator to the new node
        Iterator insert_after(const T& value) {
			//Implement
            if (iNode == nullptr) {
                return *this; // Or handle differently
            }
            Node* newNode = new Node(value, iNode->next, iNode);
            if (iNode->next != nullptr) {
                iNode->next->prev = newNode;
            }
            iNode->next = newNode;
            return Iterator(newNode);
        }

		//remove the node this iterator is pointing to
      //return an iterator to the node after the removed node
        Iterator remove() {
			//Implement
            if (iNode == nullptr) {
                return *this; // Or handle differently
            }
            if (iNode->prev != nullptr) {
                iNode->prev->next = iNode->next;
            }
            if (iNode->next != nullptr) {
                iNode->next->prev = iNode->prev;
            }
            Node* nextNode = iNode->next;
            delete iNode;
            return Iterator(nextNode);
        }
    };

	/** Return iterator pointing to the first value in linked list */
    Iterator begin() const {
        return Iterator(head);
    }

	/** Return iterator pointing to something not in the linked list
	Returns an iterator referring to the past-the-end element in the
	list container. */
    Iterator end() const {
        return Iterator(nullptr);
    }

	/*Returns an iterator to the first element in the range [first,last)
	that compares equal to value. The range searched is [first,last),
	which contains all the elements between first and last, including
	the element pointed by first but not the element pointed by last.
	If no elements match, the function returns end().*/
    Iterator find(Iterator first, Iterator last, const T& value) {
		//Implement then delete following line
        for (Iterator iter = first; iter != last; ++iter) {
            if (*iter == value) {
                return iter;
            }
        }
		// returns the end iterator if no elements match
        return last;
    }

	/*The container is extended by inserting a new element before the
	element at the specified position. The function returns an iterator
	pointing to the newly inserted element.
	If not found return end()*/
    Iterator insert_before(Iterator position, const T& value) {
		//Implement then delete following line
		// checking if the position is at the beginning of the list
        if (position == begin()) {
            push_front(value); // using push_front function to insert at the beginning
            return begin(); 	// returns iterator pointing to the newly inserted element
        }
        return position.insert_before(value);
    }

	/*The container is extended by inserting a new element after the
	element at the specified position. The function returns an iterator
	pointing to the newly inserted element.*/
    Iterator insert_after(Iterator position, const T& value) {
		//Implement then delete following line
        return position.insert_after(value);
    }

	/** Return iterator pointing to next item after deleted node linked list */
	/*Removes from the list container a single element (position) and returns an
	iterator pointing to the element that followed the element erased by the function
	call. This is the container end if the operation erased the last element in the sequence.*/
    Iterator remove(Iterator position) {
		//Implement and delete following line
        if (position == end()) {
            return end();
        }
        return position.remove();
    }

	/** Return a string from iterator position to beginning of linked list in reverse order,
	separated by a space*/
    string reverseString(Iterator position) {
		//Implement
        std::ostringstream reversedString;
        for (Iterator iter = position; iter != end(); --iter) {
            if (iter != position) {
                reversedString << " ";
            }
            reversedString << *iter;
        }
        return reversedString.str();
    }

	//Assigns new_value to all the elements in the range [first,last) are equal to old_value. 
    void replace(Iterator first, Iterator last, const T& old_value, const T& new_value) {
        for (Iterator iter = first; iter != last; ++iter) {
            if (*iter == old_value) {
                *iter = new_value;
            }
        }
    }

	//Returns all elements of the DoubleLinkedList separated by a space
    string toString() {
        std::ostringstream oss;
        for (Iterator iter = begin(); iter != end(); ++iter) {
            if (iter != begin()) {
                oss << " ";
            }
            oss << *iter;
        }
        return oss.str();
    }
};
#endif