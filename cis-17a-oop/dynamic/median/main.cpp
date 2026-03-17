/* 
 * File:   main.cpp
 * Author: Sam Mumford
 * Created on: March 16, 2026
 * Purpose:  Calculate the median of a dynamic array of integers.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &); //Return the array size and the array
void prntDat(int *,int); //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median,
                            // and the integer array data
void prntMed(float *,int); //Print the median Array

int main(){
    // Get the array size
    int arySize;
    cin >> arySize;
    
    // Get the array
    int *intAry = getData(arySize);
    
    prntDat(intAry, arySize);
    
    float *medAry = median(intAry, arySize);
    
    prntMed(medAry, arySize);
    
    delete []intAry;
    delete []medAry;
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
    cout << endl;
}

//Fill the median Array with the Float array size, the median, and the integer array data
float *median(int *intAry, int arySize) {
    float median = 0;
    int index = (arySize / 2);
    
    float *medAry = new float[arySize + 2];
    medAry[0] = arySize + 2;
    
    if (arySize % 2 == 1) {
        // If odd length of list, then use the middle value.
        median = intAry[index];
    } else {
        // If it's even, take the two middle elements and average them
        // Have to subtract one from index bc arrays start at 0.
        index -= 1;
        median = (intAry[index] + intAry[index + 1]) / 2.0;
    }
    
    medAry[1] = median;
    
    for (int i = 0; i < arySize; i++) {
        medAry[i + 2] = intAry[i];
    }
    
    return medAry;
}

//Print the median Array
void prntMed(float *medAry, int arySize) {
    for (int i = 0; i < arySize + 2; i++) {
        if (i > 0) {
            cout << setprecision(2) << fixed;
        }
        
        cout << medAry[i];
        
        if (i != arySize + 1) {
            cout << " ";
        }
    }
}






