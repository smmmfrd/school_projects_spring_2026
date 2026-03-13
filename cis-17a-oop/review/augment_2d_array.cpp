/* 
 * File:   augment_2d_array.cpp
 * Author: Sam Mumford
 * Created: March 13, 2026
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    cout << "Input a table and output the Augment row,col and total sums." << endl;
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

//Prompt for size then table
void read(int array[][COLMAX], int &row, int &col) {
    cout << "First input the number of rows and cols. <20 for each" << endl;
    cin >> row >> col;
    
    cout << "Now input the table." << endl;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> array[i][j];
        }
    }
}

//Sum rows,col,grand total
void sum(const int array[][COLMAX], int row, int col, int augment[][COLMAX]) {
    int sum;
    
    for (int i = 0; i < row; i++) {
        sum = 0;
        for (int j = 0; j < col + 1; j++) {
            if (j == col) {
                augment[i][j] = sum;
                continue;
            }
            
            augment[i][j] = array[i][j];
            sum += array[i][j];
        }
    }
    
    // Sum up the columns
    for (int x = 0; x < col + 1; x++) {
        sum = 0;
        for (int y = 0; y < row; y++) {
            sum += augment[y][x];
        }
        augment[row][x] = sum;
    }
}

//Either table can be printed
void print(const int array[][COLMAX], int row, int col, int width) {
    // cout << "im printing here" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(width) << array[i][j];
        }
        cout << endl;
    }
}








