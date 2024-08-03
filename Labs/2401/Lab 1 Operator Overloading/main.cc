#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// C-Tor
int main(int argc, char *argv[]){
    MyTime time1;
    MyTime time2;
    int scalar;

    cout << "Enter Time 1: ";
    cin >> time1;

    cout << "Enter Time 2: ";
    cin >> time2;

    cout << "Input a Scalar: ";
    cin >> scalar;
    cout << endl;

    cout << "Addition: " << time1 + time2 << endl;
    cout << "Subtraction: " << time1 - time2 << endl;
    cout << "Multiplication (Time 1 by Scalar): " << time1 * scalar << endl;
    cout << "Division (Time 1 by Scalar): " << time1 / scalar << endl;
    cout << "Time 1 = Time 2? (0 = F, 1 = T) " << (time1 == time2) << endl;
}