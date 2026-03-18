/* 
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 18, 2026
 * Purpose:  Calculate the sum of an array.
 */

#include <iostream>

using namespace std;


int *getData(int &); // Return the array size and the array from the inputs
int *sumAry(const int *,int); // Return the array with successive sums
void prntAry(const int *,int); // Print the array

int main(){
	int arySize;
	cin >> arySize;
	
	int *intAry = getData(arySize);
	int *smdAry = sumAry(intAry, arySize);
	
	prntAry(intAry, arySize);
	cout << endl;
	prntAry(smdAry, arySize);
	
	delete []intAry;
	delete []smdAry;
	return 0;
}

// Return the array size and the array from the inputs
int *getData(int &arySize){
    int input, index = 0;
    int *newAry = new int[arySize];
    
    while (cin >> input) {
        newAry[index] = input;
        index++;
    }
    
    return newAry;
}

// Return the array with successive sums
int *sumAry(const int *ary, int arySize) {
    int *newAry = new int[arySize];
    
    for (int i = 0; i < arySize; i++) {
        newAry[i] = 0;
        for (int j = i; j >= 0; j--) {
            newAry[i] += ary[j];
        }
    }
    
    return newAry;
}

// Print the array
void prntAry(const int *ary, int arySize) {
    for(int i = 0; i < arySize; i++) {
        cout << ary[i];
        
        if (i != arySize - 1) {
            cout << " ";
        }
    }
}






