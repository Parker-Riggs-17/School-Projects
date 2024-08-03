/**************************************************
*   Labs 9 and 10 inheritance
*   Converter child class
*   Ben Thornton
*   March 2024
****************************************************/

#include <cstdlib>
#include <string>
#include "Product.h"

//inheriting publicly
class Converter:public Product{
    public:
    //constructor
        Converter(){price = 9999.99; amt = 0; is_used = false; material = "aluminum";};
    //setters
        void set_price(double new_price);
        void set_amt(int new_amt);
        void set_material(std::string& new_material);
        void set_used(bool is_new);
    //getters    
        double get_price() const {return price;};
        int get_amt() const {return amt;};
        std::string get_material() const {return material;};
        bool get_used() const {return is_used;};
    private:
        bool is_used;
        std::string material;
};