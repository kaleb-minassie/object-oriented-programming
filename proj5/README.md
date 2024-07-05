[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/VYGiI-n0)
# CMSC340Project5
Pete’s Pets has four types of employees. 
<ul>
<li><b>Managers</b>, who receive a fixed weekly salary </li>
<li><b>Clerks</b>, who receive a fixed hourly wage for up to the first 40 hours they work and "time-and-a-half," i.e., 1.5 times their hourly wage, for overtime hours worked</li>
<li><b>Vets</b>, who receive $800 plus $3.75 for each vaccine they administer</li>
<li><b>Stylists</b>, who receive a fixed amount of money per appointment.  </li></ul>

<p>Create a program that calculates the weekly pay for employees of "Pete's Pets", the total payroll and print's out a Weekly Pay Report.</p>

<p>You do not know the number of employees in the file in advance.  </p>
<br>Each type of employee has its own pay code:  
<br>Managers have paycode <b>1</b>
<br>Clerks have code <b>2</b>
<br>Vets have code <b>3</b>
<br>Stylists have code <b>4 </b>
<br/><br/>
<p>Input will come from a sequential file that has a line for each employee.  
<br>The first item in the line will always be the <b>paycode</b>.  
<br>The second and third item will be the <b>first and last name</b>.  
<br>The fourth item will be the <b>employee ID</b><br/>. 
For a paycode of 1, the salary will be the next item.  If the pay code is 2, hourly salary is the next item followed by hours worked.  If the pay code is 3, the next item will be the number of vaccines administered.  If the pay code is 4, the next item will be the payrate per appointment followed by the number of appointments. All items in a line of the file are separated by a space. </p>


<p>You have been provided with the following classes:
  <ul>
<li>Employee.h (simple class, no need for .cpp file)</li>
<li>main.cpp</li>
<li>tests.cpp (tests same as the ones in the lab)</li>
<li>testsGL.cpp (this is the one to run on the gl server and get a valgrind report on)</li></ul></p>

<p>Requirements:</p>
<ol>
<li><p>Implement <b>4 derived classes that inherit from Employee</b> (these are your Data Element classes). You have been given the .h files for each of these.
<br>(a) Manager
<br>(b) Clerk
<br>(c) Stylist
<br>(d) Vet
<br>They will contain variables appropriate for the type of employee.  They inherit from Employee and define the virtual method(s).  There should also be getter and setters, and any other methods that are needed for your design.  The constructor should call the constructor of the Employee class. The toString method will override the Employee toString method and use the Employee::toString method within the implementation. Provide a destructor. Use const to represent any constants.</p></li>

<li><p>Create a Data Manager class called <b>Employees</b>. You have been provided with the .h file.
It will contain a vector that holds pointers to Employee objects that will accommodate pointers to Manager, Clerk, Stylist and Vet objects. Add any other variables needed for your design including numManagers, numClerks, numStylist and numVets, which will be incremented when you add an Employee of this type.
<p>Employees will contain the following functions:</p>
<p>(a) <b>void addEmployee(string)</b>. The string passed in will be one line from the input file. Use the paycode to determine what is to be extracted from the string. Create the correct type of object and add it to the vector.</p>
<p>(b) <b>double calculateWeeklyPay()</b>. Returns the sum of weekly pay for all objects in the vector.</p>
<p>(c) <b>string printReport()</b>. Returns a string with the Weekly Pay Report. The employees are sorted by employee number in the report. (The necessary methods and overloaded operators needed for the sort are provided for you.)The Employee Number and First and Last Names are printed in a column of width 25. The Weekly Pay is printed in a column of width 10. Total Payroll will be printed as well as the number of each type of employee. Look at the example output to see the details of the Weekly Pay Report. All pay must be printed with 2 decimal places. </p>
<p>(d) <b>Rule of 3 - Copy constructor, Destructor, operator= </b>. You will need the clone() for the copy constructor and =.</p>
<p>(e) <b>Default constructor</b></p></p></li>
</ol>

<p>Any additional functions you may need for your design must be private utility functions.</p>
<p>**** Make sure any .h files you need for the derived classes are put in the Employees.h, not the Employees.cpp</p>

<p>main.cpp will read from the file and print out the report.</p>

Given the following input file:
```
4 Paul Johnson 44444 8.75 75
1 Eric Hall 11111 1200.00
3 Katie Bell 33333 55
2 Patrick Brown 22222 12.50 50
```
The following report will be printed:
```
Weekly Pay Report for Pete's Pets

Employee                 Weekly Pay
11111 Eric Hall             1200.00
22222 Patrick Brown          687.50
33333 Katie Bell            1006.25
44444 Paul Johnson           656.25

Total payroll: 3550.00
Managers: 1
Clerks: 1
Vets: 1
Stylist: 1
```
<p>You have been provided with two data files - employees.txt and employeesA.txt</p>
<p>You have been provided with two testing files - tests.cpp and testsGL.cpp that you will use to test your program on the gl server and run a valgrind report.</p>
