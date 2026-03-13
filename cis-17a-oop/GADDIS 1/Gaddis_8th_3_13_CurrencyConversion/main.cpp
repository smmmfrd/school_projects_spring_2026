/*
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 12, 2026
 * Purpose: Convert inputted currency amount in USD to Yen and Euros.
 */

//System Libraries
#include <iomanip>
#include <iostream>  //I/O Library
#include <set>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants
const float YEN_CONVERSION = 98.93;
const float EURO_CONVERSION = 0.74;

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    float input, oYen, oEuro;

    //Initialize all known variables
    cout << "Input amount of USD to convert: $";
    cin >> input;

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    oYen = input * YEN_CONVERSION;
    oEuro = input * EURO_CONVERSION;

    //Display the Inputs/Outputs
    cout << setprecision(2) << fixed;
    cout << "USD: " << setw(5) << "$" << setw(12) << input << endl;
    cout << "JPY: " << setw(6) << "¥" << setw(12) << oYen << endl;
    cout << "EUR: " << setw(7) << "€" << setw(12) << oEuro << endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations