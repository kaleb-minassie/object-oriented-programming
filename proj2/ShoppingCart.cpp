#include "ShoppingCart.h"
#include <iostream>
/* Type your code here */

// Default constructor
ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2021";
}

// Constructor with parameters
ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

// Getters
string ShoppingCart::GetCustomerName() const {
    return customerName;
}
string ShoppingCart::GetDate() const {
    return currentDate;
}

// Adds an item to cartItems vector
void ShoppingCart::AddItem(Book item) {
    cartItems.push_back(item);
}

// Modifies the quantity for a book
void ShoppingCart::ModifyQuantity(string bookName, int quantity) {
    bool found = false;
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName() == bookName) {
            cartItems[i].SetQuantity(quantity);
            found = true;
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

// Removes item from cartItems vector
void ShoppingCart::RemoveItem(string name) {
    bool found = false;
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName() == name) {
            cartItems.erase(cartItems.begin() + i);
            found = true;
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

// Returns quantity of all the items in the cart
int ShoppingCart::GetNumItemsInCart() {
    int totalQuantity = 0;
    for (const Book& item : cartItems) {
        totalQuantity = totalQuantity + item.GetQuantity();  
     }
     return totalQuantity;
}

// Prints the total number of objects in cart, each book, quantity, and total cost
string ShoppingCart::PrintTotal() {
    double totalCost = GetCostOfCart();
    int totalQuantity = GetNumItemsInCart();

    if (cartItems.empty()) {
        return "SHOPPING CART IS EMPTY";
    }

    string costSum = "OUTPUT SHOPPING CART\n" + GetCustomerName() + "'s Shopping Cart - " + GetDate() + "\nNumber of Items: " + to_string(totalQuantity) + "\n";

    for (const Book& item : cartItems) {
        costSum = costSum + item.GetName() + " " + to_string(item.GetQuantity()) + " @ $" + to_string(item.GetPrice()) + " = $" + to_string(item.GetPrice() * item.GetQuantity()) + "\n";
    }

    costSum = costSum + "\nTotal: $" + to_string(totalCost);
    return costSum;
}

// Prints each book's name and author
string ShoppingCart::PrintDescriptions() {
    if (cartItems.empty()) {
        return "SHOPPING CART IS EMPTY";
    }

    string costSum = "OUTPUT ITEMS' DESCRIPTIONS\n" +GetCustomerName() + "'s Shopping Cart - " + GetDate() + "\nItem Desccription\n";

    for (const Book& item : cartItems) {
        costSum = costSum + item.GetName() + " by " + item.GetAuthor() + "\n"; 
    }
    return costSum;
}
