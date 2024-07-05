#include "Book.h"
/* Type your code here */

// Default constructor
Book::Book() {
    bookName = "none";
    bookPrice = 0;
    bookAuthor = "none";
    bookQuantity = 0;
}

// Constructor with parameters
Book::Book(string name, string author, double price, int quantity) {
    bookName = name;
    bookAuthor = author;
    bookPrice = price;
    bookQuantity = quantity;
}

// Setters
void Book::SetName(string name) {
    bookName = name;
}
void Book::SetPrice(double price){
    bookPrice = price;
}
void Book::SetAuthor(string author){
    bookAuthor = author;
}
void Book::SetQuantity(int quantity){
    bookQuantity = quantity;
}

// Getters
string Book::GetName() const {
    return bookName;
}
double Book::GetPrice() const {
    return bookPrice;
}
string Book::GetAuthor() const {
    return bookAuthor;
}
int Book::GetQuantity() const {
    return bookQuantity;
}

// Prints the book name followed by the quantity "@" price "=" total book costs
string Book::PrintBookCost() {
    double totalCost = bookPrice * bookQuantity;
    return bookName + " " + to_string(bookQuantity) + " @ $" + to_string(bookPrice) + " = $" + to_string(totalCost);
}

// Prints the book name " by " author of the book
string Book::PrintBookDetails() {
    return bookName + " by " + bookAuthor;
}
