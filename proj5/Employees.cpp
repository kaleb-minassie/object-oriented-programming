#include "Employees.h"
#include <iostream>

// Default constructor
Employees::Employees() {
    workers = new vector<Employee*>;
    numManagers = numClerks = numVets = numStylists = 0;
}

// Destructor
Employees::~Employees() {
    for (auto& worker : *workers) {
        delete worker;
    }
    delete workers;
}

// Copy constructor
Employees::Employees(const Employees& other) {
    workers = new vector<Employee*>;
    numManagers = other.numManagers;
    numClerks = other.numClerks;
    numVets = other.numVets;
    numStylists = other.numStylists;

    for (const auto& worker : *(other.workers)) {
        workers->push_back(worker->clone());
    }
}

// Overloaded assignment operator
Employees& Employees::operator=(const Employees& other) {
    if (this != &other) {
        // Clear existing data
        for (auto& worker : *workers) {
            delete worker;
        }
        delete workers;

        // Copy new data
        workers = new vector<Employee*>;
        numManagers = other.numManagers;
        numClerks = other.numClerks;
        numVets = other.numVets;
        numStylists = other.numStylists;

        for (const auto& worker : *(other.workers)) {
            workers->push_back(worker->clone());
        }
    }
    return *this;
}

// Function to add an employee based on the input line
void Employees::addEmployee(string line) {
    istringstream iss(line);
    int payCode;
    iss >> payCode;

    switch (payCode) {
        case 1: {
            // Manager
            string fname, lname;
            int empNum;
            double salary;
            iss >> fname >> lname >> empNum >> salary;
            workers->push_back(new Manager(fname, lname, empNum, salary));
            numManagers++;
            break;
        }
        case 2: {
            // Clerk
            string fname, lname;
            int empNum, hours;
            double wage;
            iss >> fname >> lname >> empNum >> wage >> hours;
            workers->push_back(new Clerk(fname, lname, empNum, wage, hours));
            numClerks++;
            break;
        }
        case 3: {
            // Vet
            string fname, lname;
            int empNum;
            double numVac;
            iss >> fname >> lname >> empNum >> numVac;
            workers->push_back(new Vet(fname, lname, empNum, numVac));
            numVets++;
            break;
        }
        case 4: {
            // Stylist
            string fname, lname;
            int empNum, numAppts;
            double payrate;
            iss >> fname >> lname >> empNum >> payrate >> numAppts;
            workers->push_back(new Stylist(fname, lname, empNum, payrate, numAppts));
            numStylists++;
            break;
        }
        default:
            // Handle invalid payCode
            cout << "Invalid payCode: " << payCode << endl;
            break;
    }
}

// Function to calculate the total weekly pay for all employees
double Employees::calculateWeeklyPay() {
    double totalPay = 0.0;
    for (const auto& worker : *workers) {
        totalPay += worker->calcWeeklyPay();
    }
    return totalPay;
}

// Function to print the weekly pay report
  string Employees::printReport() {
    ostringstream report;
    report << "Weekly Pay Report for Pete's Pets\n\n";
    report << left << setw(25) << "Employee" << right << setw(15) << "Weekly Pay\n";

    // Sort employees by employee number
    sort(workers->begin(), workers->end(), compareEmployees);

    for (const auto& worker : *workers) {
        report << left << setw(25) << worker->toString() << right << fixed << setprecision(2) << setw(15) << worker->calcWeeklyPay() << endl;
    }

    report << "Total payroll: " << fixed << setprecision(2) << calculateWeeklyPay() << endl;
    report << "Managers: " << numManagers << endl;
    report << "Clerks: " << numClerks << endl;
    report << "Vets: " << numVets << endl;
    report << "Stylist: " << numStylists << endl;

    return report.str();
}




// to sort the vector by Employee Number using the compareEmployees function
// sort(vectorName->begin(), vectorName->end(), compareEmployees);