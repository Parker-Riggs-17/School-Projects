//Written By Andrew Gill
#include <cstdlib>
#include <string>
#include <iostream>
#include "Product.h"
class turboCharger:public Product
{
public:
    //setters
    turboCharger(double p = 456.75, std::string bearing = "Journery", int blade = 30){price = p; bearingType = bearing; bladeSize = blade;};
    void set_bearing(std::string& bearing);
    void set_bladeSize(int size);
    void set_price(double item_price);  
    void set_amt(int item_amt);
    //getters
    std::string get_bearing();
    int get_size();
    double get_price();
    int get_amt();
    //Input Output functions
    void input(std::istream& ins);
    void output(std::ostream& outs);


private:
// double price = 0; //This is a placeholder for now. I'm thinking of having a base pr
// int amt; //stock amount
std::string bearingType; // Ball, or Journey
int bladeSize; //in millimeters

};