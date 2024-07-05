#include "Manager.h"

// Constructor
Manager::Manager(string fname, string lname, int empNum, double sal)
    : Employee(fname, lname, empNum), salary(sal) {}

// Copy constructor
Manager::Manager(Manager& other)
    : Employee(other.getFname(), other.getLname(), other.getEmpNum()), salary(other.getSalary()) {}

// Destructor
Manager::~Manager() {}


// Calculate weekly pay for Manager
double Manager::calcWeeklyPay() {
    // Manager receives a fixed weekly salary
    return salary;
}

// Override toString method
string Manager::toString() {
    // Using Employee::toString to include Employee details
    return Employee::toString() + " " + to_string(calcWeeklyPay());
}

// Getter methods

string Manager::getFname() {
    return Employee::getFname();
}

string Manager::getLname() {
    return Employee::getLname();
}

int Manager::getEmpNum() {
    return Employee::getEmpNum();
}

double Manager::getSalary() {
    return salary;
}
