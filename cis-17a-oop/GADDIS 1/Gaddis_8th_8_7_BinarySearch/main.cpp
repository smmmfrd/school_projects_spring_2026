/*
* File:   template.cpp
 * Author: Sam Mumford
 * Created: March 14, 2026
 * Purpose: Implement a sort and binary search on an array of strings
 *          To make this one more interesting I'm going to be doing
 *          to be implementing the database sort.
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void sort(string array[], int indexes[], int numElems);
int binarySearch(const string array[], int indexes[], int numElems, string value);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                                "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                                "Taylor, Terri", "Johnson, Jill",
                                "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                                "James, Jean", "Weaver, Jim", "Pore, Bob",
                                "Rutherford, Greg", "Javens, Renee",
                                "Harrison, Rose", "Setzer, Cathy",
                                "Pike, Gordon", "Holland, Beth" };

    int foundIndex = -1;
    int indexes[NUM_NAMES];
    string target = names[16];

    //Initialize all known variables
    for (int i = 0; i < NUM_NAMES; i++) {
        indexes[i] = i;
    }

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    sort(names, indexes, NUM_NAMES);

    //Display the Inputs/Outputs
    cout << "Original array: " << endl;
    for (int i = 0; i < NUM_NAMES; i++) {
        cout << i << ". " << names[i] << endl;
    }
    cout << endl << "With sorted indexes: " << endl;
    for (int i = 0; i < NUM_NAMES; i++) {
        cout << i << ". " << names[indexes[i]] << endl;
    }

    cout << endl << "Finding " << target << "..." << endl;
    foundIndex = binarySearch(names, indexes, NUM_NAMES, target);
    if (foundIndex < 0) {
        cout << "Could not find" << endl;
    } else {
        cout << "Found at index: " << foundIndex << " of sorted array.";
        cout << " Index " << indexes[foundIndex] << " of unsorted array." << endl;
    }

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

void swap(char &a, char &b) {
    a = a^b;
    b = a^b;
    a = a^b;
}

void sort(string array[], int indexes[], int numElems) {
    int compare;
    bool swapped = false;

    do {
        swapped = false;

        for (int i = 1; i < numElems; i++) {
            compare = array[indexes[i - 1]].compare(array[indexes[i]]);
            if (compare > 0) {
                swap(indexes[i - 1], indexes[i]);
                swapped = true;
            }
        }
    } while(swapped);
}

//Function Implementations
int binarySearch(const string array[], int indexes[], int numElems, string value)
{
    int first = 0, last = numElems - 1, position = -1;
    int compare, middle;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        compare = array[indexes[middle]].compare(value);
        if (compare == 0) {
            // If value is found at mid
            found = true;
            position = middle;
        }
        else if (compare > 0) {
            // If value is in lower half
            last = middle - 1;
        } else {
            first = middle + 1; // If value is in upper half
        }
    }
    return position;
}