[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/-_Topwnr)
# CMSC340Project2
Programming Project 2: Online Book Store (F23)
<p>(1) Implement the two files:</p>
<ul>
<li>Book.h - Class declaration (this has been coded for you)</li>
<li>Book.cpp - Class definition</li></ul>
<p>Build the Book class with the following specifications:</p>
<ul>
<li>Default constructor</li>
<li>Parameterized constructor to assign name, author, price, and quantity.</li>
<li>Public class functions (mutators & accessors)</li>
  <ul>
<li>SetName() & GetName()</li>
<li>SetPrice() & GetPrice()</li>
<li>SetAuthor() & GetAuthor()</li>
<li>SetQuantity() & GetQuantity()</li>
<li>PrintBookCost() - Outputs the book name followed by the quantity "@" price "=" total book costs.</li>
<li>PrintBookDescription() - Outputs the book name " by " book author</li>
  </ul>
<li>Private data members</li>
  <ul>
<li>string bookName - Initialized in default constructor to "none"</li>
<li>int bookPrice - Initialized in default constructor to 0</li>
<li>string bookAuthor - Initialized in default constructor to "none"</li>
<li>int bookQuantity - Initialized in default constructor to 0</li></ul></ul>
(2) Implement the two files:
<ul>
<li>ShoppingCart.h - Class declaration (this has been coded for you)</li>
<li>ShoppingCart.cpp - Class definition</li></ul>
<p>Build the ShoppingCart class with the following specifications. Hint: You might want to start with function stubs (empty functions) initially, to be completed in later steps.</p>
<ul>
<li>Default constructor</li>
<li>Parameterized constructor which takes the customer name and date as parameters</li>
<li>Private data members</li>
  <ul>
<li>string customerName - Initialized in default constructor to "none"</li>
<li>string currentDate - Initialized in default constructor to "January 1, 2021"</li>
<li>vector < Book > cartItems</li></ul>
<li>Public member functions</li>
  <ul>
<li>GetCustomerName() accessor</li>
<li>GetDate() accessor</li>
<li>AddItem()</li>
    <ul>
<li>Adds an item to cartItems vector. Has parameters of Book. Does not return anything.</li></ul>
<li>ModifyQuantity()</li>
    <ul>
<li>Modifies the quantity for a book. Has a parameter of string which is the book name.</li>
<li>If item name cannot be found, output this message: Item not found in cart. Nothing modified.</li></ul>
<li>RemoveItem()</li>
    <ul>
<li>Removes item from cartItems vector. Has a string (a book's name) parameter. Does not return anything.</li>
<li>If item name cannot be found, output this message: Item not found in cart. Nothing removed.</li></ul>
<li>GetNumItemsInCart()</li>
    <ul>
<li>Returns quantity of all items in cart. Has no parameters.</li></ul>
<li>GetCostOfCart()</li>
    <ul>
<li>Determines and returns the total cost of items in cart. Has no parameters.</li></ul>
<li>PrintTotal()</li>
    <ul>
<li>Outputs total number of objects in cart.</li>
<li>Outputs each book, the quantity and the net cost.</li>
<li>Outputs the total cost of all items in the cart.</li>
<li>If cart is empty, output this message: SHOPPING CART IS EMPTY</li></ul>
<li>PrintDescriptions()</li>
    <ul>
<li>Outputs each item's name and author.</li>
<li>If cart is empty, output this message: SHOPPING CART IS EMPTY</li></ul></ul></ul>

<br/>Ex. of <b>PrintTotal()</b> output:
```
OUTPUT SHOPPING CART
John Doe's Shopping Cart - February 1, 2021
Number of Items: 8

War and Peace 2 @ $24.99 = $49.98
The Great Gatsby 5 @ $15.99 = $79.95
Moby Dick 1 @ $18.99 = $18.99

Total: $148.92
```
<br/>Ex. of <b>PrintDescriptions()</b> output:
```
OUTPUT ITEMS' DESCRIPTIONS
John Doe's Shopping Cart - February 1, 2021

Item Descriptions
War and Peace by Leo Tolstoy
The Great Gatsby by F. Scott Fitzgerald
Moby Dick by Herman Melville
```
<br/>
(3) In <b>main()</b>, prompt the user for a customer's name and today's date. Output the name and date. Create an object of type ShoppingCart.

Ex.
```
Enter customer's name:
John Doe
Enter today's date:
February 1, 2021

Customer name: John Doe
Today's date: February 1, 2016
```
<br/>
(4) Implement the <b>PrintMenu()</b> function. PrintMenu() has a ShoppingCart parameter, and outputs a menu of options to manipulate the shopping cart. Each option is represented by a single character. Build and output the menu within the function.

If an invalid character is entered, continue to prompt for a valid choice. Hint: Implement Quit before implementing other options. Call PrintMenu() in the main() function. Continue to execute the menu until the user enters q to Quit.

Ex:
```
MENU
a - Add item to cart
d - Remove item from cart
c - Change item quantity
i - Output items' descriptions
o - Output shopping cart
q - Quit

Choose an option:  (place a newline here and extract menu item from next line)
```
<br/>
(5) Implement Output shopping cart menu option. <b>PrintTotal()</b>

Ex:
```
OUTPUT SHOPPING CART
John Doe's Shopping Cart - February 1, 2021
Number of Items: 8

War and Peace 2 @ $24.99 = $49.98
The Great Gatsby 5 @ $15.99 = $79.95
Moby Dick 1 @ $18.99 = $18.99

Total: $148.92
```
<br/>
(6) Implement Output item's description menu option. <b>PrintDescriptions()</b>:

Ex.
```
OUTPUT ITEMS' DESCRIPTIONS
John Doe's Shopping Cart - February 1, 2016

Item Descriptions
War and Peace by Leo Tolstoy
The Great Gatsby by F. Scott Fitzgerald
Moby Dick by Herman Melville
```
<br/>
(7) Implement Add item to cart menu option. <b>AddItem()</b>:

Ex:
```
ADD ITEM TO CART
Enter the book name:
War and Peace
Enter the book author:
Leo Tolstoy
Enter the book price:
24.99
Enter the book quantity:
2
```
<br/>
(8) Implement remove item menu option. <b>RemoveItem()</b>:

Ex:
```
REMOVE ITEM FROM CART
Enter name of item to remove:
The Great Gatsby
```
<br/>
(9) Implement change Item quantity menu option. <b>ModifyQuantity()</b>:

Ex:
```
CHANGE ITEM QUANTITY
Enter name of item to change quantity:
The Great Gatsby
Enter the new quantity:
5
```
<p>I have provided a testing.cpp file that has some unit tests that you can run externally before uploading your files to Zylab and running the tests.</p>

<br/>

<p><b></b>Grading:</b></p>
<ul>
<li>80 - Test Cases</li>
<li>5 - Working Makefile (screenshot)</li>
<li>5 - Comments within code</li>
<li>5 - Reflection - In 3+ paragraphs, highlight your lessons learned and learning experience from working on this project.
How did you do? What have you learned? What did you struggle with? How will you approach your next project differently?</li>
<li>5 - UML diagram</li></ul>



<p><b>What to test in Zylab:</b></p>
<ol>
<li>Book.h</li>
<li>Book.cpp</li>
  <li>ShoppingCart.h</li>
<li>ShoppingCart.cpp</li>
<li>main.cpp</li></ol>



<p><b>What to turn in on Blackboard - Programming Project 2</b></p>
<ol>
<li>Makefile</li>
<li>screenshot of Makefile working</li>
<li>.docx or .pdf with Reflection and UML diagram</li></ol>
