/**
*
*    File: Wage Plan
*    Name: Parker Riggs
*    Date: 01 / 08 / 2023
*   Brief: This program takes the amount of sales and puts it into 2 different plans and calculates the best plan
*
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(){
    double sales;

    cout << "Enter the weekly sales amount > ";
    cin >> sales;

    double planOne = (5.5 * 40) + (sales * .1);
    double planTwo = (sales * .15);

    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Amount of sales    $" << sales << endl;
    cout << "Plan 1 pays        $" << planOne << endl;
    cout << "Plan 2 pays        $" << planTwo << endl;
    if(planOne > planTwo){
        cout << "Plan 1 is better\n\n";
    } else{
        cout << "Plan 2 is better\n\n";
    }

}