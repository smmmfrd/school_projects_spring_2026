/* 
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 18, 2026
 * Purpose:  Calculate the sum of a 2D array.
 */

#include <iostream>

using namespace std;


int **getData(int &,int &); //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array

int main(){
	int numRows, numCols, sum = 0;
	cin >> numRows;
	cin >> numCols;
	
	int **intAry = getData(numRows, numCols);
	
	prntDat(intAry, numRows, numCols);
	
	for (int y = 0; y < numRows; y++) {
        for (int x = 0; x < numCols; x++) {
            sum += intAry[y][x];
        }
    }
    
    cout << sum;
	
	for (int y = 0; y < numRows; y++) {
        delete[] intAry[y];
    }
	delete []intAry;
	return 0;
}

// Return the array size and the array from the inputs
int **getData(int &numRows, int &numCols) {
    int input;
    int **newAry = new int*[numRows];
    
    for (int y = 0; y < numRows; y++) {
        newAry[y] = new int[numCols];
        for (int x = 0; x < numCols; x++) {
            cin >> input;
            newAry[y][x] = input;
        }
    }
    
    return newAry;
}

//Print the 2-D Array
void prntDat(const int* const *ary, int numRows, int numCols) {
    for (int y = 0; y < numRows; y++) {
        for (int x = 0; x < numCols; x++) {
            cout << ary[y][x];
            
            if (x < numCols - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
}






