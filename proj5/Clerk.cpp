#include "Clerk.h"

// Constructor
Clerk::Clerk(string fname, string lname, int empNum, double w, int h)
    : Employee(fname, lname, empNum), wage(w), hours(h) {}

// Copy constructor
Clerk::Clerk(Clerk& other)
    : Employee(other.getFname(), other.getLname(), other.getEmpNum()), wage(other.getWage()), hours(other.getHours()) {}

// Destructor
Clerk::~Clerk() {}


// Calculate weekly pay for Clerk
double Clerk::calcWeeklyPay() {
    // Assuming regular pay for the first 40 hours and time-and-a-half for overtime
    const int regularHours = 40;
    const double overtimeMultiplier = 1.5;

    if (hours <= regularHours) {
        return wage * hours;
    } else {
        return wage * regularHours + wage * overtimeMultiplier * (hours - regularHours);
    }
}

// Override toString method
string Clerk::toString() {
    // Using Employee::toString to include Employee details
    return Employee::toString() + " " + to_string(calcWeeklyPay());
}

// Getter methods

string Clerk::getFname() {
    return Employee::getFname();
}

string Clerk::getLname() {
    return Employee::getLname();
}

int Clerk::getEmpNum() {
    return Employee::getEmpNum();
}

double Clerk::getWage() {
    return wage;
}

int Clerk::getHours() {
    return hours;
}