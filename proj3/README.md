[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/BnD3BMhN)
# CMSC340Project3
You will be building a linked list. Make sure to keep track of both the head and tail nodes.

<p>(1) Create five files to submit.</p>
<ul>
<li><b>BooklistNode.h</b> - Class declaration (template provided)</li>
<li><b>BooklistNode.cpp</b> - Class definition</li>
<li><b>Booklist.h</b> - Class declaration (template provided)</li>
<li><b>Booklist.cpp</b> - Class definition</li>
<li><b>main.cpp</b> - main() function</li></ul>

<p>Build the BooklistNode class per the following specifications. Note: Some functions can initially be function stubs (empty functions), to be completed in later steps. All book names must be unique.</p>
<ul>
<li>Default constructor</li>
<li>Parameterized constructor</li>
<li>Destructor</li>
<li>Public member functions</li>
  <ul>
   <li>SetNext(BooklistNode* nodePtr) - Mutator, sets next to nodePtr</li>
   <li>GetBookName() - Accessor</li>
   <li>GetAuthorName() - Accessor</li>
   <li>GetYearPublished() - Accessor</li>
   <li>GetNext() - Accessor</li>
   <li>string PrintBooklistNode()</li></ul>
<li>Private data members</li>
  <ul>
   <li>string bookName - Initialized to "none" in default constructor</li>
   <li>string authorName - Initialized to "none" in default constructor</li>
   <li>int yearPublished - Initialized to 0 in default constructor</li>
   <li>BooklistNode* next - Initialized to NULL in default constructor</li></ul></ul>

<br/>Ex. of PrintBooklistNode output string:
```
War and Peace
Author Name: Leo Tolstoy
Year Published: 1867
```

<p>Build the BookList class per the following specifications. Note: Some functions can initially be function stubs (empty functions), to be completed in later steps.</p>
<ul>
<li>Default constructor</li>
<li>Destructor -  must  destruct all nodes</li>  
<li>Public member functions</li>
  <ul>
  <li>BooklistNode* getHead() //returns the first node with actual data, if using a dummy node, don't return it as the head</li>
  <li>BooklistNode* getTail() //return the last node with actual data.</li>
  <li>bool add(string, string, int) //adds to the end of the Linked List, returns true if added, returns false if book name already used.</li>
  <li>BooklistNode* found(string bookName)  //returns the pointer to the BooklistNode if found, returns NULL if not found</li>
  <li>bool remove(string bookName) //returns true if book is removed, returns false if book not found</li>
  <li>bool moveFront(string stringName)  //returns true if book moved to front of linked list, returns false if book not found</li>
  <li>string displayAuthor(string authorName)  //displays all books with this authorName. Look at examples for format. Use the 
             PrintBookListNode() from the BookListNode.</li>
  <li>int totalBooks();  //returns total number of books in the linked list</li>
  <li>string displayList();  //returns a string of all books in the linked list. Look at examples for format. Returns null if list is empty.</li></ul>
<li>Private data members</li>
  <ul>
   <li>BooklistNode* head - Initialized to NULL in default constructor</li>
   <li>BooklistNode* tail - Initialized to NULL in default constructor</li></ul></ul>


(2) In main(), prompts the user for the title of the booklist.
<br /><br />
Ex:
```
Enter booklist's title:
Favorites 
```
<br/>and calls the <b>PrintMenu()</b> function. PrintMenu() takes the booklist title as a parameter and displays a menu of options to manipulate the booklist. Each option is represented by a single character. PrintMenu() calls the appropriate function in the BookList class, and outputs messages to the user.

<p>If an invalid character is entered, continues to prompt for a valid choice.</p>

<br/>Ex:
```
Favorites BOOKLIST MENU
a - Add book
d - Remove book
m - Move book to front
s - Output books by specific author
t - Output total number of books in booklist
o - Output full booklist
q - Quit

Choose an option:
```
<br />
(3) Implement the <b>displayList</b> function needed for the "Output full booklist" menu option. If the list is empty, outputs: `Booklist is empty`

</br>Ex:
```
Favorites - OUTPUT FULL PLAYLIST
1.
War and Peace
Author Name: Leo Tolstoy
Year Published: 1867

2.
The Great Gatsby
Author Name: F. Scott Fitzgerald
Year Published: 1925

3.
Moby Dick
Author Name: Herman Melville
Year Published: 1851

4.
Anna Karenina
Author Name: Leo Tolstoy
Year Published: 1877

5. 
The Curious Case of Benjamin Button
Author Name: F. Scott Fitzgerald
Year Published: 1922
```
<br/>(4) Implement the <b>add</b> function needed for the "Add book" menu item. New additions are added to the end of the list. If the book already exists, outputs "This book already exists" and is not added to the linked list

<br/>Ex:
```
ADD BOOK
Enter book's name:
Anna Karenina
Enter author's name:
Leo Tolstoy
Enter year published:
1877
```
<br/>(5) Implement <b>remove</b> for the "Remove book" function. Prompt the user for the name of the book to be removed. If the book is not in the list, outputs "(book name) not in list"

<br/>Ex:
```
REMOVE BOOK
Enter book's name:
The Great Gatsby
"The Great Gatsby" removed
```
<br/>(6) Implement <b>moveFront</b> for the "Move book to front"  menu option. Prompt the user for the name of the book to be moved to the front. If the book is not in the list, outputs "(book name) not in list"

<br/>Ex:
```
MOVE BOOK TO BEGINNING
Enter book's name:
The Great Gatsby
"The Great Gatsby" moved to front of list
```
<br/>(7) Implement <b>displayAuthor</b> for the "Output books by specific author" menu option. Prompt the user for the author's name and output the node's information with this author's name, starting from the beginning of the list.

<br/>Ex:
```
OUTPUT BOOKS BY SPECIFIC AUTHOR
Enter author's name:
Leo Tolstoy

1.
War and Peace
Author Name: Leo Tolstoy
Year Published: 1867

2.
Anna Karenina
Author Name: Leo Tolstoy
Year Published: 1877
```
<br/>(8) Implement <b>totalBooks</b> for the "Output total number of books in booklist" menu option. Output the number of books in the booklist.

<br/>Ex:
```
OUTPUT TOTAL NUMBER OF BOOKS IN BOOKLIST
Total books: 5 books
```

<p>Part of your grade will be making sure that you don't have any memory leaks using Valgrind.</p>

<p>I have provided a <b>testing.cpp</b> for you to do the unit tests in an external IDE and <b>testingGL.cpp</b> do to your Valgrind test.</p>
