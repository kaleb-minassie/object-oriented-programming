/*
 * testing.cpp
 *
 *  Created on: Jul 31, 2023
 *      Author: User
 */
#include <iostream>
#include <string>
using namespace std;

int GetNumOfNonWSCharacters(const string usrStr);
int GetNumOfWords(const string usrStr);
int FindText(const string toFind, string usrStr);
void ReplaceExclamation(string& usrStr);
void ShortenSpace(string& usrStr);
char PrintMenu(string& usrStr);

bool testGetNumOfNonWSCharacters() {

	string str = "Vanity and pride are different things, though the words are often used synonymously. A person may be    proud without being vain! Pride relates more to our opinion of ourselves, vanity to what we would have others think of us.";
	   int result = GetNumOfNonWSCharacters(str);

	   if (result == 185) {
	      cout << "GetNumOfNonWSCharacters() returns the correct amount." << endl;
	      return true;
	   }

	   else {
	      cout << "GetNumOfNonWSCharacters() incorrectly returned " << result << "." << endl;
	      return false;
	   }
}

bool testGetNumOfNonWSCharactersA() {
   string str = "Vanity and pride are different things, though the words are often used synonymously.";
   int result = GetNumOfNonWSCharacters(str);

   if (result == 72) {
      cout << "GetNumOfNonWSCharacters() returns the correct amount." << endl;
      return true;
   }

   else {
      cout << "GetNumOfNonWSCharacters() incorrectly returned " << result << "." << endl;
      return false;
   }
}

bool testGetNumOfNonWSCharactersB() {
   string str = "This is a   test.";
   int result = GetNumOfNonWSCharacters(str);

   if (result == 12) {
      cout << "GetNumOfNonWSCharacters() returns the correct amount." << endl;
      return true;
   }

   else {
      cout << "GetNumOfNonWSCharacters() incorrectly returned " << result << "." << endl;
      return false;
   }
}

bool testGetNumOfNonWSCharactersC() {
   string str = "Now is the time for all good men to come to the aid of their country.";
   int result = GetNumOfNonWSCharacters(str);

   if (result == 54) {
      cout << "GetNumOfNonWSCharacters() returns the correct amount." << endl;
      return true;
   }

   else {
      cout << "GetNumOfNonWSCharacters() incorrectly returned " << result << "." << endl;
      return false;
   }
}

bool testGetNumOfNonWSCharactersD() {
   string str = "We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!";
   int result = GetNumOfNonWSCharacters(str);

   if (result == 181) {
      cout << "GetNumOfNonWSCharacters() returns the correct amount." << endl;
      return true;
   }

   else {
      cout << "GetNumOfNonWSCharacters() incorrectly returned " << result << "." << endl;
      return false;
   }
}

bool testGetNumOfWords() {

   string str = "Vanity and pride are different things, though the words are often used synonymously. A person may be    proud without being vain! Pride relates more to our opinion of ourselves, vanity to what we would have others think of us.";
   int result = GetNumOfWords(str);

   if (result == 39) {
      cout << "GetNumOfWords() returns the correct amount." << endl;
      return true;
   }

   else {
      cout << "GetNumOfWords() incorrectly returned " << result << "." << endl;
      return false;
   }
}

bool testGetNumOfWordsA() {

   string str = "Now is the time for all good men to come to the aid of their country.";
   int result = GetNumOfWords(str);

   if (result == 16) {
      cout << "GetNumOfWords() returns the correct amount." << endl;
      return true;
   }

   else {
      cout << "GetNumOfWords() incorrectly returned " << result << "." << endl;
      return false;
   }
}

bool testGetNumOfWordsB() {

   string str = "This is a     test.";
   int result = GetNumOfWords(str);

   if (result == 4) {
      cout << "GetNumOfWords() returns the correct amount." << endl;
      return true;
   }

   else {
      cout << "GetNumOfWords() incorrectly returned " << result << "." << endl;
      return false;
   }
}

bool testFindText() {
   string str = "We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!";
   string phrase = "more";
   int result = FindText(phrase, str);

   if(result == 5){
      cout << "FindText() returns the correct amount." << endl;
      return true;
   }
   else{
      cout << "FindText() incorrectly returns " << result << "." << endl;
      return false;
   }
}

bool testFindTextA() {
   string str = "The baseball pitcher asked for a pitcher of water.";
   string phrase = "pitcher";
   int result = FindText(phrase, str);

   if(result == 2){
      cout << "FindText() returns the correct amount." << endl;
      return true;
   }
   else{
      cout << "FindText() incorrectly returns " << result << "." << endl;
      return false;
   }
}

bool testFindTextB() {
   string str = "I want some water. I had some water earlier, but now he has some water.";
   string phrase = "some water";
   int result = FindText(phrase, str);

   if(result == 3){
      cout << "FindText() returns the correct amount." << endl;
      return true;
   }
   else{
      cout << "FindText() incorrectly returns " << result << "." << endl;
      return false;
   }
}

bool testReplaceExclamation() {
   string str = "We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!";

   ReplaceExclamation(str);

   if (str == "We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue.") {
      cout << "ReplaceExclamation() correctly edits the string." << endl;
      return true;
   }
   else {
      cout << "ReplaceExclamation() incorrectly edits the string." << endl;
      cout << "Result: " << str << endl;
      return false;
   }
}

