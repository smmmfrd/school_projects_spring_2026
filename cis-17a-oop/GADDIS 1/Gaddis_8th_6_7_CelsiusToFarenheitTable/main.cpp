/*
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 14, 2026
 * Purpose: Create a table of temperatures converted from
 *          Fahrenheit to Celsius of 0-20 degrees.
 */

//System Libraries
#include <iomanip>
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
float celsius(float fahrenheit); // Returns the input to celsius

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int start = 0, end = 20;

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    cout << "Fahrenheit" << setw(12) << "Celsius" << endl;
    for (int i = start; i <= end; i++) {
        cout << setw(5) << i << setw(16) << setprecision(2) << fixed << celsius(i) << endl;
    }

    //Display the Inputs/Outputs

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
float celsius(float fahrenheit) {
    return (fahrenheit - 32.0f) * 5.0f / 9.0f;
}