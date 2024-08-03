/**
*
*   File: lab5
*   Name: Parker Riggs
*   Date: 02 / 15 / 23
*   Breif: This program uses a while loops to prompt and read high and low temperatures for each day from the user.
*
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    // Variables used in program
    int highTemp = -500;
    int lowTemp = 500;
    int temp;
    int day = 1;

    while(temp != -100){    // While loop that asks user to input daily temperatures.
    cout << "Enter temperature for day " << day << ": ";
    cin >> temp;

    if(lowTemp > temp && temp != -100){ // Calculates the lowest temperature other than the sentinel value.
        lowTemp = temp;
    }

    if(highTemp < temp){    // Calculates the highest temperature
        highTemp = temp;
    }

    ++day;
    }
    
    // Displays the highest and lowest temperature recorded.
    cout << "\nHighest temperature recorded was: " << highTemp << endl;
    cout << "Lowest temperature recroded was: " << lowTemp << endl;

}