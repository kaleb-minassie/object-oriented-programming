#include "Stylist.h"

// Constructor
Stylist::Stylist(string fname, string lname, int empNum, double pay, int num)
    : Employee(fname, lname, empNum), payrate(pay), numAppts(num) {}

// Copy constructor
Stylist::Stylist(Stylist& other)
    : Employee(other.getFname(), other.getLname(), other.getEmpNum()), payrate(other.getPay()), numAppts(other.getNumAppts()) {}

// Destructor
Stylist::~Stylist() {}


// Calculate weekly pay for Stylist
double Stylist::calcWeeklyPay() {
    // Stylist receives a fixed amount of money per appointment
    return payrate * numAppts;
}

// Override toString method
string Stylist::toString() {
    // Using Employee::toString to include Employee details
    return Employee::toString() + " " + to_string(calcWeeklyPay());
}

// Getter methods

string Stylist::getFname() {
    return Employee::getFname();
}

string Stylist::getLname() {
    return Employee::getLname();
}

int Stylist::getEmpNum() {
    return Employee::getEmpNum();
}

double Stylist::getPay() {
    return payrate;
}

int Stylist::getNumAppts() {
    return numAppts;
}