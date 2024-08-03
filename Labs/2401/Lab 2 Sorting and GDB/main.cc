#include "numlist.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std; 

int main(){
    string fileName;
    NumList obj;
    int num1;
    int num2;
    int num3;
    ofstream ofs; 

    cout << "Insert File Name: ";
    cin >> fileName;

    ifstream ifs;
    ifs.open(fileName.c_str());
    if(ifs.fail()){
        cout << "File failed to open.";
        exit(0);
    }
    obj.load_from_file(ifs);

    obj.i_sort();   // Sorts the Elements in the txt file 
    obj.see_all();  // Displays all elements of obj to the terminal

    cout << "\nEnter 3 Numbers: ";
    cin >> num1 >> num2 >> num3;
    obj.insert(num1);
    obj.insert(num2);
    obj.insert(num3);
    obj.i_sort();
    obj.see_all();

     
    ofs.open(fileName.c_str());  // Opens new file for sorted values
    obj.save_to_file(ofs);  // Loads values into file
    ofs.close();

    int dotIndex = fileName.find('.');
    fileName = fileName.insert(dotIndex, "sorted");
    ofs.open(fileName);
    obj.save_to_file(ofs);

    ofs.close();
    ifs.close();
}