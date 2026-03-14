/*
 * File:   template.cpp
 * Author: Sam Mumford
 * Created: March 14, 2026
 * Purpose: Implement Luhn Algorithm to generate credit card numbers.
 *          Fun part is that we have to generate the last digit on our own.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void prpLuhn(string&, int);
int rndNum();
int charVal(char);
void luhn(string&);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));

    //Declare all variables for this function
    const int PLSIZE = 10; // The Pre Luhn Size
    string cardNum;

    //Initialize all known variables
    prpLuhn(cardNum, PLSIZE);
    luhn(cardNum);

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << cardNum << endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations

void luhn(string& target) {
    int sum = 0;
    int temp = 0;
    cout << "gonna luhn this so hard " << target << endl;
    for (int i = 0; i < target.length() - 1; i++) {
        temp = (target[i] - '0') * (i % 2 == 0 ? 1 : 2);
        if (temp > 9) {
            temp -= 9;
        }
        sum += temp;
    }
    cout << (sum * 9) % 10 << endl;
    target[target.length() - 1] = ((sum * 9) % 10) + '0';
}

void prpLuhn(string& target, int length) {
    for (int i = 0; i < length; i++) {
        target += rndNum() + '0';
    }
    target += 'x';
}

int rndNum() {
    return rand() % 10;
}

int charVal(char c) {
    return c - '0';
}