/*
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 13, 2026
 * Purpose:  Output the days in the month of the given year.
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    bool leapYr = false;
    int iMonth, iYear;

    //Initialize all known variables
    cout << "Enter a month (1-12): ";
    cin >> iMonth;

    if (iMonth < 1 || iMonth > 12) {
        cout << "Invalid month" << endl;
        return 0;
    }

    cout << "Enter a year: ";
    cin >> iYear;

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    if (iYear % 100 == 0) {
        if (iYear % 400 == 0) {
            leapYr = true;
        }
    } else {
        if (iYear % 4 == 0) {
            leapYr = true;
        }
    }

    //Display the Inputs/Outputs
    switch (iMonth) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << 30;
            break;
        case 2:
            if (leapYr) {
                cout << 29;
            } else {
                cout << 28;
            }
    }

    cout << " days" << endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations