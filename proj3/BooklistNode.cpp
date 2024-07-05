# include "BooklistNode.h"

// Default constructor
BooklistNode::BooklistNode() {
    bookName = "none";
    authorName = "none";
    yearPublished = 0;
    nextNodePtr = nullptr;
}

// Constructor with parameters
BooklistNode::BooklistNode(string initBookName, string initAuthorName, int inityearPublished, BooklistNode* nextLoc){
    bookName = initBookName;
    authorName = initAuthorName;
    yearPublished = inityearPublished;
    nextNodePtr = nextLoc;
}

// Destructor 
BooklistNode::~BooklistNode(){
    // Empty destructor (no memory deallocation)
}

// Setting the next node pointer
void BooklistNode::SetNext(BooklistNode* nodePtr) {
    nextNodePtr = nodePtr;
}

// Getting the book name
string BooklistNode::GetBookName() const {
    return bookName;
}

// Getting the author name of the book
string BooklistNode::GetAuthorName() const {
    return authorName;
}

// Getting the publication year of the book 
int BooklistNode::GetYearPublished() const {
    return yearPublished;
}

// Getting the next node pointer 
BooklistNode* BooklistNode::GetNext() {
    return nextNodePtr;
}

// Printing the information of the book node
string BooklistNode::PrintBooklistNode() {
    string result = bookName + "\nAuthor Name: " + authorName + "\nYear Published: " + to_string(yearPublished);
    return result;
}