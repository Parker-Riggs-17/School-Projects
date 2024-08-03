//Implemtation File for Product Class
#include "Product.h"

using namespace std;

//Setters
void Product::set_price(double item_price)
{
    price = item_price;
}

void Product::set_amt(int item_amt)
{
    amt = item_amt;
}

//Getters
double Product::get_price()
{
    return price;
}

int Product::get_amt()
{
    return amt;
}