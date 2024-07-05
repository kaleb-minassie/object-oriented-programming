#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 8;
const int COLS = 5;
const int GOLD_PRICE = 22;
const int SILVER_PRICE = 20;
const int NON_MEMBER_PRICE = 18;

// Function to get seat information from the user
void getSeat(int& row, char& seat, int& membership)
{
    cout << "Enter row number (1-8) or -1 to quit: ";
    cin >> row;
    if (row != -1)
    {
        cout << "Enter seat letter (A-E): ";
        cin >> seat;
        cout << "Choose your membership: \n0. Not a member.\n1. Silver. \n2. Gold.\n";
        cin >> membership;
    }
}

// Function to display the theater layout
void displayLayout(char layout[ROWS][COLS])
{
    cout << "###############" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << layout[i][j] << " ";
        }
        cout << endl;
    }
    cout << "###############" << endl;
}

// Function to display the sales report
void displaySalesReport(int sales[], int seatsSold)
{
    cout << "Sales Report:" << endl;
    cout << "Gold members: $" << sales[0] << endl;
    cout << "Silver members: $" << sales[1] << endl;
    cout << "Non-members: $" << sales[2] << endl;
}

int main()
{
    // Theater layout array
    char layout[ROWS][COLS] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'A', 'X', 'C', 'D', 'E'},
        {'A', 'B', 'C', 'D', 'E'},
        {'A', 'B', 'C', 'D', 'E'},
        {'A', 'B', 'C', 'D', 'E'},
        {'A', 'B', 'C', 'D', 'E'},
        {'A', 'B', 'C', 'D', 'E'},
        {'A', 'B', 'C', 'D', 'E'}
    };

    int sales[3] = { 0 }; // Sales array to track revenue
    int seatsSold = 0; // Counter for total seats sold
    int row; // User-input row number
    char seat; // User-input seat letter
    int membership; // User-input membership type

    displayLayout(layout); // Display the initial theater layout

    getSeat(row, seat, membership); // Get seat information from the user

    while (row != -1)
    {
        // Check if the selected seat is available
        if (layout[row - 1][toupper(seat) - 'A'] == 'X')
        {
            cout << "Sorry, that seat is not available." << endl;
        }
        else
        {
            layout[row - 1][toupper(seat) - 'A'] = 'X'; // Mark the seat as occupied
            seatsSold++; // Increment the seats sold counter

            // Calculate and update sales based on membership type
            switch (membership)
            {
            case 2:
                sales[0] += GOLD_PRICE; // Gold membership
                break;
            case 1:
                sales[1] += SILVER_PRICE; // Silver membership
                break;
            default:
                sales[2] += NON_MEMBER_PRICE; // Non-member
                break;
            }
        }

        displayLayout(layout); // Display the updated theater layout
        getSeat(row, seat, membership); // Get seat information for the next customer
    }

    // Display sales report and summary
    cout << "Number of seats sold: " << seatsSold << endl;
    cout << "Percentage occupied: " << fixed << setprecision(2) << (double)seatsSold / (ROWS * COLS) * 100 << "%" << endl;
    displaySalesReport(sales, seatsSold);

    return 0;
}
