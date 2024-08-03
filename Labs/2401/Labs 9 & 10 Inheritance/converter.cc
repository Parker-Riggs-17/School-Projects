#include "converter.h"

void Converter::set_price(double new_price){
    price = new_price;
}
void Converter::set_amt(int new_amt){
    amt = new_amt;
}

void Converter::set_material(std::string& new_material){
    material = new_material;
}

void Converter::set_used(bool is_new){
    is_used = is_new;
}