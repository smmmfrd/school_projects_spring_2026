/* 
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 8, 2026
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char array[]) {
    string input;
    cin >> input;
    strcpy(array, input.c_str());
    // cout << array << endl;
    
    return input.size();
}

void swap(char &a, char &b) {
    a = a^b;
    b = a^b;
    a = a^b;
}

void sort(char array[], int length) {
    int i;
    bool swapped = false;
    
    do {
        swapped = false;
        
        for (i = 1; i < length; i++) {
            if (array[i - 1] > array[i]) {
                swap(array[i - 1], array[i]);
                swapped = true;
            }
        }
    } while(swapped);
}

void print(const char array[],int) {
    cout << array << endl;
}



