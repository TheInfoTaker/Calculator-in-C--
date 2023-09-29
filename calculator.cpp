#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

// Function for performing addition
int addition() {
    int a;
    int b;
    int sum;

    cout << "Start by entering a number: \n";
    cin >> a;

    cout << "Enter a second number: \n";
    cin >> b;

    sum = a + b;

    cout << "The sum of those numbers is " << sum << endl;

    // Open the file for appending (ios::app)
    ofstream outfile("calculations.txt", ios::app);
    if (outfile.is_open()) {
        // Save the calculation result to the file
        outfile << a << " + " << b << " = " << sum << endl;
        outfile.close();
        cout << "Calculation saved" << endl;
    } else {
        cerr << "Cannot open file for saving." << endl;
    }

    return 0;
}

// Function for performing subtraction
int subtraction() {
    int c;
    int d;
    int dif;

    cout << "Start by entering a number: \n";
    cin >> c;

    cout << "Enter a second number: \n";
    cin >> d;

    dif = c - d;

    cout << "The difference of those numbers is " << dif << endl;

    // Open the file for appending (ios::app)
    ofstream outfile("calculations.txt", ios::app);
    if (outfile.is_open()) {
        // Save the calculation result to the file
        outfile << c << " - " << d << " = " << dif << endl;
        outfile.close();
        cout << "Calculation saved" << endl;
    } else {
        cerr << "Cannot open file for saving." << endl;
    }

    return 0;
}

// Function for loading calculation history from a file
int loadCalculations() {
    string line;
    ifstream infile("calculations.txt");

    if (infile.is_open()) {
        cout << "Calculations History:" << endl;
        // Read and display each line from the file
        while (getline(infile, line)) {
            cout << line << endl;
        }
        infile.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
    }

    return 0;
}

int main() {
    int choice;

    //Displays a menue that repeats the options until the user selects quit
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Load" << endl;
        cout << "4. Save" << endl;
        cout << "5. Quit" << endl;
        cout << "Select An Option: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                loadCalculations();
                break;
            case 4:
                cout << "Calculations saved." << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Select again." << endl;
        }
    }
    return 0;
}
