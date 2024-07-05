/*
 * main.cpp
 *
 *  Created on: Jul 31, 2023
 *      Author: Professor Kartchner
 */
#include <iostream>
#include <string>
using namespace std;

/*Give definitions to all functions*/

// Counts non-whitespace characters in a string
int GetNumOfNonWSCharacters(const string usrStr){
   int count = 0,i;
   int length = usrStr.size();
   for(i=0;i<length;i++){
      if (!isspace(usrStr[i])){
         count++;
      }
   }
   return count;
}
// Counts the number of words in a string
int GetNumOfWords(const string usrStr) {
   int count = 0,i;
   int length = usrStr.size();
   for(i=0;i<length;i++){
      if (isspace(usrStr[i])){
         // Handles the multiple spaces
         i++;
         // Increments the words
         i--;
         count++;
      }
   }
   // Handles the last word
   count += 1;
   return count;
}
// Finds and counts instances of a word or phrase in a string
int FindText(const string toFind, string usrStr) {
int count = 0;
size_t pos = 0;
while ((pos = usrStr.find(toFind, pos)) != string::npos){
   count++;
   pos = pos + toFind.length(); 
}
return count;
}
// Replacing the '!' with '.'
void ReplaceExclamation(string& usrStr)
 {
   int length = usrStr.size();
   for (int i = 0; i < length;i++) {
   if (usrStr[i] == '!'){
      usrStr[i] = '.';
   }
  }
}
// Replacing multiple spaces to a single space
void ShortenSpace(string& usrStr) {
int i,length = usrStr.size();
string newUsrStr = "";
for (i=0; i<length; i++){
   if(isspace(usrStr[i])){
      // Skips the current space
      i++;
      // Decrements the string length
      i--;
      newUsrStr += " ";
   } else {
      // Adds a single space to the new string 
      newUsrStr += usrStr[i];
   }
}
      // Adds non-whitespace characters to the new string
      newUsrStr = usrStr;
}
// Prints the menu and retrieves user's choice
char PrintMenu(string& usrStr) {
   cout << "\nMENU" << endl;
   cout << "1 - Number of non-whitespace characters" << endl;
   cout << "2 - Number of words" << endl;
   cout << "3 - Find text" << endl;
   cout << "4 - Replace all !'s with ." << endl;
   cout << "5 - Shorten spaces" << endl;
   cout << "6 - Quit" << endl;

   cout << "Choose an option: ";
   char choice;
   cin >> choice;
   // Processes newline character
   cin.ignore();
   string searchWord;
   switch (choice) {
      case '1':
      cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(usrStr) << endl;
      break;
      case '2':
      cout << "Number of words: " << GetNumOfWords(usrStr) << endl;
      break;
      case '3':
      cout << "Enter a word or phrase to find: ";
      getline(cin, searchWord);
      cout << "\"" << searchWord << "\" instances: " << FindText(searchWord, usrStr) << endl;
      break;
      case '4':
      ReplaceExclamation(usrStr);
      cout << "Text after replacing !'s with .: " << usrStr << endl;
      break;
      case '5':
      ShortenSpace(usrStr);
      cout << "Text after shortening spaces: " << usrStr << endl;
      break;
      case '6':
      cout << "Goodbye!" << endl;
      break;
      default:
      cout << "Invalid choice. Please try again." << endl;

   }
   return choice;
}

int main() {

   /* Type your main code here. */
   string userInput;
   // Prompts the user to enter a sample text
   cout << "Enter a sample text:" << endl;
   getline(cin, userInput);

   // Display the entered text
   cout << "You entered: " << userInput << endl;
   char userChoice;

   // Displaying the menu until the user chooses to quit
   do{
      userChoice = PrintMenu(userInput);
   
} while (userChoice != '6');
   return 0;
}


