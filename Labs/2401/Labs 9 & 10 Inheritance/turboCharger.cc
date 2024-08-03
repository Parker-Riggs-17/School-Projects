//Implemation for turboChargers Class
#include "turboCharger.h"
#include "Product.h"
using namespace std;

//Setters
void turboCharger::set_bearing(string &bearing)
{
    bearingType = bearing;
}

void turboCharger::set_bladeSize(int size)
{
    bladeSize = size;
}

void turboCharger::set_price(double item_price)
{
    price = item_price;
}

void turboCharger::set_amt(int item_amt)
{
    amt = item_amt;
}

//Getters
int turboCharger::get_size()
{
    return bladeSize;
}

string turboCharger::get_bearing()
{
    return bearingType;
}

double turboCharger::get_price()
{
    return price;
}

int turboCharger::get_amt()
{
    return amt;
}

//Input Output shows

void turboCharger::input(std::istream& ins)
{
    int userChoice;
    while(userChoice != 1 || userChoice != 2)
    {
    cout << "Please pick a bearing type for your Turbo! \n 1. Ball\n 2. Journey\n";
    ins >> userChoice;
        if(userChoice == 1)
        {
            bearingType = "Ball";
        }
        else if(userChoice == 2)
        {
            bearingType = "Journey";
        }
        else
        {
            cout << "Error: Please pick a valid Bearing Option" << endl;
        }
    }
    int userBlade;
    while((!(userBlade < 30)) && (!(userBlade > 80)))
    {
    cout << "Now please enter the size of your turbo blade in millimeters (From 30-80mm)" << endl;
    ins >> userBlade;
    if(userBlade < 30 || userBlade > 80)
    {
        cout << "Error: Please choose a valid blade option" << endl;
    }
    }
    bladeSize = userBlade;
}

void turboCharger::output(std::ostream& outs)
{
 outs << "Bearing Type: " << bearingType << " Bearing" << endl;
 outs << "Turbo Blade size: " << bladeSize << " mm" << endl;
}

