/*
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 13, 2026
 * Purpose: Estimates the population growth of organisms of a number of days.
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
    int startSz, popIncD, dayCount, popCount;

    //Initialize all known variables
    cout << "Calculate population growth..." << endl;

    do {
        cout << "Enter the starting population size: ";
        cin >> startSz;

        if (startSz < 2) {
            cout << "Population starting size must be 2 or greater." << endl;
        }
    } while (startSz < 2);

    do {
        cout << "Enter the daily population increase (as a percentage): %";
        cin >> popIncD;

        if (popIncD < 0) {
            cout << "Please enter a percentage without decimals (like 50%)." << endl;
        }
    } while (popIncD < 0);

    do {
        cout << "Enter the number of days: ";
        cin >> dayCount;

        if (dayCount <= 1) {
            cout << "The experiment must run longer than 1 day." << endl;
        }
    } while (dayCount < 1);

    popCount = startSz;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    for (int i = 0; i < dayCount; i++) {
        cout << (popIncD + 100) / 100.0 << endl;
        popCount *= (popIncD + 100) / 100.0;
    }

    //Display the Inputs/Outputs
    cout << "Population size: " << popCount << " after " << dayCount << " days." << endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations