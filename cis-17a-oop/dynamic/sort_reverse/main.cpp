/* 
 * File:   main.cpp
 * Author: Sam Mumford
 * Created on: March 17, 2026
 * Purpose:  Calculate the median of a dynamic array of integers.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &); // Return the array size and the array
void prntDat(int *,int); // Print the integer array
int *sort(const int *,int); //Sort smallest to largest
int *reverse(const int *,int); //Sort in reverse order

int main(){
    // Get the array size
    int arySize;
    cin >> arySize;
    
    // Get the array
    int *ary = getData(arySize);
    
    int *sorted = sort(ary, arySize);
    int *reversd = reverse(sorted, arySize);
    
    prntDat(sorted, arySize);
    cout << endl;
    prntDat(reversd, arySize);
    
    delete []ary;
    delete []sorted;
    delete []reversd;
	return 0;
}

//Return the array size and the array
int *getData(int &arySize) {
    int input, index = 0;
    
    int *newAry = new int[arySize];
    
    while (cin >> input) {
        newAry[index] = input;
        index++;
    }
    
    return newAry;
}

//Print the integer array
void prntDat(int *ary, int arySize) {
    for (int i = 0; i < arySize; i++) {
        cout << ary[i];
        
        if (i != arySize - 1) {
            cout << " ";
        }
    }
}

void swap(int &a, int &b) {
    a = a^b;
    b = a^b;
    a = a^b;
}

//Sort smallest to largest
int *sort(const int *ary, int arySize) {
    int *newAry = new int[arySize];
    bool swapped = false;
    
    for (int i = 0; i < arySize; i++) {
        newAry[i] = ary[i];
    }
    
    do {
        swapped = false;
        
        for (int i = 1; i < arySize; i++) {
            if (newAry[i - 1] > newAry[i]) {
                swap(newAry[i - 1], newAry[i]);
                swapped = true;
            }
        }
    } while(swapped);
    
    return newAry;
}

//Sort in reverse order
int *reverse(const int *ary, int arySize) {
    int *newAry = new int[arySize];
    
    for (int i = 0; i < arySize; i++) {
        newAry[i] = ary[arySize - 1 - i];
    }
    
    return newAry;
}







