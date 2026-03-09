/* 
 * File: format-output.cpp
 * Author: Sam Mumford
 * Date: March 7, 2026
 * Purpose: Display mastery over output manipulation
 */

//System Libraries - Post Here
#include <iostream>
//Library for our functions utilized in this question.
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    float a, b, c, d;
    
    //Initialize or input data here
    cin >> a >> b >> c >> d;
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cout << fixed;
    cout << setprecision(0) << setw(9) << a << setprecision(1) << setw(10) << a << setprecision(2) << setw(10) << a <<endl;
    cout << setprecision(0) << setw(9) << b << setprecision(1) << setw(10) << b << setprecision(2) << setw(10) << b <<endl;
    cout << setprecision(0) << setw(9) << c << setprecision(1) << setw(10) << c << setprecision(2) << setw(10) << c <<endl;
    cout << setprecision(0) << setw(9) << d << setprecision(1) << setw(10) << d << setprecision(2) << setw(10) << d;
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}