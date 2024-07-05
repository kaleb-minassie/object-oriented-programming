#include "Employees.h"
#include "Employee.h"
#include "Manager.h"
#include "Clerk.h"
#include "Vet.h"
#include "Stylist.h"
#include <iostream>
#include <fstream>
using namespace std;

bool testPassedClerkNoOvertime() {
    Employees employees;
    Employee* employee;
    Clerk* clerk;
    int numClerks, empNum;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    numClerks = employees.getNumClerks();
    employees.addEmployee("2 Patrick Brown 22222 12.50 40");
    numClerks = employees.getNumClerks();

    if (numClerks == 1) {
        employee = employees.getFirst();
        clerk = static_cast<Clerk*>(employee);
        pay = clerk->calcWeeklyPay();
        empNum = clerk->getEmpNum();
        lname = clerk->getLname();
        fname = clerk->getFname();

        if (pay == 500.00) {
            if (fname.compare("Patrick") == 0) {
                if (lname.compare("Brown") == 0) {
                    if (empNum == 22222) {

                        return true;
                    }
                    else {

                        return false;
                    }
                }
                else {

                    return false;
                }
            }
            else {

                return false;
            }
        }
        else {

            return false;
        }
    }

    else {


        return false;
    }
}

bool testPassedClerkOvertime() {
    Employees employees;
    Employee* employee;
    Clerk* clerk;
    int numClerks, empNum;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    numClerks = employees.getNumClerks();

    employees.addEmployee("2 Patrick Brown 22222 12.50 50");

    numClerks = employees.getNumClerks();


    if (numClerks == 1) {
        employee = employees.getFirst();
        clerk = static_cast<Clerk*>(employee);
        pay = clerk->calcWeeklyPay();
        empNum = clerk->getEmpNum();
        lname = clerk->getLname();
        fname = clerk->getFname();
        if (pay == 687.50) {
            if (fname.compare("Patrick") == 0) {
                if (lname.compare("Brown") == 0) {
                    if (empNum == 22222) {

                        return true;
                    }
                    else {

                        return false;
                    }
                }
                else {

                    return false;
                }
            }
            else {

                return false;
            }
        }
        else {

            return false;
        }
    }

    else {


        return false;
    }
}

bool testPassedManager() {
    Employees employees;
    Employee* emp;
    Manager* employee;
    int numManagers, empNum;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    numManagers = employees.getNumManagers();

    employees.addEmployee("1 Eric Hall 11111 1200.00");

    numManagers = employees.getNumManagers();


    if (numManagers == 1) {
        emp = employees.getFirst();
        employee = static_cast<Manager*>(emp);
        pay = employee->calcWeeklyPay();
        empNum = employee->getEmpNum();
        lname = employee->getLname();
        fname = employee->getFname();
        if (pay == 1200.00) {
            if (fname.compare("Eric") == 0) {
                if (lname.compare("Hall") == 0) {
                    if (empNum == 11111) {

                        return true;
                    }
                    else {

                        return false;
                    }
                }
                else {

                    return false;
                }
            }
            else {

                return false;
            }
        }
        else {

            return false;
        }
    }

    else {


        return false;
    }
}

bool testPassedVet() {
    Employees employees;
    Employee* emp;
    Vet* employee;
    int numVets, empNum;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    numVets = employees.getNumVets();

    employees.addEmployee("3 Katie Bell 33333 55");

    numVets = employees.getNumVets();


    if (numVets == 1) {
        emp = employees.getFirst();
        employee = static_cast<Vet*>(emp);
        pay = employee->calcWeeklyPay();
        empNum = employee->getEmpNum();
        lname = employee->getLname();
        fname = employee->getFname();
        if (pay == 1006.25) {
            if (fname.compare("Katie") == 0) {
                if (lname.compare("Bell") == 0) {
                    if (empNum == 33333) {

                        return true;
                    }
                    else {

                        return false;
                    }
                }
                else {

                    return false;
                }
            }
            else {

                return false;
            }
        }
        else {
            return false;
        }
    }

    else {

        return false;
    }
}

