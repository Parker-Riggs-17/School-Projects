/**
 *   @file: invoice.cc
 * @author: Parker Riggs
 *   @date: 01 / 31 / 23
 *  @brief: This program calculates the total price of 1 of 2 kinds of monitors. 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[]) {

    char monitorType;
    string monitorBrand;
    int monitorQuantity;
    string ohResident;
    const double SAMSUNG = 190;
    const double VIEWSONIC = 170;
    double price;

    cout << "Enter a Monitor type (s, v) followed by the quantity: ";

    cin >> monitorType;
    if(monitorType == 's'){
        monitorBrand = "Samsung";
    } else if (monitorType == 'v'){
        monitorBrand = "View Sonic";
    } 


    cin >> monitorQuantity;

    cout << "Do you live in Ohio? (yes/no): ";
    cin >> ohResident;
    if(ohResident == "yes"){
        ohResident = "Yes";
    } else if (ohResident == "no"){
        ohResident = "No";
    }

    if(monitorType == 's'){
        price = SAMSUNG;
    }else if (monitorType == 'v'){
        price = VIEWSONIC;
    }

    double totalPrice = price * monitorQuantity;
    double discount;

    if(monitorQuantity >= 3){
        discount = (totalPrice * 0.05);
    }else if (monitorQuantity < 3){
        discount = 0;
    }

    double subTotal = totalPrice - discount;
    double taxes = subTotal * 0.07;

    if(ohResident == "yes"){
        taxes = taxes;
    }else if (ohResident == "no"){
        taxes = 0;
    }

    double overallTotal = subTotal + taxes;
    
    cout << fixed << setprecision(2);    
    cout << "\nMonitors Invoice" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Monitor Brand: " << monitorBrand << endl;
    cout << "     Quantity: " << monitorQuantity << endl;
    cout << "        Price: $" << price << endl;
    cout << "Ohio Resident: " << ohResident << endl;
    cout << "  Total Price: $" << totalPrice << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "     Discount: $" << discount << endl;
    cout << "     Subtotal: $" << subTotal << endl;
    cout << "        Taxes: $" << taxes << endl;
    cout << "============================================================" << endl;
    cout << "        Total: $" << overallTotal << endl;
    cout << "============================================================" << endl;

    return 0;
} /// main