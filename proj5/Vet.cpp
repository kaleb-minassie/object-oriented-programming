#include "Vet.h"

// Constructor
Vet::Vet(string fname, string lname, int empNum, double numVac)
    : Employee(fname, lname, empNum), numVaccines(numVac) {}

// Copy constructor
Vet::Vet(Vet& other)
    : Employee(other.getFname(), other.getLname(), other.getEmpNum()), numVaccines(other.getNumVac()) {}

// Destructor
Vet::~Vet() {}


// Calculate weekly pay for Vet
double Vet::calcWeeklyPay() {
    // Vet receives a base pay plus additional pay per vaccine administered
    return basePay + (numVaccines * vacPay);
}

// Override toString method
string Vet::toString() {
    // Using Employee::toString to include Employee details
    return Employee::toString() + " " + to_string(calcWeeklyPay());
}

// Getter methods

string Vet::getFname() {
    return Employee::getFname();
}

string Vet::getLname() {
    return Employee::getLname();
}

int Vet::getEmpNum() {
    return Employee::getEmpNum();
}

double Vet::getNumVac() {
    return numVaccines;
}