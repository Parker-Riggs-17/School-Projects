#ifndef ORDER_H
#define ORDER_H

#include <list>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

#include "Product.h"

class Order{
    public:
        // Constructor
        Order(std::string uN = "N/A", double tC = 0.0){
            uN = userName;
            tC = totalCost;
        }

        // Getters
        void get_userName();
        void get_totalCost();

        // Setters
        void set_userName(std::string newUserName);
        void set_TotalCost(double newTotalCost);

        // Other functions
        void addItem(std::list<Product*> item);
        void output(std::ostream& outs)const;

    private:
        std::string userName;
        double totalCost;
        std::list<Product*> items;
};

#endif