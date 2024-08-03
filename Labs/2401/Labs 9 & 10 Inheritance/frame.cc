// Worked on by Parker Riggs //
#include "frame.h"

using namespace std;

// Setters //
void Frame::set_price(double newPrice){
    price = newPrice;
}

void Frame::set_material(string newMaterial){
    material = newMaterial;
}

void Frame::set_isUsed(bool newIsUsed){
    isUsed = newIsUsed;
}

// Getters //
double Frame::get_price(){
    return price;
}

string Frame::get_material(){
    return material;
}

bool Frame::get_isUsed(){
    return isUsed;
}

void Frame::output(ostream& outs) const{
    if(&outs == &cout){
        outs << "Frame Material: " << material << endl;
        outs << "Frame Type: " << type << endl;
        outs << "Frame Price: " << Frame::price << endl;
    }else{
        outs << material << endl;
        outs << type << endl;
        outs << Frame::price << endl;
    }
}

void Frame::input(istream& ins){
    if(&ins == &cin){
        cout << "Inert Frame Material: ";
        getline(ins >> ws, material);
        cout << "Insert Frame Type: ";
        getline(ins >> ws, type);
        cout << "Insert Frame Price: $"
        ins >> Frame::price;
    }else{
        getline(ins >> ws, material);
        getline(ins >> ws, type)
        ins >> Frame::price;
    }
}