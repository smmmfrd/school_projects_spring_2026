/* 
 * File:   main.cpp
 * Author: Sam Mumford
 * Created: March 20, 2026
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}


//Output true,unsigned or false
bool inRange(const char input[], unsigned short &output) {
    output = 0;
    int length = strlen(input);
    
    for (int i = 0; i < length; i++) {
        if ((input[i] - '0') > 9 || (input[i] - '0') < 0) {
            // cout << "whoopsie at " << i << ", value: " << input[i] << endl;
            return false;
        }
        
        output += (input[i] - '0');
        
        if (i < length - 1) {
            if (output * 10 > 65535) {
                return false;
            }
            
            output *= 10;
        }
    }
    
    // cout << "Inputted number was clean, value: " << output << endl;
    return true;
}

//Output true,short or false
bool reverse(unsigned short input, signed short &output){
    string temp = "", iString = to_string(input);
    int length = iString.length();
    
    for (int i = 5; i > 0; i--) {
        if (i > length) {
            // cout << '0';
            temp = '0' + temp;
        } else {
            // cout << iString[i - 1];
            temp = iString[i - 1] + temp;
        }
    }
    
    for (int i = 4; i >= 0; i--) {
        output += (temp[4 - i] - '0');
        
        if (i > 0) {
            if (output * 10 > 65535) {
                return false;
            }
            // Move it over by one 10s place every character.
            output *= 10;
        }
    }
    
    return true;
}


short subtrct(signed short input, int amount) {
    return input - amount;
}













