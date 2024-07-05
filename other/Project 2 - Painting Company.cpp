#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
void displayTitle();
void getData(double& length, double& width);
void convert12Format(int& hour, char& period);
int calcSqMeter(double length, double width);
int calcTotalCans(int sqMeter);
double calcCost(int totalCans);
void displayResults(int sqMeter, int totalCans, double cost, const string& dateTime, const string& dayOfWeek, string MonthName, int day, int year);
bool isLeapYear(int year);
int getYearValue(int year);
string getMonthNumber(int month);
int getMonthValue(int month, int year);
int getDayOfWeek(int day, int month, int year);
void displayMsg(int totalCans);

int main() {
    // Display program title
    displayTitle();

    // Main loop
    double length, width;
    while (true) {
        getData(length, width);
        if (length == 0)
            break;

        // Calculate square meter, total cans, and cost
        int sqMeter = calcSqMeter(length, width);
        int totalCans = calcTotalCans(sqMeter);
        double cost = calcCost(totalCans);

        // Get transaction date and time
        int hour, minute;
        cout << "Enter the transaction time in 24-hour notation:\n";
        cout << "Hour: ";
        cin >> hour;
        cout << "Minute: ";
        cin >> minute;
        char period;
        convert12Format(hour, period);


        int day, month, year;
        cout << "Enter the transaction date (dd mm yyyy): ";
        cin >> day >> month >> year;

        // Calculate day of the week
        string dateTime = to_string(hour) + ":" + (minute < 10 ? "0" + to_string(minute) : to_string(minute)) + " " + (period == 'p' ? "PM" : "AM");
        string dayOfWeekStr;
        switch (getDayOfWeek(day, month, year)) {
        case 0:
            dayOfWeekStr = "Sunday";
            break;
        case 1:
            dayOfWeekStr = "Monday";
            break;
        case 2:
            dayOfWeekStr = "Tuesday";
            break;
        case 3:
            dayOfWeekStr = "Wednesday";
            break;
        case 4:
            dayOfWeekStr = "Thursday";
            break;
        case 5:
            dayOfWeekStr = "Friday";
            break;
        case 6:
            dayOfWeekStr = "Saturday";
            break;
        }

        // Get month name
        string MonthName = getMonthNumber(month);

        // Display results
        displayResults(sqMeter, totalCans, cost, dateTime, dayOfWeekStr, MonthName, day, year);
        displayMsg(totalCans);
    }

    cout << "Thank you for using the program." << endl;
    return 0;
}

// Function to display the program title
void displayTitle() {
    cout << "\t  Rainbow Painting Company" << endl;
    cout << "\t\tPainting Costing" << endl;
    cout << "\t--------------------------------" << endl;
}

// Function to get input data from the user
void getData(double& length, double& width) {
    cout << "Enter the length in meters (0 to stop)... ";
    cin >> length;
    if (length != 0) {
        cout << "Enter the width in meters................ ";
        cin >> width;
    }
}

// Function to convert 24-hour format to 12-hour format
void convert12Format(int& hour, char& period) {
    if (hour >= 12) {
        period = 'p';
        if (hour > 12)
            hour -= 12;
    }
    else {
        period = 'a';
        if (hour == 0)
            hour = 12;
    }
}

// Function to calculate the square meter
int calcSqMeter(double length, double width) {
    int ceiling = static_cast<int>(length * width);
    int walls = static_cast<int>((2 * length + 2 * width) * 3);
    return ceiling + walls;
}

// Function to calculate the total cans needed
int calcTotalCans(int sqMeter) {
    return (sqMeter + 19) / 20;  // Round up to the nearest whole number
}

// Function to calculate the total cost
double calcCost(int totalCans) {
    return totalCans * 15.50;
}

// Function to display the painting results
void displayResults(int sqMeter, int totalCans, double cost, const string& dateTime, const string& dayOfWeek, string MonthName, int day, int year) {
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Area" << setw(41) << "= " << sqMeter << " square meters" << endl;
    cout << "Cans" << setw(41) << "= " << totalCans << endl;
    cout << "Cost" << setw(41) << "= $" << fixed << setprecision(2) << cost << endl;
    cout << "\t\t\t\t\t\t\t" << endl;
    cout << "Date/Time:" << setw(31) << dayOfWeek << ", " << MonthName << " " << day << ", " << year << " " << dateTime << endl;
}

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the year value
int getYearValue(int year) {
    return (year / 4) - (year / 100) + (year / 400);
}

// Function to get the month number
string getMonthNumber(int month) {
    switch (month) {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "Invalid month";
    }
}

// Function to get the month value
int getMonthValue(int month, int year) {
    switch (month) {
    case 1:
        return isLeapYear(year) ? 6 : 0;
    case 2:
    case 3:
    case 11:
        return 3;
    case 4:
    case 7:
        return 6;
    case 5:
        return 1;
    case 6:
        return 4;
    case 8:
        return 2;
    case 9:
    case 12:
        return 5;
    default:
        return -1;  // Invalid month
    }
}

// Function to get the day of the week
int getDayOfWeek(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return d;
}

// Function to display the gift message based on the number of cans
void displayMsg(int totalCans) {
    cout << "Gift: ";
    if (totalCans >= 1 && totalCans <= 3) {
        cout << "Free paint brush" << endl;
    }
    else if (totalCans >= 4 && totalCans <= 7) {
        cout << "Free paint tray" << endl;
    }
    else if (totalCans > 7) {
        cout << "$10 gift card" << endl;
    }
    else {
        cout << "No gift" << endl;
    }

    cout << "\nThank you for your purchase." << endl;
    cout << "=============================================================================" << endl;
}

