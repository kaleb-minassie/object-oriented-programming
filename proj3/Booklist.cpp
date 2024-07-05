#include "Booklist.h"
#include <iostream>

// Default constructor
Booklist::Booklist() {
    head = nullptr;
    tail = nullptr;
}

// Destructor
Booklist::~Booklist() {
    // Deleting all nodes in the linked list
    while (head != nullptr) {
        BooklistNode* temp = head;
        head = head -> GetNext();
        delete temp;
    }
    // Since nodes are removed, indicating the list is empty
    tail = nullptr;
}

// Getting the head node
BooklistNode* Booklist::getHead() {
    // Returning the first node w/ actual data
    return head;
}

// Getting the tail node
BooklistNode* Booklist::getTail() {
    // Returning the last node w/ actual data
    return tail;
}

// Adding a new book to the end of the linked list
bool Booklist::add(string name, string artist, int yearPublished) {
    // Checking if the book already exists
    if (found(name) != nullptr) {
        cout << "This book already exists." << endl;
        return false;
    }

    // Creating a new BooklistNode to add a new to linked list
    BooklistNode* newNode = new BooklistNode(name, artist, yearPublished);

    // If the list is empty, setting both head and tail to the new node
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        // Adding the new node to the end to update the tail
        tail -> SetNext(newNode);
        tail = newNode;
    }
    return true;
}

// Finding a book by its name
BooklistNode* Booklist::found(string bookName) {
    BooklistNode* current = head;
    // Checking if the current node's book name matches the one searched for
    while (current != nullptr) {
        if (current -> GetBookName() == bookName) {
            // Returning the node if match is found
            return current;
            }
            current = current -> GetNext();
        }
        // Returning a null pointer if no match is found
        return nullptr;
    }

// Removing a book by its name
bool Booklist::remove(string bookName) {
    BooklistNode* current = head;
    BooklistNode* prev = nullptr;
    // Traversing the linked list
    while (current != nullptr) {
        if (current -> GetBookName() == bookName) {
            if (prev != nullptr) {
                // Updating the previous node's next pointer if book is not first in list
                prev -> SetNext(current -> GetNext());
            } else {
                // Updating the head pointer if the book is first in list
                head = current -> GetNext();
            }
            // Updating tail pointer if book is last in list
            if (current == tail) {
                tail = prev;
            }
            // Deleting the node
            delete current;
            return true;
        }   
        prev = current;
        current = current -> GetNext();
    }
    // Returning false if book is not found in list
    cout << "\"" << bookName << "\" not in the list" << endl;
    return false;
}

// Moving a book to the front of the list
bool Booklist::moveFront(string bookName) {
    BooklistNode* current = head;
    BooklistNode* prev = nullptr;
    // Traversing the linked list to find the specific book
    while (current != nullptr) {
        if (current -> GetBookName() == bookName) {
            if (prev != nullptr) {
                // Updating the previous node's next pointer to skip the current node
                prev -> SetNext(current -> GetNext());
            } else {
                return true;
            }
            // Moving the book found to the front by updating its next pointer
            current -> SetNext(head);
            head = current;
            // Updating the tail pointer if the book was last in list
            if (current == tail) {
                tail = prev;
            }
            return true;
        }
        prev = current;
        current = current -> GetNext(); 
    }
    // Returning false if book is not found in list
    cout << "\"" << bookName << "\" not in the list" << endl;
    return false;
}

// Displaying all books by a specific author
string Booklist::displayAuthor(string authorName) {
    string result;
    int count = 1;
    BooklistNode* current = head;
    // Traversing the linked list
    while (current != nullptr) {
        // Checking if the author's name of the current book matches the specified author's name
        if (current -> GetAuthorName() == authorName) {
            result = result + to_string(count) + ".\n" + current -> PrintBooklistNode() + "\n\n";
            count++; // Incrementing the count for the next book
        }
        // Moving to the next node in list
        current = current -> GetNext(); 
    } 
    // Returning the book information by the specific author
    return result;
}

// Retrieving the total number of books in the list
int Booklist::totalBooks() {
    int count = 0;
    BooklistNode* current = head;
    // Traversing the linked list
    while (current != nullptr) {
        count++; // Increminting the count for the next book
        current = current -> GetNext(); // Moving to the next node in the list
    }
    // Returning the total count of books in the list
    return count;
}

// Displaying all of the books in the list
string Booklist::displayList() {
    string result;
    int count = 1;
    BooklistNode* current = head;
    // Checking if the list is empty
    if (head == nullptr) {
        return "Booklist is empty"; // Returning a message if the list is empty
    }
    
   
    while(current != nullptr) {
        result = result + to_string(count) + ".\n" + current -> PrintBooklistNode() + "\n\n";
        count++;
        current = current -> GetNext(); // Moving to the next node in the list
    }
    // Returning the list for all books in the list
    return result;
}

