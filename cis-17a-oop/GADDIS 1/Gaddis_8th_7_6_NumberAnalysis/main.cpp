/*
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 14, 2026
 * Purpose: Analyze array of random numbers
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants
const int SIZE = 100;
//Function Prototypes
bool read(unsigned short array[]);    // Read in numbers.txt, returns false if could not
void stats(unsigned short array[]);  // Prints the smallest, biggest, sum, and average of the array.

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    bool gdRead;
    unsigned short numbers[SIZE];

    //Initialize all known variables
    gdRead = read(numbers);

    if (!gdRead) {
        return 0;
    }

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    stats(numbers);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
bool read(unsigned short array[]) {
    int index = 0;

    fstream fInput;

    fInput.open("numbers.txt");

    if (!fInput.is_open()) {
        cout << "Could not open file" << endl;
        return false;
    }

    while (fInput >> array[index]) {
        index++;
    }

    fInput.close();
    return true;
}

void stats(unsigned short array[]) {
    int lowest = array[0], highest = array[0], sum = 0;

    for (unsigned short index = 0; index < SIZE; index++) {
        if (array[index] < lowest) {
            lowest = array[index];
        }

        if (array[index] > highest) {
            highest = array[index];
        }

        sum += array[index];
    }

    cout << "Lowest: " << lowest << endl;
    cout << "Highest: " << highest << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << sum / SIZE << endl;
}