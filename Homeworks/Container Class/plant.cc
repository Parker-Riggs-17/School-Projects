/*************************************************************************
    This is the implementation file for the Plant class. For more 
		information about the class see plant.h.
    Students are expected to implement the input and output functions
		below.

	Patricia Lindner	Ohio University EECS	January 2023
*************************************************************************/
#include "plant.h"
using namespace std;

Plant::Plant(string n, string c, Date i, int s){
	name = n;
	color = c;
	cameIn = i;
	stock = s;
}

// Input and output functions
void Plant::input(std::istream& ins){
	/* You are to write the implementation of this function to read 
	from the keyboard or a file. Remember to use getline to read the 
	name and color.  */

	if(&ins == &cin){
		cout << "Plant Name: ";
		getline(ins >> ws, name);
		cout << "Plant Color: ";
		getline(ins >> ws, color);
		cout << "Date it came in: ";
		ins >> cameIn;
		cout << "Current Stock: ";
		ins >> stock;
	} else{
		getline(ins >> ws, name);
		getline(ins >> ws, color);
		ins >> cameIn;
		ins >> stock;
	}

}

void Plant::output(std::ostream& outs)const{
	if(&outs == &cout){
		outs << "Plant Name: " << name << endl;
		outs << "Plant Color: " << color << endl;
		outs << "Arrival Date: " << cameIn << endl;
		outs << "Current Stock: " << stock << endl;
	} else{
		outs << name << endl;
		outs << color << endl;
		outs << cameIn << endl;
		outs << stock << endl;
	}
}

ostream& operator << (ostream& outs, const Plant& p){
	p.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Plant& p){
	p.input(ins);
	return ins;
}