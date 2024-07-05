#include "Fraction.h"
#include "utilities.h"
#include <numeric>
#include <string>
using namespace std;

//These functions are used for testing.

//Default constructor
Fraction::Fraction(){
	numerator = 0;
	denominator = 1;
}
//Constructor with parameters
Fraction::Fraction(int numerator, int denominator) {
	if(denominator != 0) {
		this->numerator = numerator;
		this->denominator = denominator;
		int factor = gcd(this->numerator, this->denominator);
		this->numerator = this->numerator / factor;
		this->denominator = this->denominator / factor;
		} else {
			//Setting default values for the numerator
			//and the denominator if denominator is 0
			this->numerator = 0;
			this->denominator = 1;
		}
}
//Copy constructor for initializing a fraction from one that already exists
Fraction::Fraction(const Fraction& number) {
	numerator = number.numerator;
	denominator = number.denominator;
}
//Conversion constructor for a vector of two ints into a fraction
Fraction::Fraction(vector<int> number) {
	if (number.size() == 2) {
		numerator = number[0];
		denominator = number[1];
		//Simplifying the fraction
		int factor = gcd(numerator, denominator);
		numerator = numerator / factor;
		denominator = denominator / factor;
	} else {
		//Setting default values if the 
		//vector doesn't have two elements
		numerator = 0;
		denominator = 1; 
	}
}
//Destructor
Fraction::~Fraction(){};
//Overloaded addition operator to perform addition b/w fractions
Fraction Fraction::operator+(const Fraction rhs) {
	int commonDenom = lcm(denominator, rhs.denominator);
	int newNum = (numerator * (commonDenom / denominator)) + (rhs.numerator * (commonDenom / rhs.denominator));
	return Fraction(newNum, commonDenom);
}
//Overloaded subtraction operator to perform subtraction b/w fractions
Fraction Fraction::operator-(const Fraction rhs) {
	int commonDenom = lcm(denominator, rhs.denominator);
	int newNum = (numerator * (commonDenom / denominator)) - (rhs.numerator * (commonDenom / rhs.denominator));
	return Fraction(newNum, commonDenom);
}
//Overloaded multiplication operator to perform multiplication b/w fractions
Fraction Fraction::operator*(const Fraction rhs) {
	int newNum = numerator * rhs.numerator;
	int newDenom = denominator * rhs.denominator;
	return Fraction(newNum, newDenom);
}
//Overloaded division operator to perform division b/w fractions
Fraction Fraction::operator/(const Fraction rhs) {
	int newNum = numerator * rhs.denominator;
	int newDenom = denominator * rhs.numerator;
	return Fraction(newNum, newDenom);
}
//Overloaded assignment operator to copy the values from the right-hand side fraction to the left-hand side fraction
Fraction& Fraction::operator=(const Fraction& rhs) {
	if (this != &rhs) {
		numerator = rhs.numerator;
		denominator = rhs.denominator;
	}
	return *this;
}
//Overloaded equality operator to compare fractions for equality
bool Fraction::operator==(const Fraction& rhs) {
	// Simplifying both fractions before comparison
    int commonFactor = gcd(numerator, denominator);
    int commonFactorRhs = gcd(rhs.numerator, rhs.denominator);
	// Calculating the simplified numerators
	int simplifiedThisNumerator = numerator / commonFactor;
	int simplifiedRhsNumerator = rhs.numerator / commonFactorRhs;
	// Calculating the simplified denominators
	int simplifiedThisDenominator = denominator / commonFactor;
	int simplifiedRhsDenominator = rhs.denominator / commonFactorRhs;
    return (simplifiedThisNumerator == simplifiedRhsNumerator) && (simplifiedThisDenominator == simplifiedRhsDenominator);
}
//Overloaded less than '<' operator
bool Fraction::operator<(const Fraction& rhs) {
	//Finding the least common denominator b/w two fractions
	int commonDenom = lcm(denominator, rhs.denominator);
	//Calculating the numerator for the current object after making denominators equal
	int currNum = numerator * (commonDenom / denominator);
	//Calculating the numerator for the rhs fraction after making denominators equal
	int rhsNumerator = rhs.numerator * (commonDenom / rhs.denominator);
	//Comparing the two numerators to see if current fraction < rhs (right-hand side) fraction
	return currNum < rhsNumerator;
}
//Overloaded the greater than '>' operator
bool Fraction::operator>(const Fraction& rhs) {
	//Finding the least common denominator b/w two fractions
	int commonDenom = lcm(denominator, rhs.denominator);
	//Calculating the numerator for the current object after making denominators equal
	int currNum = numerator * (commonDenom / denominator);
	//Calculating the numerator for the rhs fraction after making denominators equal
	int rhsNumerator = rhs.numerator * (commonDenom / rhs.denominator);
	//Comparing the two numerators to see if current fraction > rhs (right-hand side) fraction
	return currNum > rhsNumerator;
}
//Overloaded output stream operator to print out fractions
ostream& operator<<(ostream& out, const Fraction number) {
	//Prints fractions in the "numerator/denominator" format
	out << number.numerator << "/" << number.denominator;
	return out;
}
//Overloaded input stream operator to input fractions
istream& operator>>(istream& in, Fraction& number) {
	int num, denom;
	in >> num;
	in.ignore(); //Ignoring the '/'
	in >> denom;
	if (denom != 0) {
		number.setFraction(num,denom);
	} else {
		number.setFraction(0,1);
	}
	return in;
} 
//Checking if the fraction is in default state
bool Fraction::isDefault() const {
	return (numerator == 0) && (denominator == 1);
}
//Converting fraction to a string representation
string Fraction::toString() const {
	return to_string(numerator) + "/" + to_string(denominator);
}
//Setters and getters

//setFraction doesn't call simplify
void Fraction::setFraction(int numerator, int denominator) {
	if (denominator != 0) {
		this->numerator = numerator;
		this->denominator = denominator;
	}
	else {
		numerator = 0;
		denominator = 1;
	}
}
//Retrieves the numerator
int Fraction::getNumerator() const { return numerator; }
//Retrieves the denominator
int Fraction::getDenominator() const { return denominator; }

//returns a vector with the numerator as the first element and the denominator as the second element
vector<int> Fraction::getFraction() {
	vector<int> result;
	result.push_back(numerator);
	result.push_back(denominator);
	return result;
}