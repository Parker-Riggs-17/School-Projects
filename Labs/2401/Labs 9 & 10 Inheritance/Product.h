//C-- Product Page, We Making stuff, Making Bread
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product //Car Parts
{
public:
// Constructor
    Product(double p = 0.0, int a = 0){p = price; a = amt;}

// Setter Functions
    virtual void set_price(double item_price);  
    virtual void set_amt(int item_amt);

// Getter Functions
    virtual double get_price();
    virtual int get_amt();

// Insert/Output functions
	virtual void input(std::istream& ins) = 0;
	virtual void output(std::ostream& outs)const = 0;

protected:
    double price; 
    int amt; //stock amount
};

#endif