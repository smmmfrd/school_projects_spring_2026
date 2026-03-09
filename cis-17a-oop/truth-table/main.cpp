/* 
 * File:   main.cpp
 * Author: Sam Mumford
 * Created on: March 7, 2026
 * Purpose:  To tell the Truth, adjusted to read from file.
 */

//System Libraries Here
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool x,y;
    ifstream fInput("input.txt");

    if (!fInput.is_open()) {
        cout<<"Error opening file"<<endl;
        return 0;
    }

    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    
    while (fInput >> x >> y) {
        cout<<(x?'T':'F')<<" "
            <<(y?'T':'F')<<"  "
            <<(!x?'T':'F')<<"  "
            <<(!y?'T':'F')<<"   "
            <<(x&&y?'T':'F')<<"    "
            <<(x||y?'T':'F')<<"   "
            <<(x^y?'T':'F')<<"    "
            <<(x^y^x?'T':'F')<<"     "
            <<(x^y^y?'T':'F')<<"       "
            <<(!(x&&y)?'T':'F')<<"      "
            <<(!x||!y?'T':'F')<<"        "
            <<(!(x||y)?'T':'F')<<"      "
            <<(!x&&!y?'T':'F')
            <<endl;
    }
    
    cout << endl;

    fInput.close();

    //Exit
    return 0;
}