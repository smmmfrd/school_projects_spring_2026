/* 
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 12, 2026
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

//Search for 1 occurrence
int srch1(const char input[], const char pattern[], int index) {
    bool matches = true;
    int iPattrn = strlen(pattern);
    
    for (int j = index; j < index + iPattrn; j++) {
        if (input[j] != pattern[j - index]) {
            matches = false;
        }
    }
    
    if (matches) {
        return index;
    } else {
        return -1;
    }
}

//Search for all occurrences
void srchAll(const char input[],const char pattern[],int matches[]) {
    int iLength = strlen(input);
    
    // Count of matches
    int mCount = 0;
    // Variable to store the return value of srch1
    int rValue = -1;
    
    for (int i = 0; i < iLength - strlen(pattern); i++) {
        rValue = srch1(input, pattern, i);
        if (rValue > 0) {
            matches[mCount] = rValue;
            mCount++;
        }
    }
    
    // Add a sentinel value at the end of the matches (mCount is always the next index)
    matches[mCount] = -1;
}

//Print the character arrays
void print(const char string[]) {
    cout << string << endl;
}

//Print the array of indexes where the pattern found
void print(const int matches[]) {
    if (matches[0] < 0) {
        cout << "None" << endl;
        return;
    }
    
    int index = 0;
    
    while (matches[index] > 0) {
        cout << matches[index] << endl;
        index++;
    }
}






