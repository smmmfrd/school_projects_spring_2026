/* 
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 20, 2026
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
    sort(array,rowIn,colIn,replace,with);
    cout<<"The Sorted Array"<<endl;
    print(array,rowIn,colIn);
    
    //Exit
    return 0;
}

//Outputs row and columns detected from input
int read(char array[][COLMAX], int &rowDet){
    // cout << "im reading here" << endl;
    
    int maxSize = 0, index = 0;
    string input;
    
    while (cin >> input) {
        // cout << input << endl;
        if (input.length() > maxSize) {
            maxSize = input.length();
        }
        
        strcpy(array[index], input.c_str());
        index++;
    }
    
    // cout << maxSize << endl;
    return maxSize;
}

void swap(char &a, char &b) {
    a = a^b;
    b = a^b;
    a = a^b;
}

//Sort by row using strcmp();
void sort(char array[][COLMAX], int rowIn, int colIn, const char replace[], const char with[]) {
    bool swapped = false;
    
    do {
        swapped = false;
        
        for (int i = 1; i < rowIn; i++) {
            if (strcmp(array[i - 1], array[i], replace, with) > 0) {
                swap(array[i - 1], array[i]);
                swapped = true;
            }
        }
    } while(swapped);
}


//Replace sort order
int strcmp(char a[],char b[],const char replace[],const char with[]) {
    int cLength = strlen(a);
    int rLength = strlen(replace);
    char aComp, bComp;
    
    // Have to add these sentinels value otherwise it will keep replacing.
    bool aRplcd = false, bRplcd = false;
    
    for (int i = 0; i < cLength; i++) {
        aComp = a[i];
        bComp = b[i];
        
        for (int j = 0; j < rLength; j++) { 
            if(aComp == replace[j] && !aRplcd) {
                aComp = with[j];
                aRplcd = true;
            }
            
            if(bComp == replace[j] && !bRplcd) {
                bComp = with[j];
                bRplcd = true;
            }
        }
        
        if (aComp > bComp) {
            return 1;
        } else if (aComp < bComp) {
            return -1;
        }
    }
    
    // Regular comparison
    // for (int i = 0; i < length; i++) {
    //     if (a[i] > b[i]) {
    //         return 1;
    //     } else if (a[i] < b[i]) {
    //         return -1;
    //     }
    // }
    
    
    return 0;
}

//Print the sorted 2-D array
void print(const char array[][COLMAX], int rowIn, int) {
    for (int i = 0; i < rowIn; i++) {
        cout << array[i] << endl;
    }
}