bool testPassedStylist() {
    Employees employees;
    Employee* emp;
    Stylist* employee;
    int numStylists, empNum;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    numStylists = employees.getNumStylists();
    employees.addEmployee("4 Paul Johnson 44444 8.75 75");
    numStylists = employees.getNumStylists();

    if (numStylists == 1) {
        emp = employees.getFirst();
        employee = static_cast<Stylist*>(emp);
        pay = employee->calcWeeklyPay();
        empNum = employee->getEmpNum();
        lname = employee->getLname();
        fname = employee->getFname();
        if (pay == 656.25) {
            if (fname.compare("Paul") == 0) {
                if (lname.compare("Johnson") == 0) {
                    if (empNum == 44444) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    else {

        return false;
    }
}

bool testPassedCalcWeeklyPay() {
    Employees employees;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    employees.addEmployee("4 Paul Johnson 44444 8.75 75");
    employees.addEmployee("1 Eric Hall 11111 1200.00");
    employees.addEmployee("3 Katie Bell 33333 55");
    employees.addEmployee("2 Patrick Brown 22222 12.50 50");

    pay = employees.calculateWeeklyPay();

    if (pay == 3550.00) {
        return true;
    }

    else {
        return false;
    }
}

bool testPassedCopyconstructor() {
    Employees employees, employees2;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay, pay2;

    employees.addEmployee("4 Paul Johnson 44444 8.75 75");
    employees.addEmployee("1 Eric Hall 11111 1200.00");
    employees.addEmployee("3 Katie Bell 33333 55");
    employees.addEmployee("2 Patrick Brown 22222 12.50 50");

    pay = employees.calculateWeeklyPay();

    if (pay == 3550.00) {
        Employees employees2(employees);
        employees2.addEmployee("2 Georgia Jones 10111 12.50 40");
        pay2 = employees2.calculateWeeklyPay();
        pay = employees.calculateWeeklyPay();
        if (pay2 == 4050.00 && pay == 3550.00) {

            return true;
        }
        else {
            return false;
        }
    }

    else {
        return false;
    }
}

bool testPassedEquals() {
    Employees employees, employees3;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay, pay3;

    employees.addEmployee("4 Paul Johnson 44444 8.75 75");
    employees.addEmployee("1 Eric Hall 11111 1200.00");
    employees.addEmployee("3 Katie Bell 33333 55");
    employees.addEmployee("2 Patrick Brown 22222 12.50 50");

    pay = employees.calculateWeeklyPay();

    if (pay == 3550.00) {
        employees3 = employees;
        employees3.addEmployee("2 Georgia Jones 10111 13.50 40");
        pay3 = employees3.calculateWeeklyPay();
        pay = employees.calculateWeeklyPay();
        if (pay3 == 4090.00 && pay == 3550.00) {

            return true;
        }
        else {

            return false;
        }
    }

    else {
        return false;
    }
}

bool testPassedPrintReportEmployee() {
    Employees employees;

    ifstream in;
    string line;
    string fileName = "employees.txt";
    string result;
    char result1[80];
    int empNum;
    double total;

    in.open(fileName);
    if (!in) {
        cout << "Could not open file: " << fileName << endl;
        return false;
    }

    //read a line and add to employees
    while (!in.eof()) {
        getline(in, line);
        employees.addEmployee(line);
    }
    //report
    istringstream inp(employees.printReport());
    inp.getline(result1, 80, '\n'); //"Weekly Pay Report for Pete's Pets"
    inp.getline(result1, 80, '\n'); //empty line
    inp.getline(result1, 80, '\n'); //"Employee      Weekly Pay"
    inp >> empNum;
    if (empNum != 11111) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 22222) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 33333) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 44444) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp.getline(result1, 80, '\n'); //empty line
    inp >> result; //"Total"
    inp >> result; //"payroll"
    inp >> total;
    if (((total - 3550.00) > .01))
    {
        return false;
    }
    inp >> result; //"Managers"
    inp >> total;
    if (total != 1) {
        return false;
    }
    inp >> result; //"Clerks"

    inp >> total;
    if (total != 1) {
        return false;
    }
    inp >> result; //"Vets"
    inp >> total;
    if (total != 1) {
        return false;
    }
    inp >> result; //"Sylist"
    inp >> total;
    if (total != 1) {
        return false;
    }
    return true;

}

bool testPassedPrintReportEmployeeA() {
    Employees employees;

    ifstream in;
    string line;
    string fileName = "employeesA.txt";
    string result;
    char result1[80];
    int empNum;
    double total;

    in.open(fileName);
    if (!in) {
        cout << "Could not open file: " << fileName << endl;
        return false;
    }

    //read a line and add to employees
    while (!in.eof()) {
        getline(in, line);
        employees.addEmployee(line);
    }
    //report
    istringstream inp(employees.printReport());
    inp.getline(result1, 80, '\n'); //"Weekly Pay Report for Pete's Pets"
    inp.getline(result1, 80, '\n'); //empty line
    inp.getline(result1, 80, '\n'); //"Employee      Weekly Pay"
    inp >> empNum;
    if (empNum != 11111) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 12345) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 22222) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 23456) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 33333) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 34567) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 44444) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 45678) {
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp.getline(result1, 80, '\n'); //empty line
    inp >> result; //"Total"
    inp >> result; //"payroll"
    inp >> total;
    if (((total - 6193.00) > .01))
    {
        return false;
    }
    inp >> result; //"Managers"
    inp >> total;
    if (total != 1) {
        return false;
    }
    inp >> result; //"Clerks"

    inp >> total;
    if (total != 2) {
        return false;
    }
    inp >> result; //"Vets"
    inp >> total;
    if (total != 3) {
        return false;
    }
    inp >> result; //"Sylist"
    inp >> total;
    if (total != 2) {
        return false;
    }
    return true;

}


int main() {
    bool passed;
    cout << "UNIT TEST - addEmployee clerk no overtime" << endl;
    passed = testPassedClerkNoOvertime();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - addEmployee clerk overtime" << endl;
    passed = testPassedClerkOvertime();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - addEmployee manager" << endl;
    passed = testPassedManager();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - addEmployee vet" << endl;
    passed = testPassedVet();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - addEmployee stylist" << endl;
    passed = testPassedStylist();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - CalcWeeklyPay" << endl;
    passed = testPassedCalcWeeklyPay();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - copy constructor" << endl;
    passed = testPassedCopyconstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - Equals Operator" << endl;
    passed = testPassedEquals();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - printReport (employees.txt)" << endl;
    passed = testPassedPrintReportEmployee();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - printReport (employeesA.txt)" << endl;
    passed = testPassedPrintReportEmployeeA();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    return 0;
}