bool testReplaceExclamationA() {
   string str = "Now!!! It is the time for all good men to come to the aid of their country!";

   ReplaceExclamation(str);

   if (str == "Now... It is the time for all good men to come to the aid of their country.") {
      cout << "ReplaceExclamation() correctly edits the string." << endl;
      return true;
   }
   else {
      cout << "ReplaceExclamation() incorrectly edits the string." << endl;
      cout << "Result: " << str << endl;
      return false;
   }
}

bool testReplaceExclamationB() {
   string str = "I have a test! I am not prepared!";

   ReplaceExclamation(str);

   if (str == "I have a test. I am not prepared.") {
      cout << "ReplaceExclamation() correctly edits the string." << endl;
      return true;
   }
   else {
      cout << "ReplaceExclamation() incorrectly edits the string." << endl;
      cout << "Result: " << str << endl;
      return false;
   }
}

bool testShortenSpace() {
   string str = "We'll continue our quest in space.  there will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  nothing ends here;  our hopes and our journeys continue!";
   string ans = "We'll continue our quest in space. there will be more shuttle flights and more shuttle crews and, yes, more volunteers, more civilians, more teachers in space. nothing ends here; our hopes and our journeys continue!";
   ShortenSpace(str);

   if (str == ans) {
      cout << "ShortenSpace() correctly edits the string."<< endl;
      return true;
   }
   else {
      cout << "ShortenSpace() incorrectly edits the string." << endl;
      cout << "Result: " << str << endl;
      return false;
   }
}

bool testShortenSpaceA() {
   string str = "Now   is the  time  for all good    men to come  to the  aid of their   country.";
   string ans = "Now is the time for all good men to come to the aid of their country.";
   ShortenSpace(str);

   if (str == ans) {
      cout << "ShortenSpace() correctly edits the string."<< endl;
      return true;
   }
   else {
      cout << "ShortenSpace() incorrectly edits the string." << endl;
      cout << "Result: " << str << endl;
      return false;
   }
}

bool testShortenSpaceB() {
   string str = "There are  too  many    spaces    here.     Why?";
   string ans = "There are too many spaces here. Why?";
   ShortenSpace(str);

   if (str == ans) {
      cout << "ShortenSpace() correctly edits the string."<< endl;
      return true;
   }
   else {
      cout << "ShortenSpace() incorrectly edits the string." << endl;
      cout << "Result: " << str << endl;
      return false;
   }
}

bool testPrintMenu() {
   string str = "Hello World.";
   char result;
   cout << "Instructions: enter a 2\n";
   result = PrintMenu(str);
   if (result == '2') {
      cout << "PrintMenu() correctly returns the correct menu option."<< endl;
      return true;
   }
   else {
      cout << "PrintMenu() incorrectly returns the correct menu option of " << result << endl;
      return false;
   }
}

bool testPrintMenuA() {
   string str = "Hello World.";
   char result;
   cout << "Instructions: enter a 7, then a 6\n";
   result = PrintMenu(str);
   if (result == '6') {
      cout << "PrintMenu() correctly returns the correct menu option."<< endl;
      return true;
   }
   else {
      cout << "PrintMenu() incorrectly returns the correct menu option of " << result << endl;
      return false;
   }
}

int main() {
//int mainA() {
	int score = 0;
    bool passed;
    cout << "UNIT TEST - GetNumOfNonWSCharacters" << endl;
    passed = testGetNumOfNonWSCharacters();
    if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - GetNumOfNonWSCharactersA" << endl;
    passed = testGetNumOfNonWSCharactersA();
    if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - GetNumOfNonWSCharactersB" << endl;
    passed = testGetNumOfNonWSCharactersB();
    if(passed) {cout << "You PASSED this unit test\n\n";score+=2;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - GetNumOfNonWSCharactersC" << endl;
    passed = testGetNumOfNonWSCharactersC();
    if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - GetNumOfNonWSCharactersD" << endl;
        passed = testGetNumOfNonWSCharactersD();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=2;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - GetNumOfWords" << endl;
    passed = testGetNumOfWords();
    if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - GetNumOfWordsA" << endl;
        passed = testGetNumOfWordsA();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - GetNumOfWordsB" << endl;
        passed = testGetNumOfWordsB();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=2;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - FindText" << endl;
        passed = testFindText();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - FindTextA" << endl;
        passed = testFindTextA();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - FindTextB" << endl;
        passed = testFindTextB();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - ReplaceExclamation" << endl;
        passed = testReplaceExclamation();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - ReplaceExclamationA" << endl;
        passed = testReplaceExclamationA();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - ReplaceExclamationB" << endl;
        passed = testReplaceExclamationB();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=2;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - ShortenSpace" << endl;
        passed = testShortenSpace();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - ShortenSpaceA" << endl;
        passed = testShortenSpaceA();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - ShortenSpaceB" << endl;
        passed = testShortenSpaceB();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=2;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - PrintMenu" << endl;
        passed = testPrintMenu();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=4;} else cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - PrintMenu" << endl;
        passed = testPrintMenuA();
        if(passed) {cout << "You PASSED this unit test\n\n";score+=8;} else cout << "You DID NOT PASS this unit test\n\n";

    cout << "\n\nTOTAL SCORE: "<<score<<" / 70" << endl;
    return 0;
}
