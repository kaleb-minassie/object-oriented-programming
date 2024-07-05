[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/SUEzcFCs)
# CMSC340Project4
<p>Create a class called <b>Fraction</b> for performing arithmetic functions with fraction. You will separate the interface (.h) from the implementation (.cpp).  You have been provided with a driver/client program that will use this class. You have also been provided a <b>utilities.h</b> file which contains the gcd, simplify and lcm (least common multiple) functions.</p>

<p>Fractions have the form
		Numerator / Denominator
and will always be stored/displayed in the reduced form</p>

<p>1. Implement the Function class.</p>
<ul>
<li><b>Fraction.h</b> - Class declaration (provided for you)</li>
<li><b>Fraction.cpp</b> - Class definition</li></ul>

<p>Use int variables to represent the private data of the class.  There are only two private members: an int to represent the numerator and an int to represent the denominator. </p>

<p>(a) Provide the following constructors:
<br>      <b>default constructor</b>- give initial values of 0 for the numerator and 1 for the denominator
<br>      <b>parameterized constructor</b> - give initial values for the numerator and denominator from the constructor parameters. If the denominator is 0, use the default values for the numerator and denominator. Simplify the fraction.
<br>      <b>copy constructor</b> - initial values from an object that already exists
<br>      <b>conversion constructor</b> - converts a vector of two ints into a Function. Initial value for numerator will be the first int in the vector and initial value for denominator is second int in the vector.</p>

<p>(b) Provide a <b>destructor</b></p>

<p>(c) Provide the following <b>overloaded operators:</b>
<br>	+, -, *, /, =, ==, <, ></p>

<p>(d) Overload the <b>>></b> and <b><<</b> operators. The << operator will print out a Fraction in the form:<b> numerator/denominator</b>. Use this operator to print out fractions to the screen. Use the >> operator to input fractions from the keyboard.</p>

<p>(e) Provide implementations for the following functions:
<br>        <b> bool isDefault() const;</b> //returns false if a numerator and denominator were entered (numerator != 0 || denominator != 1), 
		//returns true if default then no numerator or denominator were entered
<br>        <b> string toString() const;</b> //returns string representative of fraction, if numerator = 4 and denominator = 5, returns 4/5</p>

<p><br>       //These functions are used for testing, and are provided for you
<br>		void setFraction(int numerator, int denominator);
<br>		int getNumerator() const;
<br>		int getDenominator() const;
<br>		vector getFraction();

<br>2. Provided for you  <b>main.cpp</b> - main() function
```
MENU
a. Input fraction A
b. Input fraction B

For menu items 1-9, you must have entered a fraction A and B

1. A + B
2. A - B
3. B - A
4. A * B
5. A < B
6. A > B
7. A == B
8. A = B
9. A / B
p - Print A and B
e - Exit

Choose an option:
```

<br/>Examples: Fraction A is 3/4 and Fraction B is 2/3
```
1. A + B

3/4 + 2/3 = 17/12
```

```
2. A - B

3/4 - 2/3 = 1/12
```
```
3. B - A

2/3 - 3/4 = -1/12  (Notice that the - goes in front of the numerator if the result is negative)
```
```
4. A * B

3/4 * 2/3 = 1/2  (Notice the result has been reduced)
```
```
5. A < B

A=3/4 B=2/3
A < B is: false
```
```
6. A > B

A=3/4 B=2/3
A > B is: true
```
```
7. A == B

A=3/4 B=2/3
A == B is: false
```
```
8. A = B

A=3/4 B=2/3
A = B: A=2/3 B=2/3
```
```
9. A / B

A=4/5 B=2/3
4/5 / 2/3 = 6/5
```
```
p. Print A and B

A=3/4 B=2/3
```

