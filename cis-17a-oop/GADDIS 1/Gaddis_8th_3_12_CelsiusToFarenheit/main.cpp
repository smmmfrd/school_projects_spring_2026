/* 
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: Mar 12, 2026
 * Purpose:  Convert inputted Celsius to Farenheit
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
    float input, output;
    
    //Initialize all known variables
    cout << "Input degrees in Celsius to be converted to Farenheit" << endl;
    cin >> input;
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    output = (9.0 * input)/5.0 + 32;

    //Display the Inputs/Outputs
    cout << output << endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations