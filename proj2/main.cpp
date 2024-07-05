#include <iostream>
#include "ShoppingCart.h"
using namespace std;

// Function to display the menu and get user's choice
char PrintMenu(){
   char choice;
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
   cout << "Choose an option: ";
   cin >> choice;
   return choice;
}
int main() {

   /* Type your code here. */

   string customerName, currentDate;
   cout << "Enter customer's name: ";
   // Remove any lingering newline character
   cin.ignore();

   // Read the customer's name (including spaces)
   getline(cin, customerName);

   cout << "Enter today's date: ";

   // Read the current date
   getline(cin, currentDate);

   cout << "\nCustomer name: " << customerName << endl;
   cout << "Today's date: " << currentDate << endl;

   // ShoppingCart object with the customer's name and date
   ShoppingCart cart(customerName, currentDate);

   char choice;
   do {
      choice = PrintMenu();
      switch (choice) {
         case 'a':
         // Implementing the Add item to cart menu option
         {
            string bookName, bookAuthor;
            double bookPrice;
            int bookQuantity;

            cout << "Enter the book name: ";
            // Remove any lingering newline character
            cin.ignore();
            getline(cin, bookName);

            cout << "Enter the book author: ";
            getline(cin, bookAuthor);

            cout << "Enter the book price: ";
            cin >> bookPrice;

            cout << "Enter the book quantity: ";
            cin >> bookQuantity;

            // Creating a Book object w/ the details
            Book newBook(bookName, bookAuthor, bookPrice, bookQuantity);

            // Adding the Book to the shopping cart 
            cart.AddItem(newBook);
            break;
         }
         case 'd':
         // Implementing the RemoveItem menu option
         {
            string itemName;
            cout << "Enter name of item to remove: ";
            // Remove any lingering newline character
            cin.ignore();
            getline(cin, itemName);

            // Removing the item from the shopping cart
            cart.RemoveItem(itemName);
            break;
         }
         case 'c':
         // Implementing the ModifyQuantity menu option
         {
            string itemName;
            int newQuantity;
            cout << "Enter name of item to change quantity: ";
            // Removing any lingering newline character
            cin.ignore();
            getline(cin, itemName);

            cout << "Enter the new quantity: ";
            cin >> newQuantity;

            // Modifying the item's quantity in the shopping cart
            cart.ModifyQuantity(itemName, newQuantity);
            break;
         }
         case 'i':
         // Implementing the PrintDescriptions menu option
         {
            // Prints the descriptions of items in the shopping cart
            cout << cart.PrintDescriptions() << endl;
            break;
         }
         case 'o':
         // Implementing the PrintTotal menu option
         {
            // Prints the total cost and details of items in the shopping cart
            cout << cart.PrintTotal() << endl;
            break;
         }
        case 'q':
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Please choose a valid option from the menu." << endl; 
      }
   } while (choice != 'q');
      return 0;
}   
   




