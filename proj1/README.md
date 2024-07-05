# CMSC340Project 1
Description for the CMSC340 Project 1<br /><br />
(1) Prompt the user to enter a string of their choosing. Store the text in a <b>string</b>. Output the string. 
<br /><br />
Ex:
```
Enter a sample text:
Vanity and pride are different things, though the words are often used synonymously. A person may be    proud without being vain! Pride relates more to our opinion of ourselves, vanity to what we would have others think of us.

You entered: Vanity and pride are different things, though the words are often used synonymously. A person may be    proud without being vain! Pride relates more to our opinion of ourselves, vanity to what we would have others think of us.

```
<br />
(2) Implement a <b>PrintMenu()</b> function, which has a string as a parameter, outputs a menu of user options for analyzing/editing the string, and returns the user's entered menu option.  Each option is represented by a single character. 

If an invalid character is entered, continue to prompt for a valid choice. *Hint: Implement 6 (Quit) before implementing other options.*
Call PrintMenu() in the main() function. Continue to call PrintMenu() until the user enters 6 to Quit.
<br /><br />
Ex:
```
MENU
1 - Number of non-whitespace characters
2 - Number of words
3 - Find text
4 - Replace all !'s
5 - Shorten spaces
6 - Quit

Choose an option:
```
<br />
(3) Implement the <b>GetNumOfNonWSCharacters()</b> function. GetNumOfNonWSCharacters() has a constant string as a parameter and returns the number of characters in the string, excluding all whitespace characters. Call GetNumOfNonWSCharacters() in the PrintMenu() function when the user selects 1 in the menu. 
<br /><br />
Ex:


```
Number of non-whitespace characters: 185
```
<br />
(4) Implement the <b>GetNumOfWords()</b> function. GetNumOfWords() has a constant string as a parameter and returns the number of words in the string. *Hint: Words end when a space is reached except for the last word in a sentence.* Call GetNumOfWords() in the PrintMenu() function when the user selects 2 in the menu.
<br /><br />
Ex:

```
Number of words: 39
```
<br />
(5) Implement the <b>FindText()</b> function, which has two strings as parameters. The first parameter is the text to be found in the user provided sample text, and the second parameter is the user provided sample text. The function returns the number of instances a word or phrase is found in the string. In the PrintMenu() function, prompt the user for a word or phrase to be found and then call FindText() in the PrintMenu() function. Before the prompt, call **cin.ignore()** to allow the user to input a new string.
<br /><br />
Ex:

```
Enter a word or phrase to be found:
vanity
"vanity" instances: 2
```
<br />
(6) Implement the <b>ReplaceExclamation()</b> function. ReplaceExclamation() has a string parameter and updates the string by replacing each '!' character in the string with a '.' character. ReplaceExclamation() DOES NOT output the string. Call ReplaceExclamation() in the PrintMenu() function, and then output the edited string.
<br /><br />
Ex.

```
Vanity and pride are different things, though the words are often used synonymously. A person may be    proud without being vain. Pride relates more to our opinion of ourselves, vanity to what we would have others think of us.
```
<br /><br/>
(7) Implement the <b>ShortenSpace()</b> function. ShortenSpace() has a string parameter and updates the string by replacing all sequences of 2 or more spaces with a single space. ShortenSpace() DOES NOT output the string. Call ShortenSpace() in the PrintMenu() function, and then output the edited string.
<br /><br />
Ex.
```
Edited text: “Vanity and pride are different things, though the words are often used synonymously. A person may be proud without being vain! Pride relates more to our opinion of ourselves, vanity to what we would have others think of us.”
```
