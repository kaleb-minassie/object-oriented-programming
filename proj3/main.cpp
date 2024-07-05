#include <iostream>
#include <iomanip>
#include <string>
#include "Booklist.h"
using namespace std;

void PrintMenu(const string booklistTitle) {
   //Put your code here

   // Creating a Booklist instance
   Booklist booklist;
   char choice;
   string bookName, authorName;
   int yearPublished;

do {
    
    cout << booklistTitle << " BOOKLIST MENU" << endl;
    cout << "a - Add book" << endl;
    cout << "d - Remove book" << endl;
    cout << "m - Move book to front" << endl;
    cout << "s - Output books by specific author" << endl;
    cout << "t - Output total number of books in booklist" << endl;
    cout << "o - Output full booklist" << endl;
    cout << "q - Quit" << endl;

    cout << "Choose an option: ";
    cin >> choice;

    switch(choice) {
        case 'a':
        // Adding a book
        cout << "ADD BOOK" << endl;
        cout << "Enter book's name: ";
        cin.ignore(); // Removing any lingering newline character
        getline(cin, bookName);
        cout << "Enter author's name: ";
        getline(cin, authorName);
        cout << "Enter year published: ";
        cin >> yearPublished;

        if (booklist.add(bookName, authorName, yearPublished)) {
            cout << "Book added successfully." << endl;
        } else {
            cout << "This book already exists." << endl;
        }
        break;
        case 'd':
        // Removing a book
        cout << "REMOVE BOOK" << endl;
        cout << "Enter book's name: ";
        cin.ignore(); // Removing any linering newline character
        getline(cin, bookName);

        if(booklist.remove(bookName)) {
            cout << "\"" << bookName << "\" removed" << endl;
         } else {
            cout << "\"" << bookName << "\" not in the list" << endl;
        }
        break;
        case 'm': 
        // Moving a book to front
        cout << "MOVE BOOK TO BEGINNING" << endl;
        cout << "Enter book's name: ";
        cin.ignore(); // Removing any lingering newline character
        getline(cin, bookName);

        if(booklist.moveFront(bookName)) {
            cout << "\"" << bookName << "\" moved to front of the list" << endl;

        } else {
            cout << "\"" << bookName << "\" not in the list" << endl;
        }
        break;
        case 's':
        // Displaying books by specific author
        cout << "OUTPUT BOOKS BY SPECIFIC AUTHOR" << endl;
        cout << "Enter author's name: ";
        cin.ignore(); // Removing any lingering newline character
        getline(cin, authorName);
        cout << booklist.displayAuthor(authorName) << endl;
        break;
        case 't':
        // Displaying the total number of books in list
        cout << "OUTPUT TOTAL NUMBER OF BOOKS IN BOOKLIST" << endl;
        cout << "Total books: " << booklist.totalBooks() << " books" << endl;
        break;
        case 'o':
        // Displaying the full book list
        cout << booklistTitle << " - OUTPUT FULL PLAYLIST" << endl;
        cout << booklist.displayList() << endl;
        break;
        case 'q':
        // Quit
        cout << "Goodbye!" << endl;
        break;
        default:
        cout << "Invaild option. Please try again." << endl;
    }
} while (choice != 'q');
}
int main() {
    string booklistTitle;

    // Prompt user for booklist title
    cout << "Enter booklist's title:" << endl;
    getline(cin, booklistTitle);
    cout << endl;

    // Output book list menu options
    PrintMenu(booklistTitle);

    return 0;
}