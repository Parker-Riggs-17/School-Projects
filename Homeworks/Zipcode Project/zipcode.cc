/**
 *   @file: zipcode.cc
 * @author: Parker Riggs
 *   @date: 02 / 24 / 23
 *  @brief: This program takes a zipcode given by the user and turns it into a barcode.
 */

// Issue with returning the Check digit, it returns into the main function but I was unable to figure out how to transform it from an int value to a char value
// so the check digit value is not a barcode rather it is just a number.

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Function Prototypes
string getDigitCode(char digit);
int getCheckDigitValue(int sum);

//Constants

int main(int argc, char const *argv[]) {

    // Variables
    string zip;
    char response = 'y';

    while(response == 'y'){ //Loops the user unless he specifies no
        
        cout << "Enter a zip code: ";
        cin >> zip;
        char ch = zip.at(0);
        char ch1 = zip.at(1);
        char ch2 = zip.at(2);
        char ch3 = zip.at(3);
        char ch4 = zip.at(4);
        int sum = ch + ch1 + ch2 + ch3 + ch4;

        // Checks if the string inputted by the user is valid.

        while(zip.length() != 5){
            cout << "Zip code must be 5 digits. \n";
            cout << "Enter a zip code: ";
            cin >> zip;
        }

        while(ch < '0' || ch > '9'){
            cout << "Zip code must only consist of numbers." << endl;
            cout << "Enter a zip code: ";
            cin >> zip;
        }

        while(ch1 < '0' || ch1 > '9'){
            cout << "Zip code must only consist of numbers." << endl;
            cout << "Enter a zip code: ";
            cin >> zip;
        }

        while(ch2 < '0' || ch2 > '9'){
            cout << "Zip code must only consist of numbers." << endl;
            cout << "Enter a zip code: ";
            cin >> zip;
        }

        while(ch3 < '0' || ch3 > '9'){
            cout << "Zip code must only consist of numbers." << endl;
            cout << "Enter a zip code: ";
            cin >> zip;
        }

        while(ch4 < '0' || ch4 > '9'){
            cout << "Zip code must only consist of numbers." << endl;
            cout << "Enter a zip code: ";
            cin >> zip;
        }

        cout << "Code: " << getDigitCode(ch) << getDigitCode(ch1) << getDigitCode(ch2) << getDigitCode(ch3) << getDigitCode(ch4) << getCheckDigitValue(sum) << endl;

        cout << "More codes (y/n)? ";
        cin >> response;
    }
    return 0;
}

string getDigitCode(char digit){    // Returns a Barcode for a single digit
    string bc1 = ":::|| ";
    string bc2 = "::|:| ";
    string bc3 = "::||: ";
    string bc4 = ":|::| ";
    string bc5 = ":|:|: ";
    string bc6 = ":||:: ";
    string bc7 = "|:::| ";
    string bc8 = "|::|: ";
    string bc9 = "|:|:: ";
    string bc0 = "||::: ";

    if(digit == '0'){
        return bc0;
    }

    if(digit == '1'){
        return bc1;
    }

    if(digit == '2'){
        return bc2;
    }
    
    if(digit == '3'){
        return bc3;
    }

    if(digit == '4'){
        return bc4;
    }

    if(digit == '5'){
        return bc5;
    }

    if(digit == '6'){
        return bc6;
    }

    if(digit == '7'){
        return bc7;
    }

    if(digit == '8'){
        return bc8;
    }

    if(digit == '9'){
        return bc9;
    }
    return 0;
}    

int getCheckDigitValue(int sum){    // Returns the check digit

    int remainder = sum % 10;
    int cdv = 0;
    if(remainder != 0){
        cdv = 10 - remainder;
    }
    return cdv;
}    